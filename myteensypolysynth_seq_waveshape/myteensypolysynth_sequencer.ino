#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     lfoenvelope;    //xy=393.28997802734375,967.1499862670898
AudioSynthWaveform       lfo;            //xy=481.28997802734375,1173.1499862670898
AudioMixer4              mixer1;         //xy=524.2899780273437,1028.1499862670898
AudioAnalyzePeak         peak1;          //xy=753.2899780273437,891.1499862670898
AudioSynthWaveform       voice6b;        //xy=764.2999267578125,1461.2899780273437
AudioSynthNoiseWhite     voice6n;        //xy=764.2999267578125,1496.2899780273437
AudioSynthWaveform       voice7b;        //xy=764.14990234375,1685.4300537109375
AudioSynthNoiseWhite     voice7n;        //xy=764.14990234375,1720.4300537109375
AudioSynthWaveform       voice6a;        //xy=766.2999267578125,1423.2899780273437
AudioSynthWaveform       voice5b;        //xy=770.85986328125,1195.85009765625
AudioSynthWaveform       voice7a;        //xy=769.14990234375,1642.4300537109375
AudioSynthNoiseWhite     voice5n;        //xy=770.85986328125,1230.85009765625
AudioSynthWaveform       voice5a;        //xy=775.85986328125,1152.85009765625
AudioSynthWaveform       voice8b;        //xy=779.2899169921875,1935.010009765625
AudioSynthNoiseWhite     voice8n;        //xy=779.2899169921875,1970.010009765625
AudioSynthWaveform       voice8a;        //xy=781.2899169921875,1897.010009765625
AudioSynthWaveform       voice4a;        //xy=794.579833984375,930.4298706054687
AudioSynthWaveform       voice4b;        //xy=795.579833984375,968.4298706054687
AudioSynthNoiseWhite     voice4n;        //xy=795.579833984375,1003.4298706054687
AudioSynthWaveform       voice3b;        //xy=869.43994140625,693.2899780273437
AudioSynthNoiseWhite     voice3n;        //xy=869.43994140625,728.2899780273437
AudioSynthWaveform       voice2b;        //xy=873.869873046875,458.42999267578125
AudioSynthNoiseWhite     voice2n;        //xy=873.869873046875,493.42999267578125
AudioSynthWaveform       voice1b;        //xy=875.1400146484375,238.719970703125
AudioSynthNoiseWhite     voice1n;        //xy=875.2900390625,282.719970703125
AudioSynthWaveform       voice3a;        //xy=874.43994140625,650.2899780273437
AudioSynthWaveform       voice2a;        //xy=875.869873046875,420.42999267578125
AudioSynthWaveform       voice1a;        //xy=880.1400146484375,195.719970703125
AudioMixer4              voice6mix;      //xy=909.2999267578125,1481.2899780273437
AudioMixer4              voice7mix;      //xy=909.14990234375,1705.4300537109375
AudioMixer4              voice5mix;      //xy=915.85986328125,1215.85009765625
AudioMixer4              voice8mix;      //xy=924.2899169921875,1955.010009765625
AudioMixer4              voice4mix;      //xy=940.579833984375,988.4298706054687
AudioMixer4              voice3mix;      //xy=1014.43994140625,713.2899780273437
AudioMixer4              voice2mix;      //xy=1018.869873046875,478.42999267578125
AudioMixer4              voice1mix;      //xy=1021.5700073242187,245.85999298095703
AudioEffectWaveshaper    voice6waveshape; //xy=1101.8599853515625,1494.1199951171875
AudioEffectWaveshaper    voice8waveshape; //xy=1110.429931640625,1962.72998046875
AudioEffectWaveshaper    voice7waveshape; //xy=1114.7099609375,1709.8299560546875
AudioEffectWaveshaper    voice5waveshape; //xy=1117.5699462890625,1236.8900146484375
AudioSynthWaveformDc     voice8filterenv; //xy=1117.2899780273437,2088.14998626709
AudioEffectWaveshaper    voice4waveshape; //xy=1126.130126953125,998.3199462890625
AudioSynthWaveformDc     voice8env;      //xy=1131.2899780273437,2027.1499862670898
AudioSynthWaveformDc     voice4filterenv; //xy=1139.2899780273437,1110.1499862670898
AudioSynthWaveformDc     voice5filterenv; //xy=1140.2899780273437,1366.1499862670898
AudioSynthWaveformDc     voice7filterenv; //xy=1149.2899780273437,1857.1499862670898
AudioSynthWaveformDc     voice4env;      //xy=1153.2899780273437,1049.1499862670898
AudioSynthWaveformDc     voice6filterenv; //xy=1152.2899780273437,1620.1499862670898
AudioSynthWaveformDc     voice5env;      //xy=1154.2899780273437,1305.1499862670898
AudioSynthWaveformDc     voice3filterenv; //xy=1160.2899780273437,862.1499862670898
AudioSynthWaveformDc     voice7env;      //xy=1163.2899780273437,1796.1499862670898
AudioSynthWaveformDc     voice6env;      //xy=1166.2899780273437,1559.1499862670898
AudioSynthWaveformDc     voice3env;      //xy=1174.2899780273437,801.1499862670898
AudioEffectWaveshaper    voice1waveshape;     //xy=1180.419921875,278.2899169921875
AudioEffectWaveshaper    voice3waveshape; //xy=1183.280029296875,728.2899780273437
AudioSynthWaveformDc     voice1filterenv; //xy=1191.2899780273437,386.14998626708984
AudioSynthWaveformDc     voice2filterenv; //xy=1193.2899780273437,630.1499862670898
AudioEffectWaveshaper    voice2waveshape; //xy=1194.7099609375,494
AudioSynthWaveformDc     voice2env;      //xy=1207.2899780273437,569.1499862670898
AudioSynthWaveformDc     voice1env;      //xy=1208.2899780273437,335.14998626708984
AudioEffectMultiply      voice8multiply; //xy=1298.2899780273437,2000.1499862670898
AudioMixer4              voice8filtermodmixer; //xy=1308.2899780273437,2116.14998626709
AudioEffectMultiply      voice4multiply; //xy=1320.2899780273437,1022.1499862670898
AudioEffectMultiply      voice5multiply; //xy=1321.2899780273437,1278.1499862670898
AudioMixer4              voice4filtermodmixer; //xy=1330.2899780273437,1138.1499862670898
AudioEffectMultiply      voice7multiply; //xy=1330.2899780273437,1769.1499862670898
AudioEffectMultiply      voice6multiply; //xy=1333.2899780273437,1532.1499862670898
AudioMixer4              voice5filtermodmixer; //xy=1338.2899780273437,1388.1499862670898
AudioMixer4              voice6filtermodmixer; //xy=1343.2899780273437,1648.1499862670898
AudioMixer4              voice7filtermodmixer; //xy=1347.2899780273437,1879.1499862670898
AudioMixer4              voice3filtermodmixer; //xy=1358.2899780273437,884.1499862670898
AudioEffectMultiply      voice3multiply; //xy=1367.0001220703125,777.0099487304687
AudioEffectMultiply      voice2multiply; //xy=1374.2899780273437,542.1499862670898
AudioMixer4              voice2filtermodmixer; //xy=1384.2899780273437,658.1499862670898
AudioMixer4              voice1filtermodmixer; //xy=1388.2899780273437,418.14998626708984
AudioEffectMultiply      voice1multiply; //xy=1398.429931640625,316.7200012207031
AudioFilterStateVariable voice8filter;   //xy=1481.2899780273437,2023.1499862670898
AudioFilterStateVariable voice5filter;   //xy=1501.2899780273437,1322.1499862670898
AudioFilterStateVariable voice4filter;   //xy=1503.2899780273437,1045.1499862670898
AudioFilterStateVariable voice7filter;   //xy=1510.2899780273437,1813.1499862670898
AudioFilterStateVariable voice6filter;   //xy=1516.2899780273437,1555.1499862670898
AudioFilterStateVariable voice3filter;   //xy=1521.2899780273437,818.1499862670898
AudioFilterStateVariable voice2filter;   //xy=1557.2899780273437,565.1499862670898
AudioFilterStateVariable voice1filter;   //xy=1574.2899780273437,360.14998626708984
AudioMixer4              last4premix;    //xy=1981.2899780273437,1295.1499862670898
AudioMixer4              first4premix;   //xy=1982.2899780273437,1211.1499862670898
AudioMixer4              mainOutMixer;   //xy=2502.2899780273437,1288.1499862670898
AudioOutputI2S           i2s1;           //xy=2728.2899780273437,1286.1499862670898
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
AudioConnection          patchCord12(voice6b, 0, voice6mix, 1);
AudioConnection          patchCord13(voice6n, 0, voice6mix, 2);
AudioConnection          patchCord14(voice7b, 0, voice7mix, 1);
AudioConnection          patchCord15(voice7n, 0, voice7mix, 2);
AudioConnection          patchCord16(voice6a, 0, voice6mix, 0);
AudioConnection          patchCord17(voice5b, 0, voice5mix, 1);
AudioConnection          patchCord18(voice7a, 0, voice7mix, 0);
AudioConnection          patchCord19(voice5n, 0, voice5mix, 2);
AudioConnection          patchCord20(voice5a, 0, voice5mix, 0);
AudioConnection          patchCord21(voice8b, 0, voice8mix, 1);
AudioConnection          patchCord22(voice8n, 0, voice8mix, 2);
AudioConnection          patchCord23(voice8a, 0, voice8mix, 0);
AudioConnection          patchCord24(voice4a, 0, voice4mix, 0);
AudioConnection          patchCord25(voice4b, 0, voice4mix, 1);
AudioConnection          patchCord26(voice4n, 0, voice4mix, 2);
AudioConnection          patchCord27(voice3b, 0, voice3mix, 1);
AudioConnection          patchCord28(voice3n, 0, voice3mix, 2);
AudioConnection          patchCord29(voice2b, 0, voice2mix, 1);
AudioConnection          patchCord30(voice2n, 0, voice2mix, 3);
AudioConnection          patchCord31(voice1b, 0, voice1mix, 1);
AudioConnection          patchCord32(voice1n, 0, voice1mix, 2);
AudioConnection          patchCord33(voice3a, 0, voice3mix, 0);
AudioConnection          patchCord34(voice2a, 0, voice2mix, 0);
AudioConnection          patchCord35(voice1a, 0, voice1mix, 0);
AudioConnection          patchCord36(voice6mix, voice6waveshape);
AudioConnection          patchCord37(voice7mix, voice7waveshape);
AudioConnection          patchCord38(voice5mix, voice5waveshape);
AudioConnection          patchCord39(voice8mix, voice8waveshape);
AudioConnection          patchCord40(voice4mix, voice4waveshape);
AudioConnection          patchCord41(voice3mix, voice3waveshape);
AudioConnection          patchCord42(voice2mix, voice2waveshape);
AudioConnection          patchCord43(voice1mix, voice1waveshape);
AudioConnection          patchCord44(voice6waveshape, 0, voice6multiply, 0);
AudioConnection          patchCord45(voice8waveshape, 0, voice8multiply, 0);
AudioConnection          patchCord46(voice7waveshape, 0, voice7multiply, 0);
AudioConnection          patchCord47(voice5waveshape, 0, voice5multiply, 0);
AudioConnection          patchCord48(voice8filterenv, 0, voice8filtermodmixer, 0);
AudioConnection          patchCord49(voice4waveshape, 0, voice4multiply, 0);
AudioConnection          patchCord50(voice8env, 0, voice8multiply, 1);
AudioConnection          patchCord51(voice4filterenv, 0, voice4filtermodmixer, 0);
AudioConnection          patchCord52(voice5filterenv, 0, voice5filtermodmixer, 0);
AudioConnection          patchCord53(voice7filterenv, 0, voice7filtermodmixer, 0);
AudioConnection          patchCord54(voice4env, 0, voice4multiply, 1);
AudioConnection          patchCord55(voice6filterenv, 0, voice6filtermodmixer, 0);
AudioConnection          patchCord56(voice5env, 0, voice5multiply, 1);
AudioConnection          patchCord57(voice3filterenv, 0, voice3filtermodmixer, 0);
AudioConnection          patchCord58(voice7env, 0, voice7multiply, 1);
AudioConnection          patchCord59(voice6env, 0, voice6multiply, 1);
AudioConnection          patchCord60(voice3env, 0, voice3multiply, 1);
AudioConnection          patchCord61(voice1waveshape, 0, voice1multiply, 0);
AudioConnection          patchCord62(voice3waveshape, 0, voice3multiply, 0);
AudioConnection          patchCord63(voice1filterenv, 0, voice1filtermodmixer, 0);
AudioConnection          patchCord64(voice2filterenv, 0, voice2filtermodmixer, 0);
AudioConnection          patchCord65(voice2waveshape, 0, voice2multiply, 0);
AudioConnection          patchCord66(voice2env, 0, voice2multiply, 1);
AudioConnection          patchCord67(voice1env, 0, voice1multiply, 1);
AudioConnection          patchCord68(voice8multiply, 0, voice8filter, 0);
AudioConnection          patchCord69(voice8filtermodmixer, 0, voice8filter, 1);
AudioConnection          patchCord70(voice4multiply, 0, voice4filter, 0);
AudioConnection          patchCord71(voice5multiply, 0, voice5filter, 0);
AudioConnection          patchCord72(voice4filtermodmixer, 0, voice4filter, 1);
AudioConnection          patchCord73(voice7multiply, 0, voice7filter, 0);
AudioConnection          patchCord74(voice6multiply, 0, voice6filter, 0);
AudioConnection          patchCord75(voice5filtermodmixer, 0, voice5filter, 1);
AudioConnection          patchCord76(voice6filtermodmixer, 0, voice6filter, 1);
AudioConnection          patchCord77(voice7filtermodmixer, 0, voice7filter, 1);
AudioConnection          patchCord78(voice3filtermodmixer, 0, voice3filter, 1);
AudioConnection          patchCord79(voice3multiply, 0, voice3filter, 0);
AudioConnection          patchCord80(voice2multiply, 0, voice2filter, 0);
AudioConnection          patchCord81(voice2filtermodmixer, 0, voice2filter, 1);
AudioConnection          patchCord82(voice1filtermodmixer, 0, voice1filter, 1);
AudioConnection          patchCord83(voice1multiply, 0, voice1filter, 0);
AudioConnection          patchCord84(voice8filter, 0, last4premix, 3);
AudioConnection          patchCord85(voice5filter, 0, last4premix, 0);
AudioConnection          patchCord86(voice4filter, 0, first4premix, 3);
AudioConnection          patchCord87(voice7filter, 0, last4premix, 2);
AudioConnection          patchCord88(voice6filter, 0, last4premix, 1);
AudioConnection          patchCord89(voice3filter, 0, first4premix, 2);
AudioConnection          patchCord90(voice2filter, 0, first4premix, 1);
AudioConnection          patchCord91(voice1filter, 0, first4premix, 0);
AudioConnection          patchCord92(last4premix, 0, mainOutMixer, 1);
AudioConnection          patchCord93(first4premix, 0, mainOutMixer, 0);
AudioConnection          patchCord94(mainOutMixer, 0, i2s1, 0);
AudioConnection          patchCord95(mainOutMixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2465.2899780273437,1055.1499862670898
// GUItool: end automatically generated code




//config variables
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (4)

#define MAX_DEBOUNCE (3)

static const uint8_t btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
static const uint8_t btnrowpins[NUM_BTN_ROWS]       = {6, 7, 31,32};

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

int btnState[16];
int prevBtnState[16];


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

//Waveshaper array
float WAVESHAPE_YAMAHA[17] = {
    -1.0000,   -0.9775 ,  -0.9141,   -0.8154,   -0.6875,   -0.5361,
   -0.3672,   -0.1865,         0,    0.1865,    0.3672,    0.5361,
    0.6875,    0.8154,    0.9141,    0.9775,    1.0000,
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

  voice1waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice2waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice3waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice4waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice5waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice6waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice7waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice8waveshape.shape(WAVESHAPE_YAMAHA, 17);
  
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

  attackTimeFilter = 0;
  decayTimeFilter = 0;
  sustainLevelFilter = 1;
  releaseTimeFilter = 500;

  attackTime = 0;
  decayTime = 250;
  sustainLevel= 1;
  releaseTime= 500;

  //Sequencer
  stepLength = 250; //BPM
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
//  Serial.println("buttonUpdate:");
//  Serial.println(i);
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
            
//            Serial.println("btnState:");
//            Serial.println(btnState);
//            Serial.println("previous:");
//            Serial.println(prevBtnState);

            if(j == 0 || j == 1){
              for(int k = 0; k< 8; k++){
                Serial.println(buttonHeld[k]);
                if(buttonHeld[k]){
                  Serial.println("sequencer input");
                  Serial.println("button");
                  Serial.println(k);
                  Serial.println("at step");
                  Serial.println(index);
                  steps[index][k] = 1; 
                }
              }
            }
            else{
              index = index%8;
              Serial.println("note triggered");
              Serial.println(index);
              buttonHeld[index]= 1;  
              
              btnState[index] = LOW;
            
              buttonUpdate(index);

            
            }
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

            if(j== 2 || j == 3){
              index = index%8;
              
              Serial.println("note released");
              Serial.println(index);
              
              buttonHeld[index] = 0;
              
              btnState[index] = HIGH;

              buttonUpdate(index);
            }
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

      //set prevBtnState to high to always retrig envelopes
      prevBtnState[index] = HIGH;
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

  if(millis() - stepWait > stepLength){
    stepWait = millis();
    if(activeStep == 7){
      activeStep = 0;
    }
    else{
      activeStep++;
    }
    advanceSequencer();
  }
}




