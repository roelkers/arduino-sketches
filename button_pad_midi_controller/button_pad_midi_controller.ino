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
#include <MIDI.h>

MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);
const int channel = 1;

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
AudioControlSGTL5000     sgtl5000_1;     //xy=558,228
// GUItool: end automatically generated code

//config variables
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (4)

#define MAX_DEBOUNCE (3)

// Global variables
//static bool LED_buffer[NUM_LED_COLUMNS][NUM_LED_ROWS];

static const uint8_t btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
static const uint8_t btnrowpins[NUM_BTN_ROWS]       = {6, 7, 9, 10};

static int8_t debounce_count[NUM_BTN_COLUMNS][NUM_BTN_ROWS];

float notes[] = {
  130.81,
  146.83,
  164.81,
  174.61,
  196.00,
  220.00,
  246.94,
  261.63,
  293.66,
  329.63,
  349.23,
  392.00,
  440.00,
  493.88,
  523.25,
  587.33,
  };

// save button state
uint8_t prevBtnState;
uint8_t btnState;

uint8_t noteTrigFlag[8];

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
            
            Serial.println("btnState:");
            Serial.println(btnState);
            Serial.println("previous:");
            Serial.println(prevBtnState);
            
            // Do whatever you want to with the button press here:
            if (btnState == LOW && prevBtnState == HIGH){

              Serial.println("note triggered");
              MIDI.sendNoteOn(notes[index], 100, channel);
              
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
            MIDI.sendNoteOff(notes[index], 100, channel);
          }
        }
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

  MIDI.begin();
  
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

}
