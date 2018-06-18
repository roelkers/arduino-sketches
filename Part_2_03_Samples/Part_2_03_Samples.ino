// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 2-3: Playing Samples

// WAV files converted to code by wav2sketch
#include "AudioSampleSnare.h"        // http://www.freesound.org/people/KEVOY/sounds/82583/
#include "AudioSampleTomtom.h"       // http://www.freesound.org/people/zgump/sounds/86334/
#include "AudioSampleHihat.h"        // http://www.freesound.org/people/mhc/sounds/102790/
#include "AudioSampleKick.h"         // http://www.freesound.org/people/DWSD/sounds/171104/
#include "AudioSampleGong.h"         // http://www.freesound.org/people/juskiddink/sounds/86773/
#include "AudioSampleCashregister.h" // http://www.freesound.org/people/kiddpark/sounds/201159/
#include <Bounce.h>


///////////////////////////////////
// copy the Design Tool code here
///////////////////////////////////

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioPlayMemory          playMem4;       //xy=103,221
AudioPlayMemory          playMem1;       //xy=105,61
AudioPlayMemory          playMem3;       //xy=105,172
AudioPlayMemory          playMem2;       //xy=106,114
AudioMixer4              mixer1;         //xy=253,131
AudioOutputI2S           i2s2;           //xy=382,128
AudioConnection          patchCord1(playMem4, 0, mixer1, 3);
AudioConnection          patchCord2(playMem1, 0, mixer1, 0);
AudioConnection          patchCord3(playMem3, 0, mixer1, 2);
AudioConnection          patchCord4(playMem2, 0, mixer1, 1);
AudioConnection          patchCord5(mixer1, 0, i2s2, 0);
AudioConnection          patchCord6(mixer1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=248,397
// GUItool: end automatically generated code

// Bounce objects to read pushbuttons 
Bounce button0 = Bounce(0, 15);
Bounce button1 = Bounce(1, 15);  // 15 ms debounce time
Bounce button2 = Bounce(2, 15);


void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  AudioMemory(10);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  mixer1.gain(0, 0.4);
  mixer1.gain(1, 0.4);
  mixer1.gain(2, 0.4);
  mixer1.gain(3, 0.4);
}

void loop() {
  // Update all the button objects
  button0.update();
  button1.update();
  button2.update();
  /*
  if (button0.fallingEdge()) {
    playMem1.play(AudioSampleSnare);
  }
  if (button1.fallingEdge()) {
    playMem2.play(AudioSampleTomtom);
  }
  if (button2.fallingEdge()) {
    playMem3.play(AudioSampleHihat);
  }
  */

  int knob = analogRead(A3);
  if (button0.fallingEdge()) {
    if (knob < 512) {
      playMem1.play(AudioSampleSnare);
    } else {
      playMem1.play(AudioSampleKick);
    }
  }
  if (button1.fallingEdge()) {
    if (knob < 512) {
      playMem2.play(AudioSampleTomtom);
    } else {
      playMem4.play(AudioSampleGong);
    }
  }
  if (button2.fallingEdge()) {
    if (knob < 512) {
      playMem3.play(AudioSampleHihat);
    } else {
      playMem3.play(AudioSampleCashregister);
    }
  }


}

