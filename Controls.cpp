#include <Arduino.h>
#include <FastLED.h>
#include "Controls.h"

// --- Button --------------------------------
bool Button::isPressed() {
  bool last = buttonState;
  buttonState = digitalRead(buttonPin);

  if ((last != buttonState) && (!buttonState) && lastTime < millis()) {
    lastTime = millis() + 50;
    return true;
  }
  return false;
}

void Button::controlsOutput(int *mode, const uint8_t *num) {
  if (buttonPin == 26) {
    --*mode;
    if (*mode < 0)
      *mode = *num - 1;
    else if (*mode > *num - 1)
      *mode = 0;
    Serial.println("Mode");
  }

  if (buttonPin == 27) {
    ++*mode;
    if (*mode < 0)
      *mode = *num - 1;
    else if (*mode > *num - 1)
      *mode = 0;
    Serial.println("Mode");
    
  }

  if (buttonPin == 14) {
    --*mode;
    if (*mode < 0)
      *mode = *num - 1;
    else if (*mode > *num - 1)
      *mode = 0;
    Serial.println("Attribute");
  }

  if (buttonPin == 12) {
    ++*mode;
    if (*mode < 0)
      *mode = *num - 1;
    else if (*mode > *num - 1)
      *mode = 0;
    Serial.println("Attribute");
  }

  Serial.println(*mode);
}

void Button::controlsOutput(int *attribute) {
  if (buttonPin == 14) {
    --*attribute;
  }
  if (buttonPin == 12) {
    ++*attribute;
  }
  Serial.println("Attribute");
  Serial.println(*attribute);
}
// --- Button --------------------------------


void attributeCheck(int *attribute, const uint8_t num) {
  if (*attribute < 0)
    *attribute = num - 1;
  else if (*attribute > num - 1)
    *attribute = 0;
}

void attributeReset(int *attribute) {
  if(*attribute != 0){
    *attribute = 0;
    Serial.println("Attribute reset");
  }
}


// --- Potentiometer -------------------------
void Potentiometer::controlsOutput() {
  potValue = analogRead(potPin);
  if (abs(potValueOld - potValue) >= 25) {
    potValueOld = potValue;
    brightness = map(potValue, 0, 4095, 1, 255);
    FastLED.setBrightness(brightness);
  }
}
// --- Potentiometer -------------------------
