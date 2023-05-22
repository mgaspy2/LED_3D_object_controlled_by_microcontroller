#include <FastLED.h>

#include "Variables.h"
#include "Controls.h"
#include "Timer.h"
#include "Visualizations.h"


// --- Controls ------------------------------
Button leftButton(26);
Button rightButton(27);
Button minusButton(14);
Button plusButton(12);
Potentiometer potentiometer(13);
// --- Controls ------------------------------


void setup() {
  Serial.begin(9600);
  // --- FastLED -----------------------------
  FastLED.addLeds<WS2812, ledsPin0>(leds0, ledsNum);
  FastLED.addLeds<WS2812, ledsPin1>(leds1, ledsNum);
  FastLED.addLeds<WS2812, ledsPin2>(leds2, ledsNum);
  FastLED.addLeds<WS2812, ledsPin3>(leds3, ledsNum);
  FastLED.addLeds<WS2812, ledsPin4>(leds4, ledsNum);
  FastLED.addLeds<WS2812, ledsPin5>(leds5, ledsNum);
  FastLED.addLeds<WS2812, ledsPin6>(leds6, ledsNum);
  FastLED.addLeds<WS2812, ledsPin7>(leds7, ledsNum); 
  FastLED.setBrightness(map(analogRead(potentiometer.potPin), 0, 4095, 1, 255));
  // --- FastLED -----------------------------
}


void loop() {
  if (leftButton.isPressed()) {
    leftButton.controlsOutput(&cubeMode, &cubeMQ);
    visCounterReset(&periodCounter0);
    attributeReset(&modeAttribute);
  }
  if (rightButton.isPressed()) {
    rightButton.controlsOutput(&cubeMode, &cubeMQ);
    visCounterReset(&periodCounter0);
    attributeReset(&modeAttribute);
  }
  if (minusButton.isPressed()) {
    minusButton.controlsOutput(&modeAttribute, &attributeQ);
  }
  if (plusButton.isPressed()) {
    plusButton.controlsOutput(&modeAttribute, &attributeQ);
  }
  potentiometer.controlsOutput();

  visTimer(&previousTime0, &timePeriod0, &periodPassed0);
  visTimer(&previousTime1, &timePeriod1, &periodPassed1);
  
  
  // --- Serial ------------------------------
  // Serial.println("previous millis"); Serial.println(previousTime0);
  // Serial.println("period0 passed"); Serial.println(periodPassed0);
  // Serial.println("counter0"); Serial.println(periodCounter0);
  // --- Serial ------------------------------

  switch (cubeMode) {
    case 0:
        switch (modeAttribute) {
          case 0:
            UAI_vis(255,0,0);
            break;

          case 1:
            UAI_vis(0,255,0);
            break;

          case 2:
            UAI_vis(0,0,255);
            break;
        };
      break;

    case 1:
      switch (modeAttribute) {
        case 0:
          RGB_ani(potentiometer);
          break;                          

        case 1:
          RGB_aniOffset(potentiometer);
          break;

        case 2:
          caramelldansen();
          // RGB_vis();
          break;
      }
      break;

    case 2:
      switch (modeAttribute) {
        case 0:
          LED_vis(60, 8);
          break;

        case 1:
          LED_vis(30, 24);
          break;

        case 2:
          LED_vis(5, 72);
          break;
      }
      break;

    case 3:
      switch (modeAttribute) {
        case 0:
          staticColor(255, 255, 255);
          break;

        case 1:
          staticColor(218, 165,  32);
          break;

        case 2:
          staticColor(255, 140,  0);
          break;
      }
      break;
  }

  visTimerReset(&periodPassed0);
  visTimerReset(&periodPassed1);
  // Serial.println("loop passed"); Serial.println();
}