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

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=155,33
AudioSynthWaveformDc     voice1env;            //xy=161,119
AudioSynthWaveformDc     voice1filterenv;            //xy=168,243
AudioEffectMultiply      voice1multiply;      //xy=371,79
AudioMixer4              voice1filtermodmixer;         //xy=393,201
AudioFilterStateVariable voice1filter;        //xy=580,116
AudioMixer4              mixer1;         //xy=760,136
AudioOutputI2S           i2s1;           //xy=972,141
AudioConnection          patchCord1(waveform1, 0, voice1multiply, 0);
AudioConnection          patchCord2(voice1env, 0, voice1multiply, 1);
AudioConnection          patchCord3(voice1filterenv, 0, voice1filtermodmixer, 0);
AudioConnection          patchCord4(voice1multiply, 0, voice1filter, 0);
AudioConnection          patchCord5(voice1filtermodmixer, 0, voice1filter, 1);
AudioConnection          patchCord6(voice1filter, 0, mixer1, 0);
AudioConnection          patchCord7(mixer1, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=589,299
// GUItool: end automatically generated code

//Note Timing
bool noteTrigFlag;
unsigned long attackWait;

int btnState = 0;
int prevBtnState = 0;

//ADSR
int attackTime;
int decayTime;
float sustainLevel;
int releaseTime;
//Filter ADSR
int attackTimeFilter;
int decayTimeFilter;
float sustainLevelFilter;
int releaseTimeFilter;

float filterfreq;
float pulseWidth;

void setup() {
  Serial.begin(9600);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);
  
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  
  voice1filtermodmixer.gain(0, 1);
  mixer1.gain(0, 1);

  attackTime = 50;
  decayTime = 0;
  sustainLevel = 1;
  releaseTime = 0;
  
  attackTimeFilter = 250;
  decayTimeFilter = 500;
  sustainLevelFilter = 1;
  releaseTimeFilter = 0;
  
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.75);
  waveform1.frequency(50);
//  waveformMod1.pulseWidth(0.15);
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
    waveform1.begin(waveform_type);
  }
  
  btnState = digitalRead(2);

  if(button2.update()){
    if (btnState == LOW && prevBtnState == HIGH){
          voice1env.amplitude(1,attackTime);
          voice1filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag = true;
          attackWait = millis();
          Serial.println("decayTimeFilter :");
          Serial.println(decayTimeFilter);
          Serial.println("attackTimeFilter :");
          Serial.println(attackTimeFilter);          
          Serial.println("filterfreq :");
          Serial.println(filterfreq);
          Serial.println("pulseWidth");
          Serial.println(pulseWidth);
        }else{
          noteTrigFlag = false;
          voice1env.amplitude(0,releaseTime);
          voice1filterenv.amplitude(-1, releaseTimeFilter);
  //        Serial.println("voice1env level: ");
  //        Serial.println(voice1env.read());
  //        Serial.println("voice1filterenv level: ");
  //        Serial.println(voice1filterenv.read());
     }
  }
  if(btnState == LOW){
        if(millis() - attackWait > attackTime && noteTrigFlag){
         voice1env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait > attackTimeFilter && noteTrigFlag){
          voice1filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
  }

  prevBtnState = btnState;
  
  // use the knobs to adjust parameters
  //float knob1 = (float)analogRead(A1) / 1023.0;
  float knob2 = (float)analogRead(A2) / 1023.0;
  float knob3 = (float)analogRead(A3) / 1023.0;
  float knob4 = (float)analogRead(A4) / 1023.0;
  //waveform1.frequency(360 * knob2 + 0.25);
  pulseWidth = knob2;
  waveform1.pulseWidth(pulseWidth);
  //attackTimeFilter = knob2 * 2000 -500;
  
  //decayTimeFilter = knob3 * 2000 -500;
  
  voice1filter.resonance(4);
  // quick and dirty equation for exp scale frequency adjust
  //float filterfreq =  expf((float)knob4 / 150.0) * 10.0 + 80.0;
  filterfreq = knob4 * 20000 -5000;
  voice1filter.frequency(filterfreq);

//  if (button0.fallingEdge()) Serial.println("Button (pin 0) Press");
//  if (button1.fallingEdge()) Serial.println("Button (pin 1) Press");
//  if (button2.fallingEdge()) Serial.println("Button (pin 2) Press");
//  if (button0.risingEdge()) Serial.println("Button (pin 0) Release");
//  if (button1.risingEdge()) Serial.println("Button (pin 1) Release");
//  if (button2.risingEdge()) Serial.println("Button (pin 2) Release");
//  int a4 = analogRead(A4);
//  int a2 = analogRead(A2);
//  int a3 = analogRead(A3);
//  if (a4 > a1history + 50 || a4 < a1history - 50) {
//    Serial.print("Knob (pin A1) = ");
//    Serial.println(a4);
//    a1history = a4;
//    Serial.println("filter frequency: ");
//    Serial.println(filterfreq);
//  }
//  if (a2 > a2history + 50 || a2 < a2history - 50) {
//    Serial.print("Knob (pin A2) = ");
//    Serial.println(a2);
//    a2history = a2;
//  }
//  if (a3 > a3history + 50 || a3 < a3history - 50) {
//    Serial.print("Knob (pin A3) = ");
//    Serial.println(a3);
//    a3history = a3;
//    Serial.println("releaseFilter: ");
//    Serial.println(releaseFilter);
//  }
}



