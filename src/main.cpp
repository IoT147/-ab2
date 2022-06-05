#include <Arduino.h>
#include <TFT_eSPI.h>
#include <SPI.h>
#include <ESP32Servo.h>
#include <Adafruit_CAP1188.h>

#define RED_PIN 32
#define YELLOW_PIN 33
#define GREEN_PIN 25

// Hard coded enumerator
#define RED_STATE 0
#define RED_YELLOW_STATE 1
#define YELLOW_STATE 2
#define GREEN_STATE 3
#define LEFT_BUTTON 0
#define BUZZER 26

#define RED_MILLIS 10000

int button_state = 0;    // button state

void red_sound() {
    tone(BUZZER, 440, 250);
    delay(1500);
}

void press_button()
{
    for (int i = 0; i < 4; i ++) {
        tone(BUZZER, 440, 500);
        delay(1500);
    }

    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(YELLOW_PIN, HIGH);
    delay(2000);
    digitalWrite(YELLOW_PIN, LOW);

    digitalWrite(RED_PIN, HIGH);
    for (int i = 0; i < 7; i ++) {
        red_sound();
    }

    digitalWrite(RED_PIN, HIGH);
    digitalWrite(YELLOW_PIN, HIGH);
    delay(2000);
    digitalWrite(RED_PIN, LOW);
    digitalWrite(YELLOW_PIN, LOW);

    button_state = 1;
}

void setup()
{
    // Configure LED pins as outputs. 
    pinMode(RED_PIN, OUTPUT); 
    pinMode(YELLOW_PIN, OUTPUT); 
    pinMode(GREEN_PIN, OUTPUT);
    pinMode(LEFT_BUTTON, INPUT_PULLUP);
    pinMode(BUZZER, OUTPUT);
    button_state = 1;
}

void loop()
{
    if (digitalRead(LEFT_BUTTON) == 0) {
      press_button();
    }
    digitalWrite(GREEN_PIN, HIGH);
    tone(BUZZER, 440, 500);
    delay(1500);
}