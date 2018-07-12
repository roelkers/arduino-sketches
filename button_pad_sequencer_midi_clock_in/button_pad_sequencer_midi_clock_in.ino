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
static bool LED_buffer[NUM_LED_COLUMNS][NUM_LED_ROWS];

static const uint8_t btncolumnpins[NUM_BTN_COLUMNS] = {2, 3, 4, 5};
static const uint8_t btnrowpins[NUM_BTN_ROWS]       = {6, 7};

static const uint8_t ledcolumnpins[NUM_LED_COLUMNS]   = {20,21,22,23};
static const uint8_t colorpins[NUM_LED_ROWS] = {13,17};

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

//midi
byte midi_start = 0xfa;
byte midi_stop = 0xfc;
byte midi_clock = 0xf8;
byte midi_continue = 0xfb;
int play_flag = 0;
byte data;
int tickCount = 0;
float lastStepTime;
  
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

//  // initialize
//  // select lines
//  for(i = 0; i < NUM_LED_COLUMNS; i++)
//  {
//      pinMode(ledcolumnpins[i], OUTPUT);
//
//      // with nothing selected by default
//      digitalWrite(ledcolumnpins[i], HIGH);
//  }
//
//  // LED drive lines
//  for(i = 0; i < NUM_LED_ROWS; i++)
//  {   
//      pinMode(colorpins[i], OUTPUT);
//      digitalWrite(colorpins[i], LOW);
//  }
  
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

//  //Drive LED colorpins
//  for(int i = 0; i < NUM_LED_COLUMNS; i++){
//
//    digitalWrite(ledcolumnpins[i], LOW);  
//  
//    for ( j = 0; j < NUM_LED_ROWS; j++)
//    {
//
//    //Serial.println(LED_buffer[j][i]);
//    
//      if(LED_buffer[j][i])
//      {
//        digitalWrite(colorpins[j], HIGH);
////        Serial.println("led driven");
////        Serial.println("row:");
////        Serial.println(j);
////        Serial.println("column:");
////        Serial.println(i);      
//      } 
//    }
//  }  
  
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
      			LED_buffer[j][i] = !LED_buffer[j][i];

            
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
    digitalWrite(ledcolumnpins[i], HIGH);
    
    //Switch LED colorpins out

  }
  
//  for(int i = 0; i < NUM_BTN_COLUMNS; i++){  
//    for (int j = 0; j < NUM_LED_ROWS; j++)
//    {
//       digitalWrite(colorpins[j], LOW);  
//    }
//  }
    

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
  
  //Begin Midi serial
  Serial.begin(57600);

  Serial.print("Starting Setup...");

  // setup hardware
  setuppins();

  Serial.println("Setup Complete.");

}

void loop() {
  // put your main code here, to run repeatedly:

  scan();
  


void setup() {
 Serial.begin(31250);
}

void loop() {

 if(Serial.available() > 0) {
	 data = Serial.read();
	 if(data == midi_start) {
	 play_flag = 1;
	 }
	 else if(data == midi_continue) {
	 play_flag = 1;
	 }
	 else if(data == midi_stop) {
	 play_flag = 0;
	 }
	 else if((data == midi_clock) && (play_flag == 1)) {
		tickCount++
		if(tickCount == 6){
			//24 ticks is one quarter, so 6 ticks is a sixteenth step...
			//set new step length
			stepLength = millis() - lastStepTime;
			
			//reset
			lastStepTime = millis();
			tickCount = 0;
		}
	 }
 }
  
  
  if(millis() - stepWait > stepLength){
    if(playFlag){
		stepWait = millis();
		if(activeStep == 7){
		  activeStep = 0;
		}
		else{
		  activeStep++;
		}
		advanceSequencer();
    }
	else{
		stepWait = 0;
	}
  }

  //check attack
//  if(millis() - attackWait > attackTime && noteTrigFlag){
//     voice1env.amplitude(sustainLevel,decayTime);
//  }
//    if(millis() - attackWait[index] > attackTimeFilter && noteTrigFlag[index]){
//      voice1filterenv.amplitude(sustainLevelFilter,decayTimeFilter);
//    }
  
}
