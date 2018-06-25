
/******************************************************************************
rgb-plus-buttons.ino
Byron Jacquot @ SparkFun Electronics
1/6/2015

Example to drive the RGB LEDs and scan the buttons of the RGB button pad.

Exercise 3 in a series of 3.
https://learn.sparkfun.com/tutorials/button-pad-hookup-guide/exercise-3-rgb-leds-and-buttons

Development environment specifics:
Developed in Arduino 1.6.5
For an Arduino Mega 2560

This code is released under the [MIT License](http://opensource.org/licenses/MIT).

Distributed as-is; no warranty is given.
******************************************************************************/         
//config variables
#define NUM_LED_COLUMNS (4)
#define NUM_LED_ROWS (4)
#define NUM_BTN_COLUMNS (4)
#define NUM_BTN_ROWS (4)
#define NUM_COLORS (3)

#define MAX_DEBOUNCE (3)

// Global variables
static uint8_t LED_outputs[NUM_LED_COLUMNS][NUM_LED_ROWS];
static int32_t next_scan;

static const uint8_t btnselpins[4]   = {2,3,4,5};
static const uint8_t btnreadpins[4] = {6,7,8,9};
static const uint8_t ledselpins[4]   = {20,21,22,23};

// RGB pins for each of 4 rows 
static const uint8_t colorpins[4][3] = {{13,14,15}, {17,18,19},{33,34,35},{36,37,38}};


static int8_t debounce_count[NUM_BTN_COLUMNS][NUM_BTN_ROWS];

static void setuppins()
{
    uint8_t i;

    // initialize
    // select lines
    for(i = 0; i < NUM_LED_COLUMNS; i++)
    {
        pinMode(ledselpins[i], OUTPUT);

        // with nothing selected by default
        digitalWrite(ledselpins[i], HIGH);
    }

    for(i = 0; i < NUM_BTN_COLUMNS; i++)
    {
        pinMode(btnselpins[i], OUTPUT);

        // with nothing selected by default
        digitalWrite(btnselpins[i], HIGH);
    }

    // key return lines
    for(i = 0; i < 4; i++)
    {
        pinMode(btnreadpins[i], INPUT_PULLUP);
    }

    // LED drive lines
    for(i = 0; i < NUM_LED_ROWS; i++)
    {
        for(uint8_t j = 0; j < NUM_COLORS; j++)
        {
            pinMode(colorpins[i][j], OUTPUT);
            digitalWrite(colorpins[i][j], LOW);
        }
    }

    for(uint8_t i = 0; i < NUM_BTN_COLUMNS; i++)
    {
        for(uint8_t j = 0; j < NUM_BTN_ROWS; j++)
        {
            debounce_count[i][j] = 0;
        }
    }
}

static void scan()
{
  //static uint8_t current = 0;
  uint8_t val;
  uint8_t i, j;

    //run

  for(int current = 0; current < NUM_LED_COLUMNS; current ++){
    
      digitalWrite(btnselpins[current], LOW);
      digitalWrite(ledselpins[current], LOW);
  
      for(i = 0; i < NUM_LED_ROWS; i++)
      {
          uint8_t val = (LED_outputs[i][current] & 0x03);
  
          if(val)
          {
              digitalWrite(colorpins[i][val-1], HIGH);
          }
    }
  
  
    delay(1);
  
    for( j = 0; j < NUM_BTN_ROWS; j++)
    {
      val = digitalRead(btnreadpins[j]);
  
      if(val == LOW)
      {
        // active low: val is low when btn is pressed
        if( debounce_count[current][j] < MAX_DEBOUNCE)
        {
          debounce_count[current][j]++;
          if( debounce_count[current][j] == MAX_DEBOUNCE )
          {
            Serial.print("Key Down ");
            Serial.println((current * NUM_BTN_ROWS) + j);
  
            LED_outputs[j][current]++;
          }
        }
      }
      else
      {
        // otherwise, button is released
        if( debounce_count[current][j] > 0)
        {
          debounce_count[current][j]--;
          if( debounce_count[current][j] == 0 )
          {
            Serial.print("Key Up ");
            Serial.println((current * NUM_BTN_ROWS) + j);
          }
        }
      }
    }// for j = 0 to 3;
  
    delay(1);
  
    digitalWrite(btnselpins[current], HIGH);
    digitalWrite(ledselpins[current], HIGH);
  
    for(i = 0; i < NUM_LED_ROWS; i++)
    {
      for(j = 0; j < NUM_COLORS; j++)
      {
        digitalWrite(colorpins[i][j], LOW);
      }
    }

  }
//  current++;
//  if (current >= NUM_BTN_COLUMNS)
//  {
//    current = 0;
//  }
}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);

  Serial.print("Starting Setup...");

  // setup hardware
  setuppins();

  // init global variables
  next_scan = millis() + 1;

  for(uint8_t i = 0; i < NUM_LED_ROWS; i++)
  {
    for(uint8_t j = 0; j < NUM_LED_COLUMNS; j++)
    {
      LED_outputs[i][j] = 0;
    }
  }

  Serial.println("Setup Complete.");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(millis() >= next_scan)
  {
    next_scan = millis()+1;
    scan();
  }
}

