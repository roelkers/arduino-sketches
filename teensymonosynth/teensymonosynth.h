#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformDc     lfoenvelope;          //xy=589.047534942627,966.6665487289429
AudioSynthWaveform       lfo;            //xy=677.4761581420898,1172.523769378662
AudioMixer4              mixer1;         //xy=720.9047355651855,1027.666706085205
AudioAnalyzePeak         peak1;          //xy=949.0476112365723,890.8095207214355
AudioSynthWaveform       voice1a;        //xy=1263.6190299987793,206.66663551330566
AudioSynthWaveform       voice1b;        //xy=1263.6190299987793,445.66663551330566
AudioSynthNoiseWhite     voice1n;        //xy=1261.6190299987793,293.66663551330566
AudioSynthWaveformDc     voice1filterenv; //xy=1387.6190299987793,385.66663551330566
AudioMixer4              voice1mix;      //xy=1403.6190299987793,269.66663551330566
AudioSynthWaveformDc     voice1env;      //xy=1404.6190299987793,334.66663551330566
AudioEffectMultiply      voice1multiply; //xy=1567.6190299987793,307.66663551330566
AudioMixer4              voice1filtermodmixer; //xy=1584.6190299987793,417.66663551330566
AudioFilterStateVariable voice1filter;   //xy=1770.6190299987793,359.66663551330566
AudioMixer4              mainOutMixer;   //xy=2698.6190299987793,1287.6666355133057
AudioOutputI2S           i2s1;           //xy=2924.6190299987793,1285.6666355133057
AudioConnection          patchCord1(lfoenvelope, 0, mixer1, 0);
AudioConnection          patchCord2(lfo, 0, voice1filtermodmixer, 1);
AudioConnection          patchCord10(lfo, 0, mixer1, 1);
AudioConnection          patchCord11(mixer1, peak1);
AudioConnection          patchCord30(voice1b, 0, voice1mix, 1);
AudioConnection          patchCord31(voice1n, 0, voice1mix, 2);
AudioConnection          patchCord34(voice1a, 0, voice1mix, 0);
AudioConnection          patchCord54(voice1filterenv, 0, voice1filtermodmixer, 0);
AudioConnection          patchCord55(voice2filterenv, 0, voice2filtermodmixer, 0);
AudioConnection          patchCord56(voice1mix, 0, voice1multiply, 0);
AudioConnection          patchCord58(voice1env, 0, voice1multiply, 1);
AudioConnection          patchCord72(voice1multiply, 0, voice1filter, 0);
AudioConnection          patchCord75(voice1filtermodmixer, 0, voice1filter, 1);
AudioConnection          patchCord83(voice1filter, 0, mainOutMixer, 0);
AudioConnection          patchCord87(mainOutMixer, 0, i2s1, 0);
AudioConnection          patchCord88(mainOutMixer, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=2661.6190299987793,1054.6666355133057
// GUItool: end automatically generated code



#include <Bounce.h>

//Buttons
int notePins[8] = {0,1,2,8,16,17,20,21};

Bounce noteBounce[] = {
  Bounce(0,10),
  Bounce(1,10),
  Bounce(2,10),
  Bounce(8,10),
  Bounce(16,10),
  Bounce(17,10),
  Bounce(20,10),
  Bounce(21,10),

};

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

int btnState[8];
int prevBtnState[8];


//Analog Inputs
float analogValues[16];
float analogValuesLag[16];

int analogPins[3] = {A13,A18,A19};
float analogValuesLag[5];
int changeThresh;

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

//Note Timing
bool noteTrigFlag[8];
unsigned long attackWait[8];

bool firstRunRead;

void setup() {
  AudioMemory(160);
  Serial.begin(115200);
  sgtl5000_1.enable();
  sgtl5000_1.volume(.7);

  colorIndex = 0;
  keyIndex = 0;

  //Voice 1
  voice1a.begin(1,440,WAVEFORM_SQUARE);
  voice1b.begin(1,440,WAVEFORM_SAWTOOTH);

  mainOutMixer.gain(3,0);

  //LFO
  lfo.begin(1,3,WAVEFORM_SINE);

  vcoOneOct = 1;
  vcoTwoOct = 1;
  deTune = 1;
  mainOutMixer.gain(0,.5);
  lfoenvelope.amplitude(1);
  voiceBPulse = false;

  firstRunRead = true;


  pinMode(A18, INPUT);
  pinMode(A19, INPUT);
  pinMode(A20, INPUT);

  pinMode(32, INPUT_PULLUP);
  pinMode(33, OUTPUT);

  for(int i=0; i<8; i++){
    pinMode(notePins[i], INPUT_PULLUP);
    digitalWrite(notePins[i], HIGH);
    //audio startup
    if(i < 4){
      voice1env.amplitude(.5,1);
      voice1a.frequency(noteFreq[0][i]);
      voice1b.frequency(noteFreq[0][i]+3);
      delay(200);
      voice1env.amplitude(0,0);
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

void loop() {

  //Volume

  sgtl5000_1.volume(mainVolume);
  tempLineOutLevel = analogRead(A1);
  tempLineOutLevel = map(tempLineOutLevel, 0, 1023, 31, 13);
  sgtl5000_1.lineOutLevel(tempLineOutLevel);

  //notes
  for(int i=0; i<8; i++){
    if(i == 0){
      voice1a.frequency((noteFreq[keyIndex][i]/4)*vcoOneOct);
      voice1b.frequency(((noteFreq[keyIndex][i]/4*vcoTwoOct) * deTune) * deTuneLfo);
    }
    
    btnState[i] = digitalRead(notePins[i]);
    if (noteBounce[i].update()){
      Serial.println(noteFreq[keyIndex][i]);
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
    }
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
    }
    prevBtnState[i] = btnState[i];
  }

  //knobs
  for(int i = 0; i < 2; i ++){
    analogValues[i] = getSmooth(analogPins[i]);

    /*if(i == 8 || i == 2){
      changeThresh = 250;
    }else if(i == 14)
      changeThresh = 200;
    else{
      changeThresh = 5;
    }*/
	changeThresh = 5;
	
    if (abs(analogValues[i] - analogValuesLag[i]) > changeThresh || firstRunRead){
      //vcoOne
      if(i == 0){
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
      if(i == 4){
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
      if(i == 12){
        //oct
        octTwoIndex = (analogValues[i]/204)+1;
        if(octTwoIndex < 6){
          vcoTwoOct = octArray[octTwoIndex];
        }

      }
      if(i == 2){
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
      if(i == 10){
        //detune
        deTune = analogValues[i];
        deTune = mapfloat(deTune, 0, 1023, .875, 1.125);
      }
      //LFO
      if(i == 6){
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
      if(i == 1){
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
      if(i == 9){
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
      if(i == 5){
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
      if(i == 13){
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
      if(i == 3){
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
      if(i == 7){
        //feedback
        mainOutMixer.gain(3,analogValues[i]/1023);
      }
      //pulseWidth
      if(i == 15){
        tempPulseWidth = 1 - (analogValues[i]/1023);
        tempDetuneMod = analogValues[i]/2046;
      }
      analogValuesLag[i] = analogValues[i];   
    }      
  }
  //ExtraAnalogIn
  for(int i=0; i<5; i++){
    extraAnalogValues[i] = getSmooth(extraAnalogPins[i]);
    if(i == 0){
      extraChangeThresh = 144;
    }else{
      extraChangeThresh = 1;
    }
    if (abs(extraAnalogValues[i] - extraAnalogValuesLag[i]) > extraChangeThresh || firstRunRead){
      if(i == 0){
        //key
        colorIndex = extraAnalogValues[i]/146;
        if(colorIndex < 7){
          keyIndex = colorIndex;
          redLevel = redLevelArray[colorIndex];
          blueLevel = blueLevelArray[colorIndex];
          greenLevel = greenLevelArray[colorIndex];
        }
      }
      if(i == 1){
        //attack
        if(firstRunRead){
          attackTimeFilter = extraAnalogValues[i]*2;
          attackTime = extraAnalogValues[i]*2;
        }
        if(envelopeFilter == LOW){
          attackTimeFilter = extraAnalogValues[i]*2;
        }else{
          attackTime = extraAnalogValues[i]*2;
        }
      }
      if(i == 2){
        //decay
        if(firstRunRead){
          decayTimeFilter = extraAnalogValues[i];
          decayTime = extraAnalogValues[i];
        }
        if(envelopeFilter == LOW){
          decayTimeFilter = extraAnalogValues[i];
        }else{
          decayTime = extraAnalogValues[i];
        }
      }
      if(i == 3){
        //sustain
        if(firstRunRead){
          sustainLevelFilter = extraAnalogValues[i];
          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
          sustainLevel = extraAnalogValues[i]/1023;
        }
        if(envelopeFilter == LOW){
          sustainLevelFilter = extraAnalogValues[i];
          sustainLevelFilter = mapfloat(sustainLevelFilter, 0, 1023, -1, 1);
        }else{
          sustainLevel = extraAnalogValues[i]/1023;
        }
      }
      if(i == 4){
        //release
        if(firstRunRead){
          releaseTimeFilter = extraAnalogValues[i]*2;
          releaseTime = extraAnalogValues[i]*2;
        }
        if(envelopeFilter == LOW){
          releaseTimeFilter = extraAnalogValues[i]*2;
        }else{
          releaseTime = extraAnalogValues[i]*2;
        }
      }
      extraAnalogValuesLag[i] = extraAnalogValues[i];
    }
  }

  //LFO Peak
  if(peak1.available()){
    tempPeak = peak1.read();
  }
  voice1a.pulseWidth((tempPeak/2) + tempPulseWidth);
  voice2a.pulseWidth((tempPeak/2) + tempPulseWidth);
  voice3a.pulseWidth((tempPeak/2) + tempPulseWidth);
  voice4a.pulseWidth((tempPeak/2) + tempPulseWidth);
  voice5a.pulseWidth((tempPeak/2) + tempPulseWidth);
  voice6a.pulseWidth((tempPeak/2) + tempPulseWidth);
  voice7a.pulseWidth((tempPeak/2) + tempPulseWidth);
  voice8a.pulseWidth((tempPeak/2) + tempPulseWidth);

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
    //deTuneLfo = ((tempPeak) * tempDetuneMod + 1);
    deTuneLfo = 1;
	//Serial.println(deTuneLfo);
  }
  firstRunRead = false;
}





