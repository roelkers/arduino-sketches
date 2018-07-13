// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 2-8: Oscillators

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
AudioSynthWaveform       waveform1;      //xy=296,235
AudioFilterStateVariable filter1;        //xy=494,235
AudioMixer4              mixer1;         //xy=673,245
AudioOutputI2S           i2s1;           //xy=1017,254
AudioConnection          patchCord1(waveform1, 0, filter1, 0);
AudioConnection          patchCord2(filter1, 0, mixer1, 0);
AudioConnection          patchCord3(mixer1, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=671,353
// GUItool: end automatically generated code


void setup() {
  Serial.begin(9600);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);
  
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);

  mixer1.gain(0, 1);
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.75);
  waveform1.frequency(440);
}

int waveform_type = WAVEFORM_SAWTOOTH;
int mixer1_setting = 0;
elapsedMillis timeout = 0;
//bool mixer1_envelope = false;

int count=1;
int a1history=0, a2history=0, a3history=0;

void loop() {

  // use the knobs to adjust parameters
  //float knob1 = (float)analogRead(A1) / 1023.0;
  float knob2 = (float)analogRead(A22) / 1023.0;
  float knob3 = (float)analogRead(A21) / 1023.0;

  float resonance = 0.7 + knob3 * 4;
  filter1.resonance(resonance);
  // quick and dirty equation for exp scale frequency adjust
  //float filterfreq =  expf((float)knob4 / 150.0) * 10.0 + 80.0;
  float filterfreq = knob2 * 20000;
  filter1.frequency(filterfreq);

  int a4 = analogRead(A4);
  int a2 = analogRead(A2);
  int a3 = analogRead(A3);
  
  if (a2 > a2history + 50 || a2 < a2history - 50) {
    Serial.print("Knob (pin A2) = ");
    Serial.println(a2);
    a2history = a2;
    Serial.println("filter frequency: ");
    Serial.println(filterfreq);
  }
  if (a3 > a3history + 50 || a3 < a3history - 50) {
    Serial.print("Knob (pin A3) = ");
    Serial.println(a3);
    a3history = a3;
    Serial.println("resonance: ");
    Serial.println(resonance);
  }
}



