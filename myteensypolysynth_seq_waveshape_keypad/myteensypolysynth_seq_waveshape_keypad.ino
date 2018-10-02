#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

#include <Keypad.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     lfoenvelope;    //xy=65.5,954.0000514984131
AudioSynthWaveform       lfo;            //xy=153.5,1160.000051498413
AudioMixer4              mixer1;         //xy=196.5,1015.0000514984131
AudioSynthWaveform       voice7b;        //xy=285.00401306152344,1671.0001311302185
AudioSynthNoiseWhite     voice7n;        //xy=285.00401306152344,1706.0001311302185
AudioSynthWaveform       voice7a;        //xy=290.00401306152344,1628.0001311302185
AudioSynthWaveform       voice8b;        //xy=291.0039863586426,1914.0001373291016
AudioSynthNoiseWhite     voice8n;        //xy=291.0039863586426,1949.0001373291016
AudioSynthWaveform       voice8a;        //xy=293.0039863586426,1876.0001373291016
AudioSynthWaveform       voice6a;        //xy=297.00396728515625,1431.0001029968262
AudioSynthWaveform       voice6b;        //xy=297.0039520263672,1469.0001487731934
AudioSynthNoiseWhite     voice6n;        //xy=297.0039520263672,1504.0001487731934
AudioSynthWaveform       voice5b;        //xy=305.0039825439453,1206.0000295639038
AudioSynthNoiseWhite     voice5n;        //xy=305.0039825439453,1241.0000295639038
AudioSynthWaveform       voice5a;        //xy=310.0039825439453,1163.0000295639038
AudioSynthWaveform       voice4a;        //xy=354.0039825439453,962.0000524520874
AudioSynthWaveform       voice4b;        //xy=355.0039825439453,1000.0000524520874
AudioSynthNoiseWhite     voice4n;        //xy=355.0039825439453,1035.0000524520874
AudioAnalyzePeak         peak1;          //xy=366.0039291381836,916.0000066757202
AudioSynthWaveform       voice3b;        //xy=397.0039939880371,632.0000762939453
AudioSynthNoiseWhite     voice3n;        //xy=397.0039939880371,667.0000762939453
AudioSynthWaveform       voice3a;        //xy=402.0039939880371,589.0000762939453
AudioSynthWaveform       voice2b;        //xy=433.0039710998535,434.00001430511475
AudioSynthNoiseWhite     voice2n;        //xy=433.0039710998535,469.00001430511475
AudioSynthWaveform       voice2a;        //xy=435.0039710998535,396.00001430511475
AudioMixer4              voice7mix;      //xy=430.00401306152344,1691.0001311302185
AudioSynthWaveform       voice1b;        //xy=438.0039520263672,211.00001335144043
AudioSynthNoiseWhite     voice1n;        //xy=438.0039520263672,255.00001335144043
AudioSynthWaveform       voice1a;        //xy=443.0039520263672,168.00001335144043
AudioMixer4              voice8mix;      //xy=436.0039863586426,1934.0001373291016
AudioMixer4              voice6mix;      //xy=442.0039520263672,1489.0001487731934
AudioMixer4              voice5mix;      //xy=450.0039825439453,1226.0000295639038
AudioMixer4              voice4mix;      //xy=500.0039825439453,1020.0000524520874
AudioMixer4              voice3mix;      //xy=548.0040893554688,629.0001049041748
AudioMixer4              voice2mix;      //xy=565.0039558410645,434.0000219345093
AudioAmplifier           voice8gain; //xy=568.0040435791016,1940.7539234161377
AudioAmplifier           voice7gain; //xy=573.0039520263672,1701.7540092468262
AudioMixer4              voice1mix;      //xy=584.0039520263672,218.00001335144043
AudioAmplifier           voice6gain; //xy=585.00390625,1499.25394821167
AudioAmplifier           voice5gain; //xy=588.0039520263672,1235.5039129257202
AudioAmplifier           voice4gain; //xy=660.0038909912109,1017.2538976669312
AudioAmplifier           voice3gain; //xy=712.0039520263672,651.0039510726929
AudioAmplifier           voice2gain; //xy=716.0039520263672,457.00395011901855
AudioAmplifier           voice1gain;           //xy=730.0039672851562,235.00392627716064
AudioEffectWaveshaper    voice7waveshape; //xy=749.0039367675781,1705.00004196167
AudioEffectWaveshaper    voice8waveshape; //xy=750.0039176940918,1950.000078201294
AudioEffectWaveshaper    voice5waveshape; //xy=767.0038871765137,1228.0000066757202
AudioEffectWaveshaper    voice6waveshape; //xy=767.0039215087891,1508.0000133514404
AudioEffectWaveshaper    voice4waveshape; //xy=829.0039024353027,1011.0000524520874
AudioEffectWaveshaper    voice3waveshape; //xy=880.0039520263672,678.0000438690186
AudioEffectWaveshaper    voice2waveshape; //xy=886.0039367675781,473.99999141693115
AudioEffectWaveshaper    voice1waveshape; //xy=895.0039520263672,252.00002574920654
AudioAmplifier           voice7postgain; //xy=945.00390625,1727.50390625
AudioAmplifier           voice6postgain; //xy=961.00390625,1504.75390625
AudioAmplifier           voice8postgain; //xy=962.00390625,1968.50390625
AudioSynthWaveformDc     voice8filterenv; //xy=969.00390625,2087
AudioAmplifier           voice5postgain; //xy=984.00390625,1247.00390625
AudioSynthWaveformDc     voice8env;      //xy=983.00390625,2026
AudioSynthWaveformDc     voice4filterenv; //xy=991.00390625,1109
AudioSynthWaveformDc     voice5filterenv; //xy=992.00390625,1365
AudioSynthWaveformDc     voice7filterenv; //xy=1001.00390625,1856
AudioSynthWaveformDc     voice4env;      //xy=1005.00390625,1048
AudioSynthWaveformDc     voice6filterenv; //xy=1004.00390625,1619
AudioSynthWaveformDc     voice5env;      //xy=1006.00390625,1304
AudioAmplifier           voice4postgain; //xy=1008.0039367675781,1011.0038976669312
AudioSynthWaveformDc     voice3filterenv; //xy=1012.00390625,861
AudioSynthWaveformDc     voice7env;      //xy=1015.00390625,1795
AudioSynthWaveformDc     voice6env;      //xy=1018.00390625,1558
AudioSynthWaveformDc     voice3env;      //xy=1026.00390625,800
AudioSynthWaveformDc     voice1filterenv; //xy=1043.00390625,385
AudioSynthWaveformDc     voice2filterenv; //xy=1045.00390625,629
AudioAmplifier           voice3postgain; //xy=1052.00390625,724.00390625
AudioSynthWaveformDc     voice2env;      //xy=1059.00390625,568
AudioSynthWaveformDc     voice1env;      //xy=1060.00390625,334
AudioAmplifier           voice2postgain; //xy=1060.00390625,506.00390625
AudioAmplifier           voice1postgain; //xy=1084.0039520263672,280.00390815734863
AudioEffectMultiply      voice8multiply; //xy=1150.00390625,1999
AudioMixer4              voice8filtermodmixer; //xy=1160.00390625,2115
AudioEffectMultiply      voice4multiply; //xy=1172.00390625,1021
AudioEffectMultiply      voice5multiply; //xy=1173.00390625,1277
AudioMixer4              voice4filtermodmixer; //xy=1182.00390625,1137
AudioEffectMultiply      voice7multiply; //xy=1182.00390625,1768
AudioEffectMultiply      voice6multiply; //xy=1185.00390625,1531
AudioMixer4              voice5filtermodmixer; //xy=1190.00390625,1387
AudioMixer4              voice6filtermodmixer; //xy=1195.00390625,1647
AudioMixer4              voice7filtermodmixer; //xy=1199.00390625,1878
AudioMixer4              voice3filtermodmixer; //xy=1210.00390625,883
AudioEffectMultiply      voice3multiply; //xy=1219.00390625,776
AudioEffectMultiply      voice2multiply; //xy=1226.00390625,541
AudioMixer4              voice2filtermodmixer; //xy=1236.00390625,657
AudioMixer4              voice1filtermodmixer; //xy=1240.00390625,417
AudioEffectMultiply      voice1multiply; //xy=1250.00390625,315
AudioFilterStateVariable voice8filter;   //xy=1333.00390625,2022
AudioFilterStateVariable voice5filter;   //xy=1353.00390625,1321
AudioFilterStateVariable voice4filter;   //xy=1355.00390625,1044
AudioFilterStateVariable voice7filter;   //xy=1362.00390625,1812
AudioFilterStateVariable voice6filter;   //xy=1368.00390625,1554
AudioFilterStateVariable voice3filter;   //xy=1373.00390625,817
AudioFilterStateVariable voice2filter;   //xy=1409.00390625,564
AudioFilterStateVariable voice1filter;   //xy=1426.00390625,359
AudioMixer4              last4premix;    //xy=1833.00390625,1294
AudioMixer4              first4premix;   //xy=1834.00390625,1210
AudioMixer4              mainOutMixer;   //xy=2354.00390625,1287
AudioOutputI2S           i2s1;           //xy=2580.00390625,1285
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
AudioConnection          patchCord12(voice7b, 0, voice7mix, 1);
AudioConnection          patchCord13(voice7n, 0, voice7mix, 2);
AudioConnection          patchCord14(voice7a, 0, voice7mix, 0);
AudioConnection          patchCord15(voice8b, 0, voice8mix, 1);
AudioConnection          patchCord16(voice8n, 0, voice8mix, 2);
AudioConnection          patchCord17(voice8a, 0, voice8mix, 0);
AudioConnection          patchCord18(voice6a, 0, voice6mix, 0);
AudioConnection          patchCord19(voice6b, 0, voice6mix, 1);
AudioConnection          patchCord20(voice6n, 0, voice6mix, 2);
AudioConnection          patchCord21(voice5b, 0, voice5mix, 1);
AudioConnection          patchCord22(voice5n, 0, voice5mix, 2);
AudioConnection          patchCord23(voice5a, 0, voice5mix, 0);
AudioConnection          patchCord24(voice4a, 0, voice4mix, 0);
AudioConnection          patchCord25(voice4b, 0, voice4mix, 1);
AudioConnection          patchCord26(voice4n, 0, voice4mix, 2);
AudioConnection          patchCord27(voice3b, 0, voice3mix, 1);
AudioConnection          patchCord28(voice3n, 0, voice3mix, 2);
AudioConnection          patchCord29(voice3a, 0, voice3mix, 0);
AudioConnection          patchCord30(voice2b, 0, voice2mix, 1);
AudioConnection          patchCord31(voice2n, 0, voice2mix, 3);
AudioConnection          patchCord32(voice2a, 0, voice2mix, 0);
AudioConnection          patchCord33(voice7mix, voice7gain);
AudioConnection          patchCord34(voice1b, 0, voice1mix, 1);
AudioConnection          patchCord35(voice1n, 0, voice1mix, 2);
AudioConnection          patchCord36(voice1a, 0, voice1mix, 0);
AudioConnection          patchCord37(voice8mix, voice8gain);
AudioConnection          patchCord38(voice6mix, voice6gain);
AudioConnection          patchCord39(voice5mix, voice5gain);
AudioConnection          patchCord40(voice4mix, voice4gain);
AudioConnection          patchCord41(voice3mix, voice3gain);
AudioConnection          patchCord42(voice2mix, voice2gain);
AudioConnection          patchCord43(voice8gain, voice8waveshape);
AudioConnection          patchCord44(voice7gain, voice7waveshape);
AudioConnection          patchCord45(voice1mix, voice1gain);
AudioConnection          patchCord46(voice6gain, voice6waveshape);
AudioConnection          patchCord47(voice5gain, voice5waveshape);
AudioConnection          patchCord48(voice4gain, voice4waveshape);
AudioConnection          patchCord49(voice3gain, voice3waveshape);
AudioConnection          patchCord50(voice2gain, voice2waveshape);
AudioConnection          patchCord51(voice1gain, voice1waveshape);
AudioConnection          patchCord52(voice7waveshape, voice7postgain);
AudioConnection          patchCord53(voice8waveshape, voice8postgain);
AudioConnection          patchCord54(voice5waveshape, voice5postgain);
AudioConnection          patchCord55(voice6waveshape, voice6postgain);
AudioConnection          patchCord56(voice4waveshape, voice4postgain);
AudioConnection          patchCord57(voice3waveshape, voice3postgain);
AudioConnection          patchCord58(voice2waveshape, voice2postgain);
AudioConnection          patchCord59(voice1waveshape, voice1postgain);
AudioConnection          patchCord60(voice7postgain, 0, voice7multiply, 0);
AudioConnection          patchCord61(voice6postgain, 0, voice6multiply, 0);
AudioConnection          patchCord62(voice8postgain, 0, voice8multiply, 0);
AudioConnection          patchCord63(voice8filterenv, 0, voice8filtermodmixer, 0);
AudioConnection          patchCord64(voice5postgain, 0, voice5multiply, 0);
AudioConnection          patchCord65(voice8env, 0, voice8multiply, 1);
AudioConnection          patchCord66(voice4filterenv, 0, voice4filtermodmixer, 0);
AudioConnection          patchCord67(voice5filterenv, 0, voice5filtermodmixer, 0);
AudioConnection          patchCord68(voice7filterenv, 0, voice7filtermodmixer, 0);
AudioConnection          patchCord69(voice4env, 0, voice4multiply, 1);
AudioConnection          patchCord70(voice6filterenv, 0, voice6filtermodmixer, 0);
AudioConnection          patchCord71(voice5env, 0, voice5multiply, 1);
AudioConnection          patchCord72(voice4postgain, 0, voice4multiply, 0);
AudioConnection          patchCord73(voice3filterenv, 0, voice3filtermodmixer, 0);
AudioConnection          patchCord74(voice7env, 0, voice7multiply, 1);
AudioConnection          patchCord75(voice6env, 0, voice6multiply, 1);
AudioConnection          patchCord76(voice3env, 0, voice3multiply, 1);
AudioConnection          patchCord77(voice1filterenv, 0, voice1filtermodmixer, 0);
AudioConnection          patchCord78(voice2filterenv, 0, voice2filtermodmixer, 0);
AudioConnection          patchCord79(voice3postgain, 0, voice3multiply, 0);
AudioConnection          patchCord80(voice2env, 0, voice2multiply, 1);
AudioConnection          patchCord81(voice1env, 0, voice1multiply, 1);
AudioConnection          patchCord82(voice2postgain, 0, voice2multiply, 0);
AudioConnection          patchCord83(voice1postgain, 0, voice1multiply, 0);
AudioConnection          patchCord84(voice8multiply, 0, voice8filter, 0);
AudioConnection          patchCord85(voice8filtermodmixer, 0, voice8filter, 1);
AudioConnection          patchCord86(voice4multiply, 0, voice4filter, 0);
AudioConnection          patchCord87(voice5multiply, 0, voice5filter, 0);
AudioConnection          patchCord88(voice4filtermodmixer, 0, voice4filter, 1);
AudioConnection          patchCord89(voice7multiply, 0, voice7filter, 0);
AudioConnection          patchCord90(voice6multiply, 0, voice6filter, 0);
AudioConnection          patchCord91(voice5filtermodmixer, 0, voice5filter, 1);
AudioConnection          patchCord92(voice6filtermodmixer, 0, voice6filter, 1);
AudioConnection          patchCord93(voice7filtermodmixer, 0, voice7filter, 1);
AudioConnection          patchCord94(voice3filtermodmixer, 0, voice3filter, 1);
AudioConnection          patchCord95(voice3multiply, 0, voice3filter, 0);
AudioConnection          patchCord96(voice2multiply, 0, voice2filter, 0);
AudioConnection          patchCord97(voice2filtermodmixer, 0, voice2filter, 1);
AudioConnection          patchCord98(voice1filtermodmixer, 0, voice1filter, 1);
AudioConnection          patchCord99(voice1multiply, 0, voice1filter, 0);
AudioConnection          patchCord100(voice8filter, 0, last4premix, 3);
AudioConnection          patchCord101(voice5filter, 0, last4premix, 0);
AudioConnection          patchCord102(voice4filter, 0, first4premix, 3);
AudioConnection          patchCord103(voice7filter, 0, last4premix, 2);
AudioConnection          patchCord104(voice6filter, 0, last4premix, 1);
AudioConnection          patchCord105(voice3filter, 0, first4premix, 2);
AudioConnection          patchCord106(voice2filter, 0, first4premix, 1);
AudioConnection          patchCord107(voice1filter, 0, first4premix, 0);
AudioConnection          patchCord108(last4premix, 0, mainOutMixer, 1);
AudioConnection          patchCord109(first4premix, 0, mainOutMixer, 0);
AudioConnection          patchCord110(mainOutMixer, 0, i2s1, 0);
AudioConnection          patchCord111(mainOutMixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2317.00390625,1054
// GUItool: end automatically generated code



//config variables
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (4)
#define NUM_LED_COLUMNS (4)
#define NUM_LED_ROWS (2)

byte btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
byte btnrowpins[NUM_BTN_ROWS]       = {6, 7, 31,32};

char keys[NUM_BTN_ROWS][NUM_BTN_COLUMNS] = {
    { 'a','b','c','d' },
    { 'e','f','g','h' },
    { '0','1','2','3' },
    { '4','5','6','7' }
};

static const uint8_t ledcolumnpins[NUM_LED_COLUMNS] = {23, 22, 21, 20}; //42,43,44,45 //LED GND 4,3,2,1
static const uint8_t redpins[NUM_LED_ROWS]        = {17, 16}; //22,30,33,36 //Red 1,2,3,4
static const uint8_t greenpins[NUM_LED_ROWS]        = {15, 14}; 

Keypad keypad = Keypad( makeKeymap(keys), btnrowpins, btncolumnpins, NUM_BTN_ROWS, NUM_BTN_COLUMNS );

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


//float WAVESHAPE_YAMAHA[17] = {
//    -1.0000,   -0.4 ,  -0.341,   -0.754,   -0.875,   -0.361,
//   -0.672,   -0.165,         0,    0.165,    0.362,    0.361,
//    0.675,    0.8154,    0.141,    0.977,    1.0000
//};

float WAVESHAPE_YAMAHA[17] = {
       -1.0000,   -0.9775 ,  -0.9141,   -0.8154,   -0.6875,   -0.5361,
   -0.3672,   -0.1865,         0,    0.1865,    0.3672,    0.5361,
    0.6875,    0.8154,    0.9141,    0.9775,    1.0000,
};

//float WAVESHAPE_YAMAHA[17] = {
//  -1.00000,-0.87500,-0.75000,-0.62500,-0.50000,-0.37500,-0.25000,-0.12500
//, 0.00000, 0.12500, 0.25000, 0.37500, 0.50000, 0.62500, 0.75000, 0.87500
//, 1.00000
//
//};

float pregain;
float postgain;

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
  voice1a.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice1b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 2
  voice2a.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice2b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 3
  voice3a.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice3b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 4
  voice4a.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice4b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 5
  voice5a.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice5b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 6
  voice6a.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice6b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 7
  voice7a.begin(.3,440,WAVEFORM_SAWTOOTH);
  voice7b.begin(.3,440,WAVEFORM_SAWTOOTH);
  //Voice 8
  voice8a.begin(.3,440,WAVEFORM_SAWTOOTH);
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

  voice1gain.gain(1);
  voice2gain.gain(1);
  voice3gain.gain(1);
  voice4gain.gain(1);
  voice5gain.gain(1);
  voice6gain.gain(1);
  voice7gain.gain(1);
  voice8gain.gain(1);
  
  voice1waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice2waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice3waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice4waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice5waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice6waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice7waveshape.shape(WAVESHAPE_YAMAHA, 17);
  voice8waveshape.shape(WAVESHAPE_YAMAHA, 17);

  voice1postgain.gain(1);
  voice2postgain.gain(1);
  voice3postgain.gain(1);
  voice4postgain.gain(1);
  voice5postgain.gain(1);
  voice6postgain.gain(1);
  voice7postgain.gain(1);
  voice8postgain.gain(1);

  pregain = 1;
  postgain = 1;
  
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

  vcoOneLevel = 0;
  vcoTwoLevel = 1;
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
  deTuneLfo = 1;
  
  lfoenvelope.amplitude(1);
  voiceBPulse = true;

  attackTimeFilter = 0;
  decayTimeFilter = 0;
  sustainLevelFilter = 0.5;
  releaseTimeFilter = 500;

  attackTime = 0;
  decayTime = 250;
  sustainLevel= 1;
  releaseTime= 0;

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

//  // LED column lines
//  for(i = 0; i < NUM_LED_COLUMNS; i++)
//  {
//    pinMode(ledcolumnpins[i], OUTPUT);
//
//    // with nothing selected by default
//    digitalWrite(ledcolumnpins[i], HIGH);
//  }
//
//    // LED red row lines
//  for(i = 0; i < NUM_LED_ROWS; i++)
//  {
//    pinMode(redpins[i], OUTPUT);
//
//    // with nothing driven by default
//    digitalWrite(redpins[i], LOW);
//  }
//
//  
//  // LED green row lines
//  for(i = 0; i < NUM_LED_ROWS; i++)
//  {
//    pinMode(greenpins[i], OUTPUT);
//
//    // with nothing driven by default
//    digitalWrite(greenpins[i], LOW);
//  }

}

