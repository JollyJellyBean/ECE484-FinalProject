/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Vst_testAudioProcessor::Vst_testAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

Vst_testAudioProcessor::~Vst_testAudioProcessor()
{
}

//==============================================================================
const String Vst_testAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Vst_testAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Vst_testAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Vst_testAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Vst_testAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Vst_testAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Vst_testAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Vst_testAudioProcessor::setCurrentProgram (int index)
{
}

const String Vst_testAudioProcessor::getProgramName (int index)
{
    return {};
}

void Vst_testAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Vst_testAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void Vst_testAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Vst_testAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif


void Vst_testAudioProcessor::allPassFilter(AudioBuffer<float> ArrayIn,AudioBuffer<float> &ArrayOut,int Delay, float feedbackCoefficient,int arrayInSize, int channel){
    
    for(int sample=0;sample<arrayInSize;sample++){
        
        ArrayOut.setSample(channel,sample,-feedbackCoefficient*ArrayIn.getSample(channel, sample));
        
        if((sample-Delay)>=0){
            ArrayOut.setSample(channel,sample, ArrayOut.getSample(channel,sample) + ArrayIn.getSample(channel, sample-Delay));
            ArrayOut.setSample(channel,sample, ArrayOut.getSample(channel,sample) + feedbackCoefficient*ArrayOut.getSample(channel,sample-Delay));
        }
        ArrayOut.setSample(channel,sample,ArrayOut.getSample(channel,sample));
        
    }
}

//====================== Comb Filter ===========================================
void Vst_testAudioProcessor::combFilter(AudioBuffer<float> ArrayIn, AudioBuffer<float> &ArrayOut, int Delay, float feedbackCoefficient, int arrayInSize, int channel)
{
	for (int sample = 0; sample < arrayInSize; sample++) {

		if ((sample - Delay) >= 0) {
			ArrayOut.setSample(channel, sample, ArrayOut.getSample(channel, sample) + ArrayIn.getSample(channel, sample - Delay));
			ArrayOut.setSample(channel, sample, ArrayOut.getSample(channel, sample) + feedbackCoefficient * ArrayOut.getSample(channel, sample - Delay));
		}
		ArrayOut.setSample(channel, sample, ArrayOut.getSample(channel, sample));

	}
}

//====================== Add Comb Filter Outputs ===============================
void Vst_testAudioProcessor::addCombFilterOutputs(AudioBuffer<float> combOutput1, AudioBuffer<float> combOutput2, AudioBuffer<float> &output, int arrayInSize, int channel)
{
	for (int sample = 0; sample < arrayInSize; sample++) {
		output.setSample(channel, sample, combOutput1.getSample(channel, sample) + combOutput2.getSample(channel, sample));
	}
}


void Vst_testAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    AudioBuffer<float> OutputMASTER;
	AudioBuffer<float> OutputMASTER2;
	AudioBuffer<float> Output1;
	AudioBuffer<float> Output2;
	AudioBuffer<float> Output3;
	AudioBuffer<float> Output4;

	OutputMASTER.setSize(buffer.getNumChannels(), buffer.getNumSamples());
	OutputMASTER2.setSize(buffer.getNumChannels(), buffer.getNumSamples());
	Output1.setSize(buffer.getNumChannels(), buffer.getNumSamples());
	Output2.setSize(buffer.getNumChannels(), buffer.getNumSamples());
	Output3.setSize(buffer.getNumChannels(), buffer.getNumSamples());
	Output4.setSize(buffer.getNumChannels(), buffer.getNumSamples());

    
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        
		//combFilter(buffer, OutputMASTER, combFilterDelay1, combFeedbackCoefficient1, buffer.getNumSamples(), channel);
		//combFilter(buffer, Output2, combFilterDelay2, combFeedbackCoefficient2, buffer.getNumSamples(), channel);
		//combFilter(buffer, Output3, combFilterDelay3, combFeedbackCoefficient3, buffer.getNumSamples(), channel);
		//combFilter(buffer, Output4, combFilterDelay4, combFeedbackCoefficient4, buffer.getNumSamples(), channel);

		//addCombFilterOutputs(Output1, Output2, Output3, Output4, OutputMASTER, buffer.getNumSamples(), channel);

        //allPassFilter(OutputMASTER, OutputMASTER2, combFeedbackCoefficient1,combFilterDelay1,buffer.getNumSamples(),channel);
		allPassFilter(buffer, OutputMASTER, combFeedbackCoefficient1, combFilterDelay1, buffer.getNumSamples(), channel);

    auto* channelData = OutputMASTER.getWritePointer (channel);

    }
    
    buffer= OutputMASTER;
    
    
}

//==============================================================================
bool Vst_testAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Vst_testAudioProcessor::createEditor()
{
    return new Vst_testAudioProcessorEditor (*this);
}

//==============================================================================
void Vst_testAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Vst_testAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Vst_testAudioProcessor();
}
