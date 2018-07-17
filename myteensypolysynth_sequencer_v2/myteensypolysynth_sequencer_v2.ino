#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     lfoenvelope;    //xy=306,883
AudioSynthWaveform       lfo;            //xy=394,1089
AudioMixer4              mixer1;         //xy=437,944
AudioAnalyzePeak         peak1;          //xy=666,807
AudioSynthWaveform       voice8b;        //xy=902,1858
AudioSynthNoiseWhite     voice8n;        //xy=902,1893
AudioSynthWaveform       voice8a;        //xy=904,1820
AudioSynthWaveform       voice4a;        //xy=923,842
AudioSynthWaveform       voice4b;        //xy=924,880
AudioSynthNoiseWhite     voice4n;        //xy=924,915
AudioSynthWaveform       voice5b;        //xy=925,1136
AudioSynthNoiseWhite     voice5n;        //xy=925,1171
AudioSynthWaveform       voice5a;        //xy=930,1093
AudioSynthWaveform       voice7b;        //xy=934,1627
AudioSynthNoiseWhite     voice7n;        //xy=934,1662
AudioSynthWaveform       voice6b;        //xy=937,1390
AudioSynthNoiseWhite     voice6n;        //xy=937,1425
AudioSynthWaveform       voice6a;        //xy=939,1352
AudioSynthWaveform       voice7a;        //xy=939,1584
AudioSynthWaveform       voice3b;        //xy=945,632
AudioSynthNoiseWhite     voice3n;        //xy=945,667
AudioSynthWaveform       voice3a;        //xy=950,589
AudioSynthWaveform       voice1b;        //xy=975,166
AudioSynthNoiseWhite     voice1n;        //xy=978,210
AudioSynthWaveform       voice2b;        //xy=978,400
AudioSynthNoiseWhite     voice2n;        //xy=978,435
AudioSynthWaveform       voice1a;        //xy=980,123
AudioSynthWaveform       voice2a;        //xy=980,362
AudioSynthWaveformDc     voice8filterenv; //xy=1030,2004
AudioSynthWaveformDc     voice8env;      //xy=1044,1943
AudioMixer4              voice8mix;      //xy=1047,1878
AudioSynthWaveformDc     voice4filterenv; //xy=1052,1026
AudioSynthWaveformDc     voice5filterenv; //xy=1053,1282
AudioSynthWaveformDc     voice7filterenv; //xy=1062,1773
AudioSynthWaveformDc     voice4env;      //xy=1066,965
AudioSynthWaveformDc     voice6filterenv; //xy=1065,1536
AudioSynthWaveformDc     voice5env;      //xy=1067,1221
AudioMixer4              voice4mix;      //xy=1069,900
AudioMixer4              voice5mix;      //xy=1070,1156
AudioSynthWaveformDc     voice3filterenv; //xy=1073,778
AudioSynthWaveformDc     voice7env;      //xy=1076,1712
AudioSynthWaveformDc     voice6env;      //xy=1079,1475
AudioMixer4              voice7mix;      //xy=1079,1647
AudioMixer4              voice6mix;      //xy=1082,1410
AudioSynthWaveformDc     voice3env;      //xy=1087,717
AudioMixer4              voice3mix;      //xy=1090,652
AudioSynthWaveformDc     voice1filterenv; //xy=1104,302
AudioSynthWaveformDc     voice2filterenv; //xy=1106,546
AudioMixer4              voice1mix;      //xy=1120,186
AudioSynthWaveformDc     voice2env;      //xy=1120,485
AudioSynthWaveformDc     voice1env;      //xy=1121,251
AudioMixer4              voice2mix;      //xy=1123,420
AudioEffectMultiply      voice8multiply; //xy=1211,1916
AudioMixer4              voice8filtermodmixer; //xy=1221,2032
AudioEffectMultiply      voice4multiply; //xy=1233,938
AudioEffectMultiply      voice5multiply; //xy=1234,1194
AudioMixer4              voice4filtermodmixer; //xy=1243,1054
AudioEffectMultiply      voice7multiply; //xy=1243,1685
AudioEffectMultiply      voice6multiply; //xy=1246,1448
AudioMixer4              voice5filtermodmixer; //xy=1251,1304
AudioEffectMultiply      voice3multiply; //xy=1254,690
AudioMixer4              voice6filtermodmixer; //xy=1256,1564
AudioMixer4              voice7filtermodmixer; //xy=1260,1795
AudioMixer4              voice3filtermodmixer; //xy=1271,800
AudioEffectMultiply      voice1multiply; //xy=1284,224
AudioEffectMultiply      voice2multiply; //xy=1287,458
AudioMixer4              voice2filtermodmixer; //xy=1297,574
AudioMixer4              voice1filtermodmixer; //xy=1301,334
AudioFilterStateVariable voice8filter;   //xy=1394,1939
AudioFilterStateVariable voice5filter;   //xy=1414,1238
AudioFilterStateVariable voice4filter;   //xy=1416,961
AudioFilterStateVariable voice7filter;   //xy=1423,1729
AudioFilterStateVariable voice6filter;   //xy=1429,1471
AudioFilterStateVariable voice3filter;   //xy=1434,734
AudioFilterStateVariable voice2filter;   //xy=1470,481
AudioFilterStateVariable voice1filter;   //xy=1487,276
AudioMixer4              last4premix;    //xy=1894,1211
AudioMixer4              first4premix;   //xy=1895,1127
AudioMixer4              mainOutMixer;   //xy=2415,1204
AudioOutputI2S           i2s1;           //xy=2641,1202
AudioConnection          patchCord1(lfoenvelope, 0, mixer1, 0);
AudioConnection          patchCord2(lfo, 0, voice1filtermodmixer, 1);
AudioConnection          patchCord3(lfo, 0, voice2filtermodmixer, 1);
AudioConnection          patchCord4(lfo, 0, voice3filtermodmixer, 1);
AudioConnection          patchCord5(lfo, 0, voice4filtermodmixer, 1);
AudioConnection          patchCord6(lfo, 0, voice5filtermodmixer, 1);
AudioConnection          patchCord7(lfo, 0, voice6filtermodmixer, 1);
AudioConnection          patchCord8(lfo, 0, voice7filtermodmixer, 1);
AudioConnection          patchCord9(lfo, 0, voice8filtermodmixer, 1);
AudioConnection          patchCord10(lfo, 0, mixer1, 1);
AudioConnection          patchCord11(mixer1, peak1);
AudioConnection          patchCord12(voice8b, 0, voice8mix, 1);
AudioConnection          patchCord13(voice8n, 0, voice8mix, 2);
AudioConnection          patchCord14(voice8a, 0, voice8mix, 0);
AudioConnection          patchCord15(voice4a, 0, voice4mix, 0);
AudioConnection          patchCord16(voice4b, 0, voice4mix, 1);
AudioConnection          patchCord17(voice4n, 0, voice4mix, 2);
AudioConnection          patchCord18(voice5b, 0, voice5mix, 1);
AudioConnection          patchCord19(voice5n, 0, voice5mix, 2);
AudioConnection          patchCord20(voice5a, 0, voice5mix, 0);
AudioConnection          patchCord21(voice7b, 0, voice7mix, 1);
AudioConnection          patchCord22(voice7n, 0, voice7mix, 2);
AudioConnection          patchCord23(voice6b, 0, voice6mix, 1);
AudioConnection          patchCord24(voice6n, 0, voice6mix, 2);
AudioConnection          patchCord25(voice6a, 0, voice6mix, 0);
AudioConnection          patchCord26(voice7a, 0, voice7mix, 0);
AudioConnection          patchCord27(voice3b, 0, voice3mix, 1);
AudioConnection          patchCord28(voice3n, 0, voice3mix, 2);
AudioConnection          patchCord29(voice3a, 0, voice3mix, 0);
AudioConnection          patchCord30(voice1b, 0, voice1mix, 1);
AudioConnection          patchCord31(voice1n, 0, voice1mix, 2);
AudioConnection          patchCord32(voice2b, 0, voice2mix, 1);
AudioConnection          patchCord33(voice2n, 0, voice2mix, 3);
AudioConnection          patchCord34(voice1a, 0, voice1mix, 0);
AudioConnection          patchCord35(voice2a, 0, voice2mix, 0);
AudioConnection          patchCord36(voice8filterenv, 0, voice8filtermodmixer, 0);
AudioConnection          patchCord37(voice8env, 0, voice8multiply, 1);
AudioConnection          patchCord38(voice8mix, 0, voice8multiply, 0);
AudioConnection          patchCord39(voice4filterenv, 0, voice4filtermodmixer, 0);
AudioConnection          patchCord40(voice5filterenv, 0, voice5filtermodmixer, 0);
AudioConnection          patchCord41(voice7filterenv, 0, voice7filtermodmixer, 0);
AudioConnection          patchCord42(voice4env, 0, voice4multiply, 1);
AudioConnection          patchCord43(voice6filterenv, 0, voice6filtermodmixer, 0);
AudioConnection          patchCord44(voice5env, 0, voice5multiply, 1);
AudioConnection          patchCord45(voice4mix, 0, voice4multiply, 0);
AudioConnection          patchCord46(voice5mix, 0, voice5multiply, 0);
AudioConnection          patchCord47(voice3filterenv, 0, voice3filtermodmixer, 0);
AudioConnection          patchCord48(voice7env, 0, voice7multiply, 1);
AudioConnection          patchCord49(voice6env, 0, voice6multiply, 1);
AudioConnection          patchCord50(voice7mix, 0, voice7multiply, 0);
AudioConnection          patchCord51(voice6mix, 0, voice6multiply, 0);
AudioConnection          patchCord52(voice3env, 0, voice3multiply, 1);
AudioConnection          patchCord53(voice3mix, 0, voice3multiply, 0);
AudioConnection          patchCord54(voice1filterenv, 0, voice1filtermodmixer, 0);
AudioConnection          patchCord55(voice2filterenv, 0, voice2filtermodmixer, 0);
AudioConnection          patchCord56(voice1mix, 0, voice1multiply, 0);
AudioConnection          patchCord57(voice2env, 0, voice2multiply, 1);
AudioConnection          patchCord58(voice1env, 0, voice1multiply, 1);
AudioConnection          patchCord59(voice2mix, 0, voice2multiply, 0);
AudioConnection          patchCord60(voice8multiply, 0, voice8filter, 0);
AudioConnection          patchCord61(voice8filtermodmixer, 0, voice8filter, 1);
AudioConnection          patchCord62(voice4multiply, 0, voice4filter, 0);
AudioConnection          patchCord63(voice5multiply, 0, voice5filter, 0);
AudioConnection          patchCord64(voice4filtermodmixer, 0, voice4filter, 1);
AudioConnection          patchCord65(voice7multiply, 0, voice7filter, 0);
AudioConnection          patchCord66(voice6multiply, 0, voice6filter, 0);
AudioConnection          patchCord67(voice5filtermodmixer, 0, voice5filter, 1);
AudioConnection          patchCord68(voice3multiply, 0, voice3filter, 0);
AudioConnection          patchCord69(voice6filtermodmixer, 0, voice6filter, 1);
AudioConnection          patchCord70(voice7filtermodmixer, 0, voice7filter, 1);
AudioConnection          patchCord71(voice3filtermodmixer, 0, voice3filter, 1);
AudioConnection          patchCord72(voice1multiply, 0, voice1filter, 0);
AudioConnection          patchCord73(voice2multiply, 0, voice2filter, 0);
AudioConnection          patchCord74(voice2filtermodmixer, 0, voice2filter, 1);
AudioConnection          patchCord75(voice1filtermodmixer, 0, voice1filter, 1);
AudioConnection          patchCord76(voice8filter, 0, last4premix, 3);
AudioConnection          patchCord77(voice5filter, 0, last4premix, 0);
AudioConnection          patchCord78(voice4filter, 0, first4premix, 3);
AudioConnection          patchCord79(voice7filter, 0, last4premix, 2);
AudioConnection          patchCord80(voice6filter, 0, last4premix, 1);
AudioConnection          patchCord81(voice3filter, 0, first4premix, 2);
AudioConnection          patchCord82(voice2filter, 0, first4premix, 1);
AudioConnection          patchCord83(voice1filter, 0, first4premix, 0);
AudioConnection          patchCord84(last4premix, 0, mainOutMixer, 1);
AudioConnection          patchCord85(first4premix, 0, mainOutMixer, 0);
AudioConnection          patchCord86(mainOutMixer, 0, i2s1, 0);
AudioConnection          patchCord87(mainOutMixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2378,971
// GUItool: end automatically generated code

//config variables
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (4)

#define MAX_DEBOUNCE (3)

static const uint8_t btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
static const uint8_t btnrowpins[NUM_BTN_ROWS]       = {6, 7, 9, 10};

static int8_t debounce_count[NUM_BTN_COLUMNS][NUM_BTN_ROWS];

int colorIndex;
int keyIndex;
float noteFreq[7][8] = {

  //5       1       6      2      7      3      8     4  
  {329.63,220.00,369.99,246.94,415.30,277.18,440.00,293.66},
  {369.99,246.94,415.30,277.18,466.16,311.13,493.88,329.63},
  {392.00,261.63,440.00,293.66,493.88,329.63,523.25,349.23},
  {440.00,293.66,493.88,329.63,554.37,369.99,587.33,392.00},
  {493.88,329.63,554.37,369.99,622.25,415.30,659.25,440.00},
  {523.25,349.23,587.33,392.00,659.25,440.00,698.46,466.16},
  {587.33,392.00,659.25,440.00,739.99,493.88,783.99,523.25},
};

int steps[8][8];

int btnState[8];
int prevBtnState[8];


//Analog Inputs
float analogValues[16];
float analogValuesLag[16];

float extraAnalogValues[5];
float extraAnalogValuesLag[5];
int changeThresh;
int extraChangeThresh;

//EnvSwitch
int EnvSwitchPin = 32;
int envelopeFilter;

float tempPulseWidth;
float tempPeak;
float tempRMS;


//synth
float mainVolume;
int tempLineOutLevel;
float vcoOneLevel;
float vcoTwoLevel;
int vcoOneOct;
int vcoTwoOct;
int octArray[6] = {1,1,2,4,8,16};
float deTune;
int waveShapeOneIndex;
int waveShapeTwoIndex;
int lfoWaveShapeIndex;
int octOneIndex;
int octTwoIndex;
//WaveShapes
short waveShapes[4] = {
  WAVEFORM_SINE,
  WAVEFORM_SAWTOOTH,
  WAVEFORM_SQUARE,
  WAVEFORM_PULSE,
};
bool voiceBPulse;
float tempDetuneMod;
float deTuneLfo;
//LFO WaveShapes
short lfoWaveShapes[5] = {
  WAVEFORM_SINE,
  WAVEFORM_SAWTOOTH,
  WAVEFORM_SAWTOOTH_REVERSE,
  WAVEFORM_SQUARE,
  WAVEFORM_SAMPLE_HOLD,
};
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
//LFO ADSR
// int attackTimeLFO;
// int decayTimeLFO;
// float sustainLevelLFO;
// int releaseTimeLFO;

//Note Timing
bool noteTrigFlag[8];
unsigned long attackWait[8];

bool firstRunRead;

//Sequencer
double stepLength; //120 BPM
double stepWait;
int activeStep;
float buttonHeld[8];


void setup() {
  AudioMemory(160);
  Serial.begin(115200);
  sgtl5000_1.enable();
  sgtl5000_1.volume(.7);

  colorIndex = 0;
  keyIndex = 0;

  //mix
  first4premix.gain(0, .25);
  first4premix.gain(1, .25);
  first4premix.gain(2, .25);
  first4premix.gain(3, .25);
  last4premix.gain(0, .25);
  last4premix.gain(1, .25);
  last4premix.gain(2, .25);
  last4premix.gain(3, .25);

  //Voice 1
  voice1a.begin(.3,440,WAVEFORM_SQUARE);
  voice1b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 2
  voice2a.begin(.3,440,WAVEFORM_SQUARE);
  voice2b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 3
  voice3a.begin(.3,440,WAVEFORM_SQUARE);
  voice3b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 4
  voice4a.begin(.3,440,WAVEFORM_SQUARE);
  voice4b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 5
  voice5a.begin(.3,440,WAVEFORM_SQUARE);
  voice5b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 6
  voice6a.begin(.3,440,WAVEFORM_SQUARE);
  voice6b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 7
  voice7a.begin(.3,440,WAVEFORM_SQUARE);
  voice7b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 8
  voice8a.begin(.3,440,WAVEFORM_SQUARE);
  voice8b.begin(.3,440,WAVEFORM_SAWTOOTH);

  float noiseAmplitude = 0;
  
  voice1n.amplitude(0);
  voice2n.amplitude(0);
  voice3n.amplitude(0);
  voice4n.amplitude(0);
  voice5n.amplitude(0);
  voice6n.amplitude(0);
  voice7n.amplitude(0);
  voice8n.amplitude(0);

  //frequency
  double filterfreq = 5000;
  voice1filter.frequency(filterfreq);
  voice2filter.frequency(filterfreq);
  voice3filter.frequency(filterfreq);
  voice4filter.frequency(filterfreq);
  voice5filter.frequency(filterfreq);
  voice6filter.frequency(filterfreq);
  voice7filter.frequency(filterfreq);
  voice8filter.frequency(filterfreq);

  //resonance
  double res = 1;
  voice1filter.resonance(res);
  voice2filter.resonance(res);
  voice3filter.resonance(res);
  voice4filter.resonance(res);
  voice5filter.resonance(res);
  voice6filter.resonance(res);
  voice7filter.resonance(res);
  voice8filter.resonance(res);

  //lfo Mod
  double lfoModMixer = 0;
  voice1filtermodmixer.gain(1,lfoModMixer);
  voice2filtermodmixer.gain(1,lfoModMixer);
  voice3filtermodmixer.gain(1,lfoModMixer);
  voice4filtermodmixer.gain(1,lfoModMixer);
  voice5filtermodmixer.gain(1,lfoModMixer);
  voice6filtermodmixer.gain(1,lfoModMixer);
  voice7filtermodmixer.gain(1,lfoModMixer);
  voice8filtermodmixer.gain(1,lfoModMixer);

  //env Mod
  double envModFilter = 1;
  voice1filtermodmixer.gain(0, envModFilter);
  voice2filtermodmixer.gain(0, envModFilter);
  voice3filtermodmixer.gain(0, envModFilter);
  voice4filtermodmixer.gain(0, envModFilter);
  voice5filtermodmixer.gain(0, envModFilter);
  voice6filtermodmixer.gain(0, envModFilter);
  voice7filtermodmixer.gain(0, envModFilter);
  voice8filtermodmixer.gain(0, envModFilter);

  vcoOneLevel = 0.5;
  vcoTwoLevel = 0.5;
  voice1mix.gain(1,vcoOneLevel);
  voice1mix.gain(0,vcoTwoLevel);
  voice2mix.gain(1,vcoOneLevel);
  voice2mix.gain(0,vcoTwoLevel);
  voice3mix.gain(1,vcoOneLevel);
  voice3mix.gain(0,vcoTwoLevel);  
  voice4mix.gain(1,vcoOneLevel); 
  voice4mix.gain(0,vcoTwoLevel); 
  voice5mix.gain(1,vcoOneLevel); 
  voice5mix.gain(0,vcoTwoLevel); 
  voice6mix.gain(1,vcoOneLevel); 
  voice6mix.gain(0,vcoTwoLevel); 
  voice7mix.gain(1,vcoOneLevel); 
  voice7mix.gain(0,vcoTwoLevel); 
  voice8mix.gain(1,vcoOneLevel); 
  voice8mix.gain(0,vcoTwoLevel); 

  mainOutMixer.gain(0,0.5);
  mainOutMixer.gain(1,0.5);

  //LFO
  lfo.begin(1,3,WAVEFORM_SINE);

  vcoOneOct = 1;
  vcoTwoOct = 1;
  deTune = 1;

  lfoenvelope.amplitude(1);
  voiceBPulse = false;

  attackTimeFilter = 250;
  decayTimeFilter = 250;
  sustainLevelFilter = 1;
  releaseTimeFilter = 500;

  attackTime = 250;
  decayTime = 250;
  sustainLevel= 1;
  releaseTime= 500;

  //Sequencer
  stepLength = 1000; //BPM
  stepWait = 0;
  activeStep = 0;

  firstRunRead = true;

  tempDetuneMod = 0.25;
  

//  pinMode(A18, INPUT);
//  pinMode(A19, INPUT);
//  pinMode(A20, INPUT);
//
//  pinMode(32, INPUT_PULLUP);
//  pinMode(33, OUTPUT);

  uint8_t i;

  // button columns
  for (i = 0; i < NUM_BTN_COLUMNS; i++)
  {
    pinMode(btncolumnpins[i], OUTPUT);

    // with nothing selected by default
    digitalWrite(btncolumnpins[i], HIGH);
  }

  // button row input lines
  for (i = 0; i < NUM_BTN_ROWS; i++)
  {
    pinMode(btnrowpins[i], INPUT_PULLUP);
  }

  // Initialize the debounce counter array
  for (uint8_t i = 0; i < NUM_BTN_COLUMNS; i++)
  {
    for (uint8_t j = 0; j < NUM_BTN_ROWS; j++)
    {
      debounce_count[i][j] = 0;
    }
  }

}

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
int getSmooth(int pin){
  int vals[5]; //array that stores 5 readings.
  for(int i = 0; i < 5; i++){
    vals[i] = analogRead(pin); //takes 5 readings.
  }
  float smooth = (vals[0] + vals[1] + vals[2] + vals[3] + vals[4]) / 5;
  return smooth;
}

void buttonUpdate(int i){
  Serial.println("buttonUpdate:");
  Serial.println(i);
      if(i == 0){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice1env.amplitude(1,attackTime);
          voice1filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();          
        }else{
          noteTrigFlag[i] = false;
          voice1env.amplitude(0,releaseTime);
          voice1filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
      if(i == 1){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice2env.amplitude(1,attackTime);
          voice2filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();
          Serial.println("button pressed");
        }else{
          noteTrigFlag[i] = false;
          voice2env.amplitude(0,releaseTime);
          voice2filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
      if(i == 2){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice3env.amplitude(1,attackTime);
          voice3filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();
        }else{
          noteTrigFlag[i] = false;
          voice3env.amplitude(0,releaseTime);
          voice3filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
      if(i == 3){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice4env.amplitude(1,attackTime);
          voice4filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();
        }else{
          noteTrigFlag[i] = false;
          voice4env.amplitude(0,releaseTime);
          voice4filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
      if(i == 4){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice5env.amplitude(1,attackTime);
          voice5filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();
        }else{
          noteTrigFlag[i] = false;
          voice5env.amplitude(0,releaseTime);
          voice5filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
      if(i == 5){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice6env.amplitude(1,attackTime);
          voice6filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();
        }else{
          noteTrigFlag[i] = false;
          voice6env.amplitude(0,releaseTime);
          voice6filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
      if(i == 6){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice7env.amplitude(1,attackTime);
          voice7filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();
        }else{
          noteTrigFlag[i] = false;
          voice7env.amplitude(0,releaseTime);
          voice7filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
      if(i == 7){
        if (btnState[i] == LOW && prevBtnState[i] == HIGH){
          voice8env.amplitude(1,attackTime);
          voice8filterenv.amplitude(1,attackTimeFilter);
          noteTrigFlag[i] = true;
          attackWait[i] = millis();
        }else{
          noteTrigFlag[i] = false;
          voice8env.amplitude(0,releaseTime);
          voice8filterenv.amplitude(-1, releaseTimeFilter);
        }
      }
}

static void scan()
{
  static uint8_t current = 0;
  uint8_t val;
  uint8_t i, j;
  int index = 0;;
  
  for(int i = 0; i < NUM_BTN_COLUMNS; i++){
    
    // Select current columns
    digitalWrite(btncolumnpins[i], LOW);
    //digitalWrite(ledcolumnpins[current], LOW);
  
    // pause a moment
    delay(1);
  
    // Read the button inputs
    for ( j = 0; j < NUM_BTN_ROWS; j++)
    {
      index = j*NUM_BTN_COLUMNS+i;
      
      val = digitalRead(btnrowpins[j]);

      //Serial.println(prevBtnState);
      
      if (val == LOW)
      {
        // active low: val is low when btn is pressed
        if ( debounce_count[i][j] < MAX_DEBOUNCE)
        {
          debounce_count[i][j]++;
          if ( debounce_count[i][j] == MAX_DEBOUNCE )
          {
            
            Serial.print("Key Down ");
            Serial.println(index);
            Serial.println("row:");
            Serial.println(j);
            Serial.println("column:");
            Serial.println(i); 
            
            btnState[index] = LOW;

            buttonUpdate(index);
            
            
          }
        }
      }
      else
      {
        // otherwise, button is released
        if ( debounce_count[i][j] > 0)
        {
          debounce_count[i][j]--;
          if ( debounce_count[i][j] == 0 )
          {
            Serial.print("Key Up ");
            Serial.println(index);
            Serial.println("row:");
            Serial.println(j);
            Serial.println("column:");
            Serial.println(i); 
            btnState[index] = HIGH;

            buttonUpdate(index); 
          }
        }
      } 
    }// for j = 0 to 3;

    delay(1);
  
    digitalWrite(btncolumnpins[i], HIGH);

  }
}  

void advanceSequencer(){

  for(int index = 0; index< 8; index++){ 
    if(steps[activeStep][index]){
      
      Serial.println("note triggered");
      Serial.println("activeStep");
      Serial.println(activeStep);
      Serial.println("freq");

      btnState[index] = LOW;
      buttonUpdate(index);
                
    }
    else {  

      btnState[index] = HIGH;
      buttonUpdate(index);
    }
  }
}

void loop() {

  //Volume
//  mainVolume = analogRead(A1);
//  mainVolume = mainVolume/1023;
//  sgtl5000_1.volume(mainVolume);
//  tempLineOutLevel = analogRead(A1);
//  tempLineOutLevel = map(tempLineOutLevel, 0, 1023, 31, 13);
//  sgtl5000_1.lineOutLevel(tempLineOutLevel);

  //notes
  for(int i=0; i<8; i++){
    if(i == 0){
      voice1a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice1b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    if(i == 1){
      voice2a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice2b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    if(i == 2){
      voice3a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice3b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    if(i == 3){
      voice4a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice4b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    if(i == 4){
      voice5a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice5b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    if(i == 5){
      voice6a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice6b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    if(i == 6){
      voice7a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice7b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    if(i == 7){
      voice8a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice8b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    
    scan();
   
    if(btnState[i] == LOW){
      if(i == 0){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice1env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice1filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      }
      if(i == 1){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice2env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice2filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      }
      if(i == 2){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice3env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice3filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      }   
      if(i == 3){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice4env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice4filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      }  
      if(i == 4){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice5env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice5filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      }  
      if(i == 5){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice6env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice6filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      } 
      if(i == 6){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice7env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice7filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      } 
      if(i == 7){
        if(millis() - attackWait[i] > attackTime && noteTrigFlag[i]){
          voice8env.amplitude(sustainLevel,decayTime);
        }
        if(millis() - attackWait[i] > attackTimeFilter && noteTrigFlag[i]){
          voice8filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        }
      } 
    }
    prevBtnState[i] = btnState[i];
  }

//  //LFO Peak
//  if(peak1.available()){
//    tempPeak = peak1.read();
//  }
//  else
//  {
//    deTuneLfo = ((tempPeak) * tempDetuneMod + 1);
//    //Serial.println(deTuneLfo);
//  }
  firstRunRead = false;

//  if(millis() - stepWait > stepLength){
//    stepWait = millis();
//    if(activeStep == 7){
//      activeStep = 0;
//    }
//    else{
//      activeStep++;
//    }
//    //advanceSequencer();
//  }
}




