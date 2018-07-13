/******************************************************************************
red-plus-buttons.ino
Byron Jacquot @ SparkFun Electronics
1/6/2015

Example to drive the red LEDs and scan the buttons of the RGB button pad.

Exercise 2 in a series of 3.
https://learn.sparkfun.com/tutorials/button-pad-hookup-guide/exercise-2-monochrome-plus-buttons

Development environment specifics:
Developed in Arduino 1.6.5
For an Arduino Mega 2560

This code is released under the [MIT License](http://opensource.org/licenses/MIT).

Distributed as-is; no warranty is given.
******************************************************************************/    

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveform       lfo;            //xy=677.4761581420898,1172.523769378662
AudioAnalyzePeak         peak1;          //xy=949.0476112365723,890.8095207214355
AudioSynthWaveformDc     voice1env;      //xy=104.8900146484375,251.92996215820312
AudioSynthWaveform       waveform2;      //xy=106.3699951171875,161.37001037597656
AudioSynthWaveform       waveform1;      //xy=106.72998046875,104.54998779296875
AudioMixer4              mixer2;         //xy=302.14996337890625,132.9499969482422
AudioEffectMultiply      multiply1;      //xy=498.8899841308594,149.1799774169922
AudioMixer4              mixer1;         //xy=657.72998046875,157.54998779296875
AudioOutputI2S           i2s1;           //xy=869.72998046875,162.54998779296875
AudioConnection          patchCord1(voice1env, 0, multiply1, 1);
AudioConnection          patchCord2(waveform2, 0, mixer2, 1);
AudioConnection          patchCord3(waveform1, 0, mixer2, 0);
AudioConnection          patchCord4(mixer2, 0, multiply1, 0);
AudioConnection          patchCord5(multiply1, 0, mixer1, 0);
AudioConnection          patchCord6(mixer1, 0, i2s1, 0);
AudioConnection          patchCord7(lfo, 0, peak1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=455.72998046875,249.54998779296875
// GUItool: end automatically generated code

//config variables
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (2)

#define MAX_DEBOUNCE (3)

// Global variables
//static bool LED_buffer[NUM_LED_COLUMNS][NUM_LED_ROWS];

static const uint8_t btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
static const uint8_t btnrowpins[NUM_BTN_ROWS]       = {6, 7};

static int8_t debounce_count[NUM_BTN_COLUMNS][NUM_BTN_ROWS];

float notes[] = {
  261.6255653006,
  293.6647679174,
  329.6275569129,
  349.2282314330,
  391.9954359817,
  440.0000000000,
  493.8833012561,
  513.23
  };

// save button state
uint8_t prevBtnState;
uint8_t btnState;

uint8_t noteTrigFlag[8];

//ADSR
int attackTime;
int decayTime;
float sustainLevel;
int releaseTime;

int attackWait[8];

//Octaves
int vcoOneOct;
int vcoTwoOct;

//LFO
float tempDetuneMod;
float tempPeak;
float deTune;
float deTuneLfo;
float lfoFrequency;

float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

static void setuppins()
{
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
      
      btnState = digitalRead(btnrowpins[j]);

      //Serial.println(prevBtnState);
      
      if (btnState == LOW)
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
            
            Serial.println("btnState:");
            Serial.println(btnState);
            Serial.println("previous:");
            Serial.println(prevBtnState);
            
            // Do whatever you want to with the button press here:
            if (btnState == LOW && prevBtnState == HIGH){

              Serial.println("note triggered");
              Serial.println("deTuneLfo");
              Serial.println(deTuneLfo);
        
              Serial.println("lfoFrequency");
              Serial.println(lfoFrequency);

              Serial.println("tempDetuneMod");
              Serial.println(tempDetuneMod);
        
              
              waveform1.frequency((notes[index]/4)*vcoOneOct);
			        waveform2.frequency((((notes[index]/4)*vcoTwoOct) * deTune) * deTuneLfo);
			  
              voice1env.amplitude(1,attackTime);
              //voice1filterenv.amplitude(1,attackTimeFilter);
              noteTrigFlag[index] = true;
              attackWait[index] = millis();
              
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
            // If you want to do something when a key is released, do it here:
              noteTrigFlag[index] = false;
              voice1env.amplitude(0,releaseTime);
              //voice1filterenv.amplitude(-1, releaseTimeFilter);
            
          }
        }
      }

      if(btnState == LOW){
        if(millis() - attackWait[index] > attackTime && noteTrigFlag[index]){
         voice1env.amplitude(sustainLevel,decayTime);
        }
        //if(millis() - attackWait[index] > attackTimeFilter && noteTrigFlag[index]){
        //  voice1filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
        //}
      }

      prevBtnState = btnState;
  
    }// for j = 0 to 3;

    delay(1);
  
    digitalWrite(btncolumnpins[i], HIGH);

  }
//  digitalWrite(ledcolumnpins[current], HIGH);

}

void setup()
{

  Serial.begin(9600);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);

  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.75);
  waveform1.frequency(50);
  
  waveform2.begin(WAVEFORM_SAWTOOTH);
  waveform2.amplitude(0.75);
  waveform2.frequency(50);
  
  mixer2.gain(0,0.5);
  mixer2.gain(1,0.5);
	
  voice1env.amplitude(0);
  mixer1.gain(0,1);
  
  attackTime = 550;
  decayTime = 150;
  sustainLevel = 1;
  releaseTime = 550;
  
  vcoOneOct = 1;
  vcoTwoOct = 2;
  
    //LFO
  lfo.begin(1,3,WAVEFORM_SINE);
  deTuneLfo = 1;
  deTune = 1;
  lfoFrequency = 1;
  
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.print("Starting Setup...");

  // setup hardware
  setuppins();

  Serial.println("Setup Complete.");

}

void loop() {
  // put your main code here, to run repeatedly:

  scan();
//
//  deTune = analogRead(A17);
//  deTune = mapfloat(deTune, 0, 1023, .875, 1.125);
  
  //lfo
 
  lfoFrequency = analogRead(A17)/50;
  lfo.frequency(lfoFrequency);
  tempDetuneMod = analogRead(A14)/2046;
  if(peak1.available()){
    tempPeak = peak1.read();
    //Serial.println("tempPeak");
    //Serial.println(tempPeak);
  }
  deTuneLfo = ((tempPeak) * tempDetuneMod + 1);
   //Serial.println(deTuneLfo);
}
  


