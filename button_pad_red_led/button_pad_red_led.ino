
/******************************************************************************
red-only.ino
Byron Jacquot @ SparkFun Electronics
1/6/2015

Example to drive the red LEDs in the RGB button pad.

Exercise 1 in a series of 3.
https://learn.sparkfun.com/tutorials/button-pad-hookup-guide/exercise-1-monochrome-leds

Development environment specifics:
Developed in Arduino 1.6.5
For an Arduino Mega 2560

This code is released under the [MIT License](http://opensource.org/licenses/MIT).

Distributed as-is; no warranty is given.
******************************************************************************/    
//config variables
#define NUM_LED_COLUMNS (4)
#define NUM_LED_ROWS (2)
#define NUM_COLORS (1)

// Global variables
static bool LED_buffer[NUM_LED_COLUMNS][NUM_LED_ROWS];
static int32_t next_advance;
static uint8_t led_index;

static const uint8_t ledcolumnpins[NUM_LED_COLUMNS] = {23, 22, 21, 20}; //42,43,44,45 //LED GND 4,3,2,1
static const uint8_t colorpins[NUM_LED_ROWS]        = {17, 13}; //22,30,33,36 //Red 1,2,3,4

static void setuppins()
{
  uint8_t i;

  // initialize all of the output pins

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
    pinMode(colorpins[i], OUTPUT);

    // with nothing driven by default
    digitalWrite(colorpins[i], LOW);
  }

}

static void scan()
{
  static uint8_t current = 0;
  uint8_t val;
  uint8_t i, j;

  // Select a column
  digitalWrite(ledcolumnpins[current], LOW);

  // write the row pins
  for(i = 0; i < NUM_LED_ROWS; i++)
  {
    if(LED_buffer[current][i])
    {
      digitalWrite(colorpins[i], HIGH);
    }
  }

  delay(1);

  digitalWrite(ledcolumnpins[current], HIGH);

  for(i = 0; i < NUM_LED_ROWS; i++)
  {
    digitalWrite(colorpins[i], LOW);
  }

  // Move on to the next column
  current++;
  if (current >= NUM_LED_COLUMNS)
  {
    current = 0;
  }

}

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Starting Setup...");

  // setup hardware
  setuppins();

  // init global variables
  next_advance = millis() + 1000;
  led_index = 0;

  // Initialize the LED display array
  for(uint8_t i = 0; i < NUM_LED_COLUMNS; i++)
  {
    for(uint8_t j = 0; j < NUM_LED_ROWS; j++)
    {
      LED_buffer[i][j] = false;
    }
  }
  // Set the first LED in the buffer on
  LED_buffer[0][0] = true;

  Serial.println("Setup Complete.");

}

void loop() 
{
  // put your main code here, to run repeatedly:

  scan();

  if(millis() >= next_advance)
  {
    next_advance = millis()+1000;

    LED_buffer[led_index%NUM_LED_COLUMNS][led_index/NUM_LED_COLUMNS] = false;
    led_index++;
	//next line resets led_index when at end of loop
    led_index = led_index % (NUM_LED_COLUMNS * NUM_LED_ROWS);
    LED_buffer[led_index%NUM_LED_COLUMNS][led_index/NUM_LED_COLUMNS] = true;

    int row = led_index%NUM_LED_COLUMNS;
    int column = led_index/NUM_LED_COLUMNS;
    Serial.println("index: ");
    Serial.println(led_index);
    Serial.println("row: ");
    Serial.println(row);
    Serial.println("column: ");
    Serial.println(column);
  }
}

