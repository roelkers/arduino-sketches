// ---------------------------------------------------------------------------
//
// basic.ino
//
// A MIDI sequencer example using a standard MIDI cable and a push button
// attached to pin 4.
//
// Author: Todd Treece <todd@uniontownlabs.org>
// Copyright: (c) 2015 Adafruit Industries
// License: GNU GPLv3
//
// ---------------------------------------------------------------------------
#include "FifteenStep.h"

#include <Bounce.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     voice1env;            //xy=204,183
AudioSynthWaveform       waveform1;      //xy=209,83
AudioEffectMultiply      multiply1;      //xy=458,135
AudioMixer4              mixer1;         //xy=760,136
AudioOutputI2S           i2s1;           //xy=972,141
AudioConnection          patchCord1(voice1env, 0, multiply1, 1);
AudioConnection          patchCord2(waveform1, 0, multiply1, 0);
AudioConnection          patchCord3(multiply1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=558,228
// GUItool: end automatically generated code


void midi(byte channel, byte command, byte arg1, byte arg2);
void step(int current, int last);

// sequencer init
FifteenStep seq = FifteenStep();

// save button state
int button_last[] = {0,0,0};

//ADSR
int attackTime;
int decayTime;
float sustainLevel;
int releaseTime;

int attackWait;

float notes[] = {
  261.6255653006,
  277.1826309769,
  293.6647679174,
  311.1269837221,
  329.6275569129,
  349.2282314330,
  369.9944227116,
  391.9954359817,
  415.3046975799,
  440.0000000000,
  466.1637615181,
  493.8833012561};

Bounce bounce[] = {
  Bounce(2,15),
  Bounce(3,15),
  Bounce(4,15)
};

int BTNNR = 3;

int button[] = {0,0,0};

bool isRecording = false;
bool noteTrigFlag = false;

void setup() {

  Serial.begin(9600);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);
  
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  
  mixer1.gain(0,1);
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.75);
  waveform1.frequency(50);

  voice1env.amplitude(0);

  attackTime = 50;
  decayTime = 1000;
  sustainLevel = 1;
  releaseTime = 1000;
  
  // start sequencer and set callbacks
  seq.begin();
  seq.setMidiHandler(midi);
  seq.setStepHandler(step);

}

void loop() {

 if(millis() > 2000){
  isRecording = true;
 }
  
//  
//  // read the state of the button
 button[0] = digitalRead(2);
 button[1] = digitalRead(3);
 button[2] = digitalRead(4);
 
// use the knobs to adjust parameters
  //float knob1 = (float)analogRead(A1) / 1023.0;
  float knob2 = (float)analogRead(A2) / 1023.0;
  float knob3 = (float)analogRead(A3) / 1023.0;
  float knob4 = (float)analogRead(A4) / 1023.0;

  for(int i = 0; i< BTNNR; i++){ 
    if (bounce[i].fallingEdge()){
      Serial.println("Button Press Pin:");
      Serial.println(i);
    }
    if (bounce[i].risingEdge()){
      Serial.println("Button Release Pin:");
      Serial.println(i);
    }
    //Serial.println("button: " + button[i]);
    if(bounce[i].update()){
      byte midiNote;

        if(i == 0) midiNote = 0x3C; //middle C
        if(i == 1) midiNote = 0x40;
        if(i == 2) midiNote = 0x43;

      // check for button press or release and
      // send note on or off to seqencer if needed
      if(button[i] == HIGH && button_last[i] == LOW) {

        Serial.println("midiNote :" + midiNote);

        // button pressed. play preview now
        midi(0x0, 0x9, midiNote, 0x40);
        
        if(isRecording){
          //seq.setNote(0x0, midiNote, 0x40);
        }
      } else if(button[i] == LOW && button_last[i] == HIGH) {

        Serial.println("midiNoteOff :" + midiNote);
           
        // button released. send off preview now
        midi(0x0, 0x8, midiNote, 0x0);
       
        if(isRecording){
          //seq.setNote(0x0, midiNote, 0x0);
        }
      }
      if(button[i] == LOW){
       if(millis() - attackWait > attackTime && noteTrigFlag){
         voice1env.amplitude(sustainLevel,decayTime);
      }
    }
      
    }
    
      
    // save button state
    button_last[i] = button[i];
  }

  // this is needed to keep the sequencer
  // running. there are other methods for
  // start, stop, and pausing the steps
  seq.run();

}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//                         SEQUENCER CALLBACKS                               //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////

// called when the step position changes. both the current
// position and last are passed to the callback
void step(int current, int last) {

//  // blink on even steps
//  if(current % 2 == 0)
//    digitalWrite(13, HIGH);
//  else
//    digitalWrite(13, LOW);

}

// the callback that will be called by the sequencer when it needs
// to send midi commands. this specific callback is designed to be
// used with a standard midi cable.
//
// the following image will show you how your MIDI cable should
// be wired to the Arduino:
// http://arduino.cc/en/uploads/Tutorial/MIDI_bb.png
void midi(byte channel, byte command, byte arg1, byte arg2) {

//  if(command < 128) {
//    // shift over command
//    command <<= 4;
//    // add channel to the command
//    command |= channel;
//  }

  if(command == 0x8){
    //note off command
    voice1env.amplitude(0,releaseTime);
    noteTrigFlag = false;
  }
  else if(command == 0x9){
    //note on command
    voice1env.amplitude(1,attackTime);
    attackWait = millis();

    noteTrigFlag = true;
    
    int index = arg1 - 60;
    float notefreq =  notes[index];
  
    Serial.println("notefreq :");
    Serial.println(notefreq);
    
    waveform1.frequency(notefreq);
  }

}

