/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class Vst_testAudioProcessorEditor  : public AudioProcessorEditor,
public Slider::Listener
{
public:
    Vst_testAudioProcessorEditor (Vst_testAudioProcessor&);
    ~Vst_testAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (Slider* slider);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Vst_testAudioProcessor& processor;
    Slider dial11;
    Label dial11label;
    Slider dial12;
    Label dial12label;
    Slider dial13;
    Label dial13label;
    Slider dial14;
    Label dial14label;
    Slider dial21;
    Label dial21label;
    Slider dial22;
    Label dial22label;
    Slider dial23;
    Label dial23label;
    Slider dial24;
    Label dial24label;
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Vst_testAudioProcessorEditor)
};
