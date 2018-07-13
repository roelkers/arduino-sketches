
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
AudioControlSGTL5000     sgtl5000_1;     //xy=558,228
// GUItool: end automatically generated code

//config variables
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (2)

// Global variables
//static bool LED_buffer[NUM_LED_COLUMNS][NUM_LED_ROWS];

static const uint8_t btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
static const uint8_t btnrowpins[NUM_BTN_ROWS]       = {6, 7};

KeyMatrix keypad(4,4, btnrowPins, btncolumnPins, keymap);

float notes[] = {
  {
   261.6255653006,
   293.6647679174,
   329.6275569129,
   349.2282314330
  },
  {
   391.9954359817,
   440.0000000000,
   493.8833012561,
   513.23
  }
};

// save button state
uint8_t prevBtnState;
uint8_t btnState;

uint8_t noteTrigFlag;

//ADSR
int attackTime;
int decayTime;
float sustainLevel;
int releaseTime;

int attackWait;

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

}

void pressed(float note){
  
     Serial.println("note triggered");
      waveform1.frequency(note);
      
      voice1env.amplitude(1,attackTime);
      //voice1filterenv.amplitude(1,attackTimeFilter);
      noteTrigFlag = true;
      attackWait = millis();
}    

void released(float note){
  
      Serial.print("Key Up ");
      Serial.println(note);
      // If you want to do something when a key is released, do it here:
      noteTrigFlag= false;
      voice1env.amplitude(0,releaseTime);
      //voice1filterenv.amplitude(-1, releaseTimeFilter);
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

  attackTime = 550;
  decayTime = 150;
  sustainLevel = 0;
  releaseTime = 550;
  
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.print("Starting Setup...");

  // setup hardware
  setuppins();

  Serial.println("Setup Complete.");

}

void loop() {
  // put your main code here, to run repeatedly:

  keypad.update();
  
  if(millis() - attackWait > attackTime && noteTrigFlag){
       voice1env.amplitude(sustainLevel,decayTime);
  }

}
