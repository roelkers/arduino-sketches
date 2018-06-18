// Advanced Microcontroller-based Audio Workshop
//
// http://www.pjrc.com/store/audio_tutorial_kit.html
// https://hackaday.io/project/8292-microcontroller-audio-workshop-had-supercon-2015
// 
// Part 2-8: Oscillators

#include <Bounce.h>

Bounce button0 = Bounce(0, 15);
Bounce button1 = Bounce(1, 15);  // 15 = 15 ms debounce time
Bounce button2 = Bounce(2, 15);


///////////////////////////////////
// copy the Design Tool code here
///////////////////////////////////


#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=109,193
AudioSynthWaveformModulated waveformMod1;   //xy=224,97
AudioFilterStateVariable filter1;        //xy=400,97
AudioMixer4              mixer1;         //xy=547,161
AudioOutputI2S           i2s1;           //xy=713,164
AudioConnection          patchCord1(sine1, 0, waveformMod1, 0);
AudioConnection          patchCord2(waveformMod1, 0, filter1, 0);
AudioConnection          patchCord3(filter1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 0);
AudioConnection          patchCord5(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=365,225
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
  waveformMod1.begin(WAVEFORM_SAWTOOTH);
  waveformMod1.amplitude(0.75);
  waveformMod1.frequency(50);
//  waveformMod1.pulseWidth(0.15);
//  envelope1.attack(10);
//  envelope1.hold(10);
//  envelope1.decay(25);
//  envelope1.sustain(0.4);
//  envelope1.release(70);
}

int waveform_type = WAVEFORM_SAWTOOTH;
int mixer1_setting = 0;
elapsedMillis timeout = 0;
//bool mixer1_envelope = false;

int count=1;
int a1history=0, a2history=0, a3history=0;

