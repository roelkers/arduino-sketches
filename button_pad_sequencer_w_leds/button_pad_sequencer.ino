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
AudioSynthWaveformDc     voice1env;            //xy=204,183
AudioSynthWaveform       waveform1;      //xy=209,83
AudioEffectMultiply      multiply1;      //xy=458,135
AudioMixer4              mixer1;         //xy=760,136
AudioOutputI2S           i2s1;           //xy=972,141
AudioConnection          patchCord1(voice1env, 0, multiply1, 1);
AudioConnection          patchCord2(waveform1, 0, multiply1, 0);
AudioConnection          patchCord3(multiply1, 0, mixer1, 0);
AudioConnection          patchCord4(mixer1, 0, i2s1, 0);
AudioConnection          patchCord5(mixer1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=558,228
// GUItool: end automatically generated code

//config variables
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (2)
#define NUM_LED_COLUMNS (4)
#define NUM_LED_ROWS (2)

#define MAX_DEBOUNCE (3)

// Global variables
static bool LED_buffer_green[NUM_LED_COLUMNS][NUM_LED_ROWS];
static bool LED_buffer_red[NUM_LED_COLUMNS][NUM_LED_ROWS];

static const uint8_t btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
static const uint8_t btnrowpins[NUM_BTN_ROWS]       = {6, 7};

static const uint8_t ledcolumnpins[NUM_LED_COLUMNS] = {23, 22, 21, 20}; //42,43,44,45 //LED GND 4,3,2,1
static const uint8_t redpins[NUM_LED_ROWS]        = {17, 13}; //22,30,33,36 //Red 1,2,3,4
static const uint8_t greenpins[NUM_LED_ROWS]        = {18, 14}; 

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

static bool steps[8];
static float sequence[8];
  
// save button state
uint8_t prevBtnState;
uint8_t btnState;

//Sequencer
double stepLength; //120 BPM
double stepWait;
int activeStep;

//ADSR
int attackTime;
int decayTime;
float sustainLevel;
int releaseTime;

int attackWait;
int noteTrigFlag;

int getSmooth(){
  int vals[100]; //array that stores 5 readings.
  for(int i = 0; i < 100; i++){
    vals[i] = analogRead(A14); //takes 5 readings.
  }
  float smooth = (vals[0] + vals[1] + vals[2] + vals[3] + vals[4]) / 5;
  return smooth;
}

static void setuppins()
{
  uint8_t i;

  // LED column lines
  for(i = 0; i < NUM_LED_COLUMNS; i++)
  {
    pinMode(ledcolumnpins[i], OUTPUT);

    // with nothing selected by default
    digitalWrite(ledcolumnpins[i], HIGH);
  }

  // LED row lines
  for(i = 0; i < NUM_LED_ROWS; i++)
  {
    pinMode(redpins[i], OUTPUT);

    // with nothing driven by default
    digitalWrite(redpins[i], LOW);
  }
  
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

static void scanLEDs()
{
  static uint8_t j = 0;
  uint8_t val;
  uint8_t i, j;
  uint8_t index = 0; 
  
  // Select a column
  digitalWrite(ledcolumnpins[j], LOW);

  // write the row pins
  for(i = 0; i < NUM_LED_ROWS; i++)
  {
	index = j*NUM_BTN_COLUMNS+i;
	//check if this is the activeStep
    if(index == activeStep){
	  digitalWrite(redPins[i],High);
	}
	//otherwise check if this step has a note
	else if(steps[index])
    {
      digitalWrite(greenpins[i], HIGH);
    }
	
  }

  delay(1);

  digitalWrite(ledcolumnpins[j], HIGH);

  for(i = 0; i < NUM_LED_ROWS; i++)
  {
    digitalWrite(redpins[i], LOW);
	digitalWrite(greenpins[i], LOW);
  }

  // Move on to the next column
  j++;
  if (j >= NUM_LED_COLUMNS)
  {
    j = 0;
  }

}

static void scanButtons()
{
  static uint8_t current = 0;
  uint8_t val;
  uint8_t i, j;
  int index = 0;;
  
  //buttons
  for(int i = 0; i < NUM_BTN_COLUMNS; i++){  
    // Select current columns
    digitalWrite(btncolumnpins[i], LOW);
  
    // pause a moment
    delay(1);
    
    // Read the button inputs
    for ( j = 0; j < NUM_BTN_ROWS; j++)
    {
	
      index = j*NUM_BTN_COLUMNS+i;
      
      btnState = digitalRead(btnrowpins[j]);
      
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
              
			steps[index] = !steps[index];  

            //Serial.println("LED buffer: ");  
            //Serial.println(LED_buffer[j][i]);

            //Serial.println("LED values");
            
//            for(int k = 0; k < NUM_LED_COLUMNS; k++){
//
//              for (int m = 0; m < NUM_LED_ROWS; m++)
//              {
//                Serial.println(LED_buffer[k][m]);
//              }
//            }            
                        
            //read pitch value 
            float knob = getSmooth();
            Serial.println(knob);
      
            float pitch = map(knob,1015,1023,261,513);
            Serial.println(pitch);

            sequence[index] = pitch;
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
            
          }
        }
      }
  
    }// for j = 0 to 3;

    delay(1);

    digitalWrite(btncolumnpins[i], HIGH);

  }

}

void advanceSequencer(){
//    Serial.println("envelope amp: ");
//    Serial.println(voice1env.read());
    
	  if(steps[activeStep]){
      
  	  Serial.println("note triggered");
      Serial.println("activeStep");
      Serial.println(activeStep);
      //waveform1.frequency(sequence[activeStep]);
             
      waveform1.frequency(sequence[activeStep]);
          
      voice1env.amplitude(1,attackTime);
      //voice1filterenv.amplitude(1,attackTimeFilter);
      noteTrigFlag = true;
      attackWait = millis();  
	  }
    else {  
      if(noteTrigFlag){
        voice1env.amplitude(0,releaseTime);
        noteTrigFlag = false;
        Serial.println("note released");
      }
    }

}

void setup()
{

  Serial.begin(9600);
  AudioMemory(20);
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.32);

  mixer1.gain(0,1);
  waveform1.begin(WAVEFORM_SAWTOOTH);
  waveform1.amplitude(0.75);
  waveform1.frequency(50);

  voice1env.amplitude(0);

  attackTime = 50;
  decayTime = 150;
  sustainLevel = 0;
  releaseTime = 550;

  //Sequencer
  stepLength = 250; //BPM
  stepWait = 0;
  activeStep = 0;
  
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.print("Starting Setup...");

  // setup hardware
  setuppins();

  Serial.println("Setup Complete.");

}

void loop() {
  // put your main code here, to run repeatedly:
  
  scanLEDs();
  scanButtons();
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

  //check attack
//  if(millis() - attackWait > attackTime && noteTrigFlag){
//     voice1env.amplitude(sustainLevel,decayTime);
//  }
//    if(millis() - attackWait[index] > attackTimeFilter && noteTrigFlag[index]){
//      voice1filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
//    }
  
}
