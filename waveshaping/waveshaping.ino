#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       waveform1;      //xy=209,83
AudioEffectWaveshaper    waveshape1;     //xy=629,110
AudioOutputI2S           i2s1;           //xy=972,141
AudioConnection          patchCord1(waveform1, waveshape1);
AudioConnection          patchCord2(waveshape1, 0, i2s1, 0);
AudioConnection          patchCord3(waveshape1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=558,228
// GUItool: end automatically generated code

float WAVESHAPE_EXAMPLE[17] = {
  -0.588,
  -0.579,
  -0.549,
  -0.488,
  -0.396,
  -0.320,
  -0.228,
  -0.122,
  0,
  0.122,
  0.228,
  0.320,
  0.396,
  0.488,
  0.549,
  0.579,
  0.588
};

float WAVESHAPE_EXAMPLE_2[17] = {
   -0.84147,  -0.76754,  -0.68164,  -0.58510,  -0.47943,  -0.36627,  -0.24740,  -0.12467,
   0.00000,   0.12467,   0.24740,   0.36627,   0.47943,   0.58510,   0.68164,   0.76754
   ,0.84147

};

float WAVESHAPE_QUADRATIC[17] = {
  1.00000 ,  0.76562 ,  0.56250 ,  0.39062  , 0.25000 ,  0.14062  , 0.06250 ,  0.01562,
   0.00000,   0.01562,   0.06250,   0.14062 ,  0.25000,   0.39062 ,  0.56250,   0.76562,
   1.00000,

};


float WAVESHAPE_CUBIC[17] = {
  -1.00000,  -0.66992,  -0.42188,  -0.24414,  -0.12500,  -0.05273,  -0.01562,  -0.00195,
   0.00000,   0.00195,   0.01562,   0.05273,   0.12500,   0.24414,   0.42188,   0.66992,
   1.00000
};

float WAVESHAPE_5TH_ORDER[17] = {
  -1.00000,-0.51291,-0.23730,-0.09537,-0.03125,-0.00742,-0.00098,-0.00003
, 0.00000, 0.00003, 0.00098, 0.00742, 0.03125, 0.09537, 0.23730, 0.51291
, 1.00000
};

float WAVESHAPE_ATAN[17] = {
   -0.78540,  -0.71883,  -0.64350,  -0.55860,  -0.46365,  -0.35877,  -0.24498,  -0.12435,
   0.00000,   0.12435,   0.24498,   0.35877,   0.46365,   0.55860,   0.64350,   0.71883,
   0.78540
};

float WAVESHAPE_INPUT[17] = {

  -1.00000,-0.87500,-0.75000,-0.62500,-0.50000,-0.37500,-0.25000,-0.12500
, 0.00000, 0.12500, 0.25000, 0.37500, 0.50000, 0.62500, 0.75000, 0.87500
, 1.00000

};

float nextRead = 0;

void setup() {
  Serial.begin(9600);
  AudioMemory(40);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.5);
  waveform1.begin(1.0, 400.0, WAVEFORM_SINE);
  waveshape1.shape(WAVESHAPE_ATAN, 17);
}

float getSmooth(){
  float vals[100]; //array that stores 100 readings.
  for(int i = 0; i < 100; i++){
    vals[i] = analogRead(A14); //takes 5 readings.
  }
  float smooth = (vals[0] + vals[1] + vals[2] + vals[3] + vals[4]) / 5;
  return smooth;
}

void loop() {
  float WAVESHAPE_NEW[17];

  if(millis() > nextRead){
    Serial.println("nextRead");
    
    nextRead = millis() + 3000;
    
    float knob = getSmooth();
    
    float distort_exponent = map(knob,1015,1023,0,1);
    
    Serial.println(distort_exponent);    
    for(int i = 0; i < 18; i++){
      WAVESHAPE_NEW[i] = pow(WAVESHAPE_INPUT[i],distort_exponent);
    }
  
    waveshape1.shape(WAVESHAPE_NEW,17);
  
  }
}