void loop() {
  button0.update();
  button1.update();
  button2.update();

  // Left changes the type of control waveform
  if (button0.fallingEdge()) {
    Serial.print("Control waveform: ");
    if (waveform_type == WAVEFORM_SAWTOOTH) {
      waveform_type = WAVEFORM_SINE;
      Serial.println("Sine");
    } else if (waveform_type == WAVEFORM_SINE) {
      waveform_type = WAVEFORM_SQUARE;
      Serial.println("Square");
    } else if (waveform_type == WAVEFORM_SQUARE) {
      waveform_type = WAVEFORM_TRIANGLE;
      Serial.println("Triangle");
    } else if (waveform_type == WAVEFORM_TRIANGLE) {
      waveform_type = WAVEFORM_PULSE;
      Serial.println("Pulse");
    } else if (waveform_type == WAVEFORM_PULSE) {
      waveform_type = WAVEFORM_SAWTOOTH;
      Serial.println("Sawtooth");
    }
    waveformMod1.begin(waveform_type);
  }
//
//  // middle button switch which source we hear from mixer1
//  if (button1.fallingEdge()) {
//    if (mixer1_setting == 0) {
//      mixer1.gain(0, 0.75);
//      mixer1.gain(1, 0.0);
//      mixer1.gain(2, 0.0);
//      mixer1.gain(3, 0.0);
//      Serial.println("Mixer1: Control oscillator");
//      mixer1_setting = 1;
//    } else if (mixer1_setting == 1) {
//      mixer1.gain(0, 0.0);
//      mixer1.gain(1, 0.75);
//      mixer1.gain(2, 0.0);
//      mixer1.gain(3, 0.0);
//      Serial.println("Mixer1: Frequency Modulated Oscillator");
//      mixer1_setting = 2;
//    } else if (mixer1_setting == 2) {
//      mixer1.gain(0, 0.0);
//      mixer1.gain(1, 0.0);
//      mixer1.gain(2, 0.75);
//      mixer1.gain(3, 0.0);
//      Serial.println("Mixer1: Regular Sine Wave Oscillator");
//      mixer1_setting = 3;
//    } else if (mixer1_setting == 3) {
//      mixer1.gain(0, 0.0);
//      mixer1.gain(1, 0.0);
//      mixer1.gain(2, 0.0);
//      mixer1.gain(3, 0.75);
//      Serial.println("Mixer1: Pink Noise");
//      mixer1_setting = 0;
//    }
//  }
//
//  // Right button activates the envelope
//  if (button2.fallingEdge()) {
//    mixer2.gain(0, 0.0);
//    mixer2.gain(1, 1.0);
//    mixer2_envelope = true;
//    timeout = 0;
//    envelope1.noteOn();
//  }
//  if (button2.risingEdge()) {
//    envelope1.noteOff();
//    timeout = 0;
//  }
//
//  // after 4 seconds of inactivity, go back to
//  // steady listening intead of the envelope
//  if (mixer2_envelope == true && timeout > 4000) {
//    mixer2.gain(0, 0.15);
//    mixer2.gain(1, 0.0);
//    mixer2_envelope = false;
//  }

  // use the knobs to adjust parameters
  //float knob1 = (float)analogRead(A1) / 1023.0;
  float knob2 = (float)analogRead(A2) / 1023.0;
  float knob3 = (float)analogRead(A3) / 1023.0;
  float knob4 = (float)analogRead(A4) / 1023.0;
  waveformMod1.frequency(360 * knob2 + 0.25);
  sine1.frequency(knob3 * 1500 + 50);
  // quick and dirty equation for exp scale frequency adjust
  float freq =  expf((float)knob4 / 150.0) * 10.0 + 80.0;
  filter1.frequency(freq);

  //wait(1750);
      button0.update();
    button1.update();
    button2.update();
    if (button0.fallingEdge()) Serial.println("Button (pin 0) Press");
    if (button1.fallingEdge()) Serial.println("Button (pin 1) Press");
    if (button2.fallingEdge()) Serial.println("Button (pin 2) Press");
    if (button0.risingEdge()) Serial.println("Button (pin 0) Release");
    if (button1.risingEdge()) Serial.println("Button (pin 1) Release");
    if (button2.risingEdge()) Serial.println("Button (pin 2) Release");
    int a4 = analogRead(A1);
    int a2 = analogRead(A2);
    int a3 = analogRead(A3);
    if (a4 > a1history + 50 || a4 < a1history - 50) {
      Serial.print("Knob (pin A1) = ");
      Serial.println(a4);
      a1history = a4;
    }
    if (a2 > a2history + 50 || a2 < a2history - 50) {
      Serial.print("Knob (pin A2) = ");
      Serial.println(a2);
      a2history = a2;
    }
    if (a3 > a3history + 50 || a3 < a3history - 50) {
      Serial.print("Knob (pin A3) = ");
      Serial.println(a3);
      a3history = a3;
    }
}


void wait(unsigned int milliseconds)
{
  elapsedMillis msec=0;

  while (msec <= milliseconds) {
    button0.update();
    button1.update();
    button2.update();
    if (button0.fallingEdge()) Serial.println("Button (pin 0) Press");
    if (button1.fallingEdge()) Serial.println("Button (pin 1) Press");
    if (button2.fallingEdge()) Serial.println("Button (pin 2) Press");
    if (button0.risingEdge()) Serial.println("Button (pin 0) Release");
    if (button1.risingEdge()) Serial.println("Button (pin 1) Release");
    if (button2.risingEdge()) Serial.println("Button (pin 2) Release");
    int a4 = analogRead(A1);
    int a2 = analogRead(A2);
    int a3 = analogRead(A3);
    if (a4 > a1history + 50 || a4 < a1history - 50) {
      Serial.print("Knob (pin A1) = ");
      Serial.println(a4);
      a1history = a4;
    }
    if (a2 > a2history + 50 || a2 < a2history - 50) {
      Serial.print("Knob (pin A2) = ");
      Serial.println(a2);
      a2history = a2;
    }
    if (a3 > a3history + 50 || a3 < a3history - 50) {
      Serial.print("Knob (pin A3) = ");
      Serial.println(a3);
      a3history = a3;
    }
  }
}


