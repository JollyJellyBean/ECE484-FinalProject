/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include <vector>

//==============================================================================
/**
*/
class Vst_testAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Vst_testAudioProcessor();
    ~Vst_testAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void allPassFilter(AudioBuffer<float> ArrayIn,AudioBuffer<float> &ArrayOut,int Delay, float feedbackCoefficient,int arrayInSize, int channel);
    
    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

	void combFilter(AudioBuffer<float> ArrayIn, AudioBuffer<float> &ArrayOut, int Delay, float feedbackCoefficient, int arrayInSize, int channel);

	void addCombFilterOutputs(AudioBuffer<float> combOutput1, AudioBuffer<float> combOutput2, AudioBuffer<float> combOutput3, AudioBuffer<float> combOutput4, AudioBuffer<float> &output, int arrayInSize, int channel);

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    //Listener Values
    int combFilterDelay1, combFilterDelay2, combFilterDelay3, combFilterDelay4;
    float combFeedbackCoefficient1, combFeedbackCoefficient2, combFeedbackCoefficient3, combFeedbackCoefficient4;
    
    
    
private:
    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Vst_testAudioProcessor)
};