static void scanLEDs()
{

  uint8_t val;
  uint8_t i;
  static uint8_t current;
  uint8_t index = 0; 
  
  // Select a column
  digitalWrite(ledcolumnpins[current], LOW);

  // write the row pins
  for(i = 0; i < NUM_LED_ROWS; i++)
  {
    index = i*NUM_LED_COLUMNS+current;
    //check if this is the activeStep
    if(index == activeStep){
  
      //digitalWrite(redpins[i],HIGH);
      
//        Serial.println("active step");
//        Serial.println(index);
//        Serial.println("current");
//        Serial.println(current);
      
    }
  //otherwise check if this step has a note
  
    else {
      for(int j = 0; j < 8; j++){
        if(steps[index][j] == 1)
        {
//                Serial.println("mark step");
//                Serial.println(index);
//                Serial.println(i);
                //digitalWrite(greenpins[i], HIGH);
        }
      }
    }
  }

  delay(1);

  digitalWrite(ledcolumnpins[current], HIGH);

  for(i = 0; i < NUM_LED_ROWS; i++)
  {
    digitalWrite(redpins[i], LOW);
    digitalWrite(greenpins[i], LOW);
  }

  // Move on to the next column
  current++;
  if (current >= NUM_LED_COLUMNS)
  {
    current = 0;
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

void scanButtons()
{

  String msg;
  char key;
  if (keypad.getKeys())
    {
        for (int i=0; i<LIST_MAX; i++)   // Scan the whole key list.
        {
            if ( keypad.key[i].stateChanged )   // Only find keys that have changed state.
            {
                key = keypad.key[i].kchar;
                switch (keypad.key[i].kstate) {  // Report active key state : IDLE, PRESSED, HOLD, or RELEASED
                    case PRESSED:
                    msg = " PRESSED.";
                    if (isdigit(key)){
                      //convert to int
                      int keyNum = key -'0';
                      Serial.println("buttonUpdate");
                      Serial.println(keyNum);
                      buttonHeld[keyNum]= 1;  
                      btnState[keyNum]=LOW;
                      buttonUpdate(keyNum);
                    }
                    else{
                      //convert letter to int
                      int stepNum = key - 'a';
                      //Serial.println("corresponding step");
                      //Serial.println(stepNum);
                      for(int k = 0; k< 8; k++){
                        Serial.println(buttonHeld[k]);
                        if(buttonHeld[k] == 1){
                          Serial.println("sequencer input");
                          Serial.println("at step");
                          Serial.println(stepNum);
                          steps[stepNum][k] = 1; 
                        }
                      }
                    }
                break;
                    case RELEASED:
                    msg = " RELEASED.";

                    if (isdigit(key)){
                      //convert to int
                      int keyNum = key -'0';
                      Serial.println("buttonUpdate");
                      Serial.println(keyNum);
                      buttonHeld[keyNum] = 0;
                      btnState[keyNum]= HIGH;
                      buttonUpdate(keyNum);
                    }
                break;
                    }
                Serial.print("Key ");
                Serial.print(key);
                Serial.println(msg);
            }
        }
    }
}  

void advanceSequencer(){

  for(int index = 0; index< 8; index++){ 
    if(!buttonHeld[index]){
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
            //buttonUpdate(index);
      }
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
    
    scanButtons();
    //scanLEDs();
    
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

  //knobs
  analogValues[0] = getSmooth(A14);
  analogValues[1] = getSmooth(A15);
  
  for(int i = 0; i < 2; i ++){

    if(i == 8 || i == 2){
      changeThresh = 250;
    }else if(i == 14)
      changeThresh = 200;
    else{
      changeThresh = 5;
    }
    if (abs(analogValues[i] - analogValuesLag[i]) > changeThresh || firstRunRead){
      //vcoOne
      if(i == 4){
        //oct
        octOneIndex = (analogValues[i]/204)+1;
        if(octOneIndex < 6){
          vcoOneOct = octArray[octOneIndex];
        }
      }
      if(i == 8){
        //shape
        waveShapeOneIndex = analogValues[i]/255;
        if(waveShapeOneIndex < 4){
          voice1a.begin(waveShapes[waveShapeOneIndex]);
          voice2a.begin(waveShapes[waveShapeOneIndex]);
          voice3a.begin(waveShapes[waveShapeOneIndex]);
          voice4a.begin(waveShapes[waveShapeOneIndex]);
          voice5a.begin(waveShapes[waveShapeOneIndex]);
          voice6a.begin(waveShapes[waveShapeOneIndex]);
          voice7a.begin(waveShapes[waveShapeOneIndex]);
          voice8a.begin(waveShapes[waveShapeOneIndex]);
        }
      }
      if(i == 0){
        //mix
        vcoOneLevel = (analogValues[i])/1023;
        vcoTwoLevel = 1 - (analogValues[i])/1023;
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
      }
      //vcoTwo
      if(i == 10){
        //oct
        octTwoIndex = (analogValues[i]/204)+1;
        if(octTwoIndex < 6){
          vcoTwoOct = octArray[octTwoIndex];
        }

      }
      if(i == 9){
        //shape
        waveShapeTwoIndex = analogValues[i]/255;
        if(waveShapeTwoIndex < 4){
          if(waveShapeTwoIndex == 3){
            voiceBPulse = true;
          }else{
            voiceBPulse = false;
          }          
          voice1b.begin(waveShapes[waveShapeTwoIndex]);
          voice2b.begin(waveShapes[waveShapeTwoIndex]);
          voice3b.begin(waveShapes[waveShapeTwoIndex]);
          voice4b.begin(waveShapes[waveShapeTwoIndex]);
          voice5b.begin(waveShapes[waveShapeTwoIndex]);
          voice6b.begin(waveShapes[waveShapeTwoIndex]);
          voice7b.begin(waveShapes[waveShapeTwoIndex]);
          voice8b.begin(waveShapes[waveShapeTwoIndex]);
        }
      }
      if(i == 2){
        //detune
        deTune = analogValues[i];
        deTune = mapfloat(deTune, 0, 1023, .875, 1.125);
      }
      //LFO
      if(i == 7){
        //freq
        lfo.frequency(analogValues[i]/50);
      }
      if(i == 14){
        //shape
        lfoWaveShapeIndex = analogValues[i]/204.6;
        if(lfoWaveShapeIndex < 5){
          lfo.begin(lfoWaveShapes[lfoWaveShapeIndex]);
          Serial.println(lfoWaveShapeIndex);
        }
      }
      //noise
      if(i == 5){
        voice1n.amplitude(analogValues[i]/3096);
        voice2n.amplitude(analogValues[i]/3096);
        voice3n.amplitude(analogValues[i]/3096);
        voice4n.amplitude(analogValues[i]/3096);
        voice5n.amplitude(analogValues[i]/3096);
        voice6n.amplitude(analogValues[i]/3096);
        voice7n.amplitude(analogValues[i]/3096);
        voice8n.amplitude(analogValues[i]/3096);
      }
      //Filter
      if(i == 3){
        //frequency
        voice1filter.frequency(analogValues[i]*10);
        voice2filter.frequency(analogValues[i]*10);
        voice3filter.frequency(analogValues[i]*10);
        voice4filter.frequency(analogValues[i]*10);
        voice5filter.frequency(analogValues[i]*10);
        voice6filter.frequency(analogValues[i]*10);
        voice7filter.frequency(analogValues[i]*10);
        voice8filter.frequency(analogValues[i]*10);
      }
      if(i == 6){
        //resonance
        voice1filter.resonance((analogValues[i]/204)+.9);
        voice2filter.resonance((analogValues[i]/204)+.9);
        voice3filter.resonance((analogValues[i]/204)+.9);
        voice4filter.resonance((analogValues[i]/204)+.9);
        voice5filter.resonance((analogValues[i]/204)+.9);
        voice6filter.resonance((analogValues[i]/204)+.9);
        voice7filter.resonance((analogValues[i]/204)+.9);
        voice8filter.resonance((analogValues[i]/204)+.9);
      }
      if(i == 15){
        //lfo Mod
        voice1filtermodmixer.gain(1, analogValues[i]/1023);
        voice2filtermodmixer.gain(1, analogValues[i]/1023);
        voice3filtermodmixer.gain(1, analogValues[i]/1023);
        voice4filtermodmixer.gain(1, analogValues[i]/1023);
        voice5filtermodmixer.gain(1, analogValues[i]/1023);
        voice6filtermodmixer.gain(1, analogValues[i]/1023);
        voice7filtermodmixer.gain(1, analogValues[i]/1023);
        voice8filtermodmixer.gain(1, analogValues[i]/1023);
      }
      if(i == 13){
        //env Mod
        voice1filtermodmixer.gain(0, analogValues[i]/1023);
        voice2filtermodmixer.gain(0, analogValues[i]/1023);
        voice3filtermodmixer.gain(0, analogValues[i]/1023);
        voice4filtermodmixer.gain(0, analogValues[i]/1023);
        voice5filtermodmixer.gain(0, analogValues[i]/1023);
        voice6filtermodmixer.gain(0, analogValues[i]/1023);
        voice7filtermodmixer.gain(0, analogValues[i]/1023);
        voice8filtermodmixer.gain(0, analogValues[i]/1023);
      }
      //delay
//      if(i == 11){
//        //time
//        //delay1.delay(0, analogValues[i]/2.4);
//      }
//      if(i == 7){
//        //feedback
//        mainOutMixer.gain(3,analogValues[i]/1023);
//      }
      //pulseWidth
      if(i == 16){
        tempPulseWidth = 1 - (analogValues[i]/1023);
        tempDetuneMod = analogValues[i]/2046;

      }
      //waveshape drive
      if(i == 1){
        pregain = analogValues[i]/1023*0.8 + 0,1;
        //Serial.println("pregain:");
        //Serial.println(pregain);
        postgain = 1/pregain;
        //Serial.println("postgain:");
        //Serial.println(postgain);
        
        voice1gain.gain(pregain);
        voice2gain.gain(pregain);
        voice3gain.gain(pregain);
        voice4gain.gain(pregain);
        voice5gain.gain(pregain);
        voice6gain.gain(pregain);
        voice7gain.gain(pregain);
        voice8gain.gain(pregain);

        voice1postgain.gain(postgain);
        voice2postgain.gain(postgain);
        voice3postgain.gain(postgain);
        voice4postgain.gain(postgain);
        voice5postgain.gain(postgain);
        voice6postgain.gain(postgain);
        voice7postgain.gain(postgain);
        voice8postgain.gain(postgain);
      }
      analogValuesLag[i] = analogValues[i];   
    }      
  }
  //ExtraAnalogIn
//  for(int i=0; i<5; i++){
//    extraAnalogValues[i] = getSmooth(extraAnalogPins[i]);
//    if(i == 0){
//      extraChangeThresh = 144;
//    }else{
//      extraChangeThresh = 1;
//    }
//    if (abs(extraAnalogValues[i] - extraAnalogValuesLag[i]) > extraChangeThresh || firstRunRead){
//      if(i == 0){
//        //key
//        colorIndex = extraAnalogValues[i]/146;
//        if(colorIndex < 7){
//          keyIndex = colorIndex;
//          redLevel = redLevelArray[colorIndex];
//          blueLevel = blueLevelArray[colorIndex];
//          greenLevel = greenLevelArray[colorIndex];
//        }
//      }
//      if(i == 1){
//        //attack
//        if(firstRunRead){
//          attackTimeFilter = extraAnalogValues[i]*2;
//          attackTime = extraAnalogValues[i]*2;
//        }
//        if(envelopeFilter == LOW){
//          attackTimeFilter = extraAnalogValues[i]*2;
//        }else{
//          attackTime = extraAnalogValues[i]*2;
//        }
//      }
//      if(i == 2){
//        //decay
//        if(firstRunRead){
//          decayTimeFilter = extraAnalogValues[i];
//          decayTime = extraAnalogValues[i];
//        }
//        if(envelopeFilter == LOW){
//          decayTimeFilter = extraAnalogValues[i];
//        }else{
//          decayTime = extraAnalogValues[i];
//        }
//      }
//      if(i == 3){
//        //sustain
//        if(firstRunRead){
//          sustainLevelFilter = extraAnalogValues[i];
//          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
//          sustainLevel = extraAnalogValues[i]/1023;
//        }
//        if(envelopeFilter == LOW){
//          sustainLevelFilter = extraAnalogValues[i];
//          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
//        }else{
//          sustainLevel = extraAnalogValues[i]/1023;
//        }
//      }
//      if(i == 4){
//        //release
//        if(firstRunRead){
//          releaseTimeFilter = extraAnalogValues[i]*2;
//          releaseTime = extraAnalogValues[i]*2;
//        }
//        if(envelopeFilter == LOW){
//          releaseTimeFilter = extraAnalogValues[i]*2;
//        }else{
//          releaseTime = extraAnalogValues[i]*2;
//        }
//      }
//      extraAnalogValuesLag[i] = extraAnalogValues[i];
//    }
//  }

  //LFO Peak
  if(peak1.available()){
    tempPeak = peak1.read();
    //Serial.println("reading peak value");
  }
  if(voiceBPulse){
    voice1b.pulseWidth((tempPeak/2) + tempPulseWidth);
    voice2b.pulseWidth((tempPeak/2) + tempPulseWidth);
    voice3b.pulseWidth((tempPeak/2) + tempPulseWidth);
    voice4b.pulseWidth((tempPeak/2) + tempPulseWidth);
    voice5b.pulseWidth((tempPeak/2) + tempPulseWidth);
    voice6b.pulseWidth((tempPeak/2) + tempPulseWidth);
    voice7b.pulseWidth((tempPeak/2) + tempPulseWidth);
    voice8b.pulseWidth((tempPeak/2) + tempPulseWidth);
  }else{
    deTuneLfo = ((tempPeak) * tempDetuneMod + 1);
  }

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




