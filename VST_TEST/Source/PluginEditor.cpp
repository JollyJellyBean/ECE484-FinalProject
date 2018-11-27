/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Vst_testAudioProcessorEditor::Vst_testAudioProcessorEditor (Vst_testAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    //'sample Delay'
    addAndMakeVisible(dial11);
    dial11.setSliderStyle(Slider::SliderStyle::Rotary);
    dial11.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial11.setTextValueSuffix(" Coefficient");
    dial11.setRange(0,0.99,0.01);
    dial11.setValue(0.99);
    dial11.addListener(this);
    
    addAndMakeVisible(dial12);
    dial12.setSliderStyle(Slider::SliderStyle::Rotary);
    dial12.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial12.setTextValueSuffix(" Coefficient");
    dial12.setRange(0,0.99,0.01);
    dial12.setValue(0.75);
    dial12.addListener(this);

    addAndMakeVisible(dial13);
    dial13.setSliderStyle(Slider::SliderStyle::Rotary);
    dial13.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial13.setTextValueSuffix(" Coefficient");
    dial13.setRange(0,0.99,0.01);
    dial13.setValue(0.5);
    dial13.addListener(this);

    addAndMakeVisible(dial14);
    dial14.setSliderStyle(Slider::SliderStyle::Rotary);
    dial14.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial14.setTextValueSuffix(" Coefficient");
    dial14.setRange(0,0.99,0.01);
    dial14.setValue(0.25);
    dial14.addListener(this);

    //'G' feedback coefficient
    addAndMakeVisible(dial21);
    dial21.setSliderStyle(Slider::SliderStyle::Rotary);
    dial21.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial21.setTextValueSuffix(" Samples");
    dial21.setRange(0,100,1);
    dial21.setValue(100);
    dial21.addListener(this);

    addAndMakeVisible(dial22);
    dial22.setSliderStyle(Slider::SliderStyle::Rotary);
    dial22.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial22.setTextValueSuffix(" Samples");
    dial22.setRange(0,100,1);
    dial22.setValue(75);
    dial22.addListener(this);

    addAndMakeVisible(dial23);
    dial23.setSliderStyle(Slider::SliderStyle::Rotary);
    dial23.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial23.setTextValueSuffix(" Samples");
    dial23.setRange(0,100,1);
    dial23.setValue(50);
    dial23.addListener(this);

    addAndMakeVisible(dial24);
    dial24.setSliderStyle(Slider::SliderStyle::Rotary);
    dial24.setTextBoxStyle(Slider::TextBoxBelow, false, 100, 20);
    dial24.setTextValueSuffix(" Samples");
    dial24.setRange(0,100,1);
    dial24.setValue(25);
    dial24.addListener(this);

    addAndMakeVisible(dial11label);
    dial11label.setText ("FC1", dontSendNotification);
    addAndMakeVisible(dial12label);
    dial12label.setText ("FC2", dontSendNotification);
    addAndMakeVisible(dial13label);
    dial13label.setText ("FC3", dontSendNotification);
    addAndMakeVisible(dial14label);
    dial14label.setText ("FC4", dontSendNotification);
    addAndMakeVisible(dial21label);
    dial21label.setText ("SD1", dontSendNotification);
    addAndMakeVisible(dial22label);
    dial22label.setText ("SD2", dontSendNotification);
    addAndMakeVisible(dial23label);
    dial23label.setText ("SD3", dontSendNotification);
    addAndMakeVisible(dial24label);
    dial24label.setText ("SD4", dontSendNotification);

    setSize (300, 680);
}

Vst_testAudioProcessorEditor::~Vst_testAudioProcessorEditor()
{
}

//==============================================================================
void Vst_testAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::black);

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("", getLocalBounds(), Justification::centred, 1);
}

void Vst_testAudioProcessorEditor::resized()
{
    dial11.setBounds(0,20, 150, 150);
    dial12.setBounds(0, 190, 150, 150);
    dial13.setBounds(0, 360, 150, 150);
    dial14.setBounds(0, 530, 150, 150);
    dial21.setBounds(150,20, 150, 150);
    dial22.setBounds(150, 190, 150, 150);
    dial23.setBounds(150, 360, 150, 150);
    dial24.setBounds(150, 530, 150, 150);
    dial11label.setBounds(0, 0, 150, 20);
    dial12label.setBounds(0, 170, 150, 20);
    dial13label.setBounds(0, 340, 150, 20);
    dial14label.setBounds(0, 510, 150, 20);
    dial21label.setBounds(150, 0, 150, 20);
    dial22label.setBounds(150, 170, 150, 20);
    dial23label.setBounds(150, 340, 150, 20);
    dial24label.setBounds(150, 510, 150, 20);
}

void Vst_testAudioProcessorEditor::sliderValueChanged (Slider* slider){
    
    if(slider == &dial11){
        processor.combFeedbackCoefficient1=slider->getValue();
    }
    
    if(slider == &dial12){
        processor.combFeedbackCoefficient2=slider->getValue();
    }
    
    if(slider == &dial13){
        processor.combFeedbackCoefficient3=slider->getValue();
    }
    
    if(slider == &dial14){
        processor.combFeedbackCoefficient4=slider->getValue();
    }
    if(slider == &dial21){
        processor.combFilterDelay1=slider->getValue();
    }
    
    if(slider == &dial22){
        processor.combFilterDelay2=slider->getValue();
    }
    
    if(slider == &dial23){
        processor.combFilterDelay3=slider->getValue();
    }
    
    if(slider == &dial24){
        processor.combFilterDelay4=slider->getValue();
    }

}

