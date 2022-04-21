#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <Servo.h>

// Hard coded enumerator
#define RED_STATE 0
#define RED_YELLOW_STATE 1
#define YELLOW_STATE 2
#define GREEN_STATE 3

#define RED_MILLIS 10000

int tl_state;           // Traffic light state.
unsigned long tl_timer; // Traffic light timer.

void setup()
{
    // Configure LED pins as outputs. 
    pinMode(RED_PIN, OUTPUT); 
    pinMode(YELLOW_PIN, OUTPUT); 
    pinMode(GREEN_PIN, OUTPUT);

    // Initial state for states and timers.. 
    tl_state = RED_STATE;

    tl_timer = millis() + RED_MILLIS;
}

void loop()
{
    // TL state machine
    switch (tl_state)
    {
    case RED_STATE:
        // Turn red light on.
        if (/*Timer expired*/)
        { 
            // Turn red light off.

            // Set timer for red-yellow state.
            tl_state = RED_YELLOW_STATE;
        }
        break;
    case RED_YELLOW_STATE:
        // Code for red-yellow state.
    break; 
    case YELLOW_STATE:
        // Code for yellow state.
    break;
    case GREEN_STATE:
        // Turn green light on.
        if (/*Timer expired AND touch-button was pressed*/)
        {
            // Turn green light off.

            // Set timer for yellow 
            state. tl_state = YELLOW_STATE;
        }
        break;
    }
    // Detect touch - button pressed.
    
    // Buzzer state machine.
    // .
    // .
}

/*
void loop()
{
	loop_time++;
	Serial.println("Loop " + String(loop_time));
	val = analogRead(ADC);
	Serial.println("ADC val: " + String(val));
	int pos = int(val) / divider;
	myservo.write(pos);
	delay(15);
}
/*
const int LIGHT_PIN = A0; // Pin connected to voltage divider output
const int LED_PIN = 13; // Use built-in LED as dark indicator

// Measure the voltage at 5V and the actual resistance of your
// 47k resistor, and enter them below:
const float VCC = 4.98; // Measured voltage of Ardunio 5V line
const float R_DIV = 4660.0; // Measured resistance of 3.3k resistor

// Set this to the minimum resistance require to turn an LED on:
const float DARK_THRESHOLD = 10000.0;

void setup() 
{
  Serial.begin(9600);
  pinMode(LIGHT_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  // Read the ADC, and calculate voltage and resistance from it
  int lightADC = analogRead(LIGHT_PIN);
  if (lightADC > 0)
  {
    // Use the ADC reading to calculate voltage and resistance
    float lightV = lightADC * VCC / 1023.0;
    float lightR = R_DIV * (VCC / lightV - 1.0);
    Serial.println("Voltage: " + String(lightV) + " V");
    Serial.println("Resistance: " + String(lightR) + " ohms");

    // If resistance of photocell is greater than the dark
    // threshold setting, turn the LED on.
    if (lightR >= DARK_THRESHOLD)
      digitalWrite(LED_PIN, HIGH);
    else
      digitalWrite(LED_PIN, LOW);

    Serial.println();
    delay(500);
  }
}
*/