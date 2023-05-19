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
      visCounter(&periodCounter0, &periodPassed0);
      if (periodCounter0 < 4) {
        clcLED();
        switch (modeAttribute) {
          case 0:
            for (int i = 0; i < ledsNum; i++) {
              if (VUT_LOGO[i] == 1) {
                leds0[i] = CRGB::White;
                leds1[i] = CRGB::White;
                leds2[i] = CRGB::White;
                leds3[i] = CRGB::White;
                leds4[i] = CRGB::White;
                leds5[i] = CRGB::White;
                leds6[i] = CRGB::White;
                leds7[i] = CRGB::White;
              } else {
                leds0[i] = CRGB::Red;
                leds1[i] = CRGB::Red;
                leds2[i] = CRGB::Red;
                leds3[i] = CRGB::Red;
                leds4[i] = CRGB::Red;
                leds5[i] = CRGB::Red;
                leds6[i] = CRGB::Red;
                leds7[i] = CRGB::Red;
              }
            }
            break;

          case 1:
            for (int i = 0; i < ledsNum; i++) {
              if (VUT_LOGO[i] == 1) {
                leds0[i] = CRGB::White;
                leds1[i] = CRGB::White;
                leds2[i] = CRGB::White;
                leds3[i] = CRGB::White;
                leds4[i] = CRGB::White;
                leds5[i] = CRGB::White;
                leds6[i] = CRGB::White;
                leds7[i] = CRGB::White;
              } else {
                leds0[i] = CRGB::Blue;
                leds1[i] = CRGB::Blue;
                leds2[i] = CRGB::Blue;
                leds3[i] = CRGB::Blue;
                leds4[i] = CRGB::Blue;
                leds5[i] = CRGB::Blue;
                leds6[i] = CRGB::Blue;
                leds7[i] = CRGB::Blue;
              }
            }
            
            break;

          case 2:
            for (int i = 0; i < ledsNum; i++) {
              if (VUT_LOGO[i] == 1) {
                leds0[i] = CRGB::White;
                leds1[i] = CRGB::White;
                leds2[i] = CRGB::White;
                leds3[i] = CRGB::White;
                leds4[i] = CRGB::White;
                leds5[i] = CRGB::White;
                leds6[i] = CRGB::White;
                leds7[i] = CRGB::White;
              } else {
                leds0[i] = CRGB::Green;
                leds1[i] = CRGB::Green;
                leds2[i] = CRGB::Green;
                leds3[i] = CRGB::Green;
                leds4[i] = CRGB::Green;
                leds5[i] = CRGB::Green;
                leds6[i] = CRGB::Green;
                leds7[i] = CRGB::Green;
              }
            }
            break;
        };

      } else if (periodCounter0 < 6) {
        clcLED();
        for (int i = 0; i < ledsNum; i++) {
          if (ALPHA_U[i] == 1) {
            leds2[i] = CRGB::Blue;
            leds3[i] = CRGB::Blue;
            leds4[i] = CRGB::Blue;
            leds5[i] = CRGB::Blue;
          }
        }
      } else if (periodCounter0 < 8) {
        clcLED();
        for (int i = 0; i < ledsNum; i++) {
          if (ALPHA_A[i] == 1) {
            leds2[i] = CRGB::Blue;
            leds3[i] = CRGB::Blue;
            leds4[i] = CRGB::Blue;
            leds5[i] = CRGB::Blue;
          }
        }
      } else if (periodCounter0 < 10) {
        clcLED();
        for (int i = 0; i < ledsNum; i++) {
          if (ALPHA_I[i] == 1) {
            leds2[i] = CRGB::Blue;
            leds3[i] = CRGB::Blue;
            leds4[i] = CRGB::Blue;
            leds5[i] = CRGB::Blue;
          }
        }
      } else if (periodCounter0 >= 10) {
        Serial.println("VUT visualization passed");
        visCounterReset(&periodCounter0);
      }
      FastLED.show();
      break;

    case 1:
      switch (modeAttribute) {
        case 0:
          visCounter(&periodCounter0, &periodPassed0);
          if (periodCounter0 < 1) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Red;
              leds1[i] = CRGB::Red;
              leds2[i] = CRGB::Red;
              leds3[i] = CRGB::Red;
              leds4[i] = CRGB::Red;
              leds5[i] = CRGB::Red;
              leds6[i] = CRGB::Red;
              leds7[i] = CRGB::Red;
            }
          } else if (periodCounter0 < 2) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Green;
              leds1[i] = CRGB::Green;
              leds2[i] = CRGB::Green;
              leds3[i] = CRGB::Green;
              leds4[i] = CRGB::Green;
              leds5[i] = CRGB::Green;
              leds6[i] = CRGB::Green;
              leds7[i] = CRGB::Green;
            }
          } else if (periodCounter0 < 3) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Blue;
              leds1[i] = CRGB::Blue;
              leds2[i] = CRGB::Blue;
              leds3[i] = CRGB::Blue;
              leds4[i] = CRGB::Blue;
              leds5[i] = CRGB::Blue;
              leds6[i] = CRGB::Blue;
              leds7[i] = CRGB::Blue;
            }
          } else if (periodCounter0 >= 3) {
            Serial.println("RGB visualization passed");
            visCounterReset(&periodCounter0);
          }
          FastLED.show();
          break;

        case 1:
          visCounter(&periodCounter1, &periodPassed1);
          if (periodCounter1 < 1) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Red;
              leds1[i] = CRGB::Red;
              leds2[i] = CRGB::Red;
              leds3[i] = CRGB::Red;
              leds4[i] = CRGB::Red;
              leds5[i] = CRGB::Red;
              leds6[i] = CRGB::Red;
              leds7[i] = CRGB::Red;
            }
          } else if (periodCounter1 < 2) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Orange;
              leds1[i] = CRGB::Orange;
              leds2[i] = CRGB::Orange;
              leds3[i] = CRGB::Orange;
              leds4[i] = CRGB::Orange;
              leds5[i] = CRGB::Orange;
              leds6[i] = CRGB::Orange;
              leds7[i] = CRGB::Orange;
            }
          } else if (periodCounter1 < 3) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Yellow;
              leds1[i] = CRGB::Yellow;
              leds2[i] = CRGB::Yellow;
              leds3[i] = CRGB::Yellow;
              leds4[i] = CRGB::Yellow;
              leds5[i] = CRGB::Yellow;
              leds6[i] = CRGB::Yellow;
              leds7[i] = CRGB::Yellow;
            }
          } else if (periodCounter1 < 4) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Green;
              leds1[i] = CRGB::Green;
              leds2[i] = CRGB::Green;
              leds3[i] = CRGB::Green;
              leds4[i] = CRGB::Green;
              leds5[i] = CRGB::Green;
              leds6[i] = CRGB::Green;
              leds7[i] = CRGB::Green;
            }
          } else if (periodCounter1 < 5) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Blue;
              leds1[i] = CRGB::Blue;
              leds2[i] = CRGB::Blue;
              leds3[i] = CRGB::Blue;
              leds4[i] = CRGB::Blue;
              leds5[i] = CRGB::Blue;
              leds6[i] = CRGB::Blue;
              leds7[i] = CRGB::Blue;
            }
          } else if (periodCounter1 < 6) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Indigo;
              leds1[i] = CRGB::Indigo;
              leds2[i] = CRGB::Indigo;
              leds3[i] = CRGB::Indigo;
              leds4[i] = CRGB::Indigo;
              leds5[i] = CRGB::Indigo;
              leds6[i] = CRGB::Indigo;
              leds7[i] = CRGB::Indigo;
            }
          } else if (periodCounter1 < 7) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Violet;
              leds1[i] = CRGB::Violet;
              leds2[i] = CRGB::Violet;
              leds3[i] = CRGB::Violet;
              leds4[i] = CRGB::Violet;
              leds5[i] = CRGB::Violet;
              leds6[i] = CRGB::Violet;
              leds7[i] = CRGB::Violet;
            }
          } else if (periodCounter1 >= 7) {
            visCounterReset(&periodCounter1);
          }
          FastLED.show();
          break;

        case 2:
          visCounter(&periodCounter0, &periodPassed0);
          if (periodCounter0 < 1) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Red;
              leds1[i] = CRGB::Red;
              leds2[i] = CRGB::Red;
              leds3[i] = CRGB::Red;
              leds4[i] = CRGB::Red;
              leds5[i] = CRGB::Red;
              leds6[i] = CRGB::Red;
              leds7[i] = CRGB::Red;
            }
          } else if (periodCounter0 < 2) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Orange;
              leds1[i] = CRGB::Orange;
              leds2[i] = CRGB::Orange;
              leds3[i] = CRGB::Orange;
              leds4[i] = CRGB::Orange;
              leds5[i] = CRGB::Orange;
              leds6[i] = CRGB::Orange;
              leds7[i] = CRGB::Orange;
            }
          } else if (periodCounter0 < 3) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Yellow;
              leds1[i] = CRGB::Yellow;
              leds2[i] = CRGB::Yellow;
              leds3[i] = CRGB::Yellow;
              leds4[i] = CRGB::Yellow;
              leds5[i] = CRGB::Yellow;
              leds6[i] = CRGB::Yellow;
              leds7[i] = CRGB::Yellow;
            }
          } else if (periodCounter0 < 4) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Green;
              leds1[i] = CRGB::Green;
              leds2[i] = CRGB::Green;
              leds3[i] = CRGB::Green;
              leds4[i] = CRGB::Green;
              leds5[i] = CRGB::Green;
              leds6[i] = CRGB::Green;
              leds7[i] = CRGB::Green;
            }
          } else if (periodCounter0 < 5) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Blue;
              leds1[i] = CRGB::Blue;
              leds2[i] = CRGB::Blue;
              leds3[i] = CRGB::Blue;
              leds4[i] = CRGB::Blue;
              leds5[i] = CRGB::Blue;
              leds6[i] = CRGB::Blue;
              leds7[i] = CRGB::Blue;
            }
          } else if (periodCounter0 < 6) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Indigo;
              leds1[i] = CRGB::Indigo;
              leds2[i] = CRGB::Indigo;
              leds3[i] = CRGB::Indigo;
              leds4[i] = CRGB::Indigo;
              leds5[i] = CRGB::Indigo;
              leds6[i] = CRGB::Indigo;
              leds7[i] = CRGB::Indigo;
            }
          } else if (periodCounter0 < 7) {
            for (int i = 0; i < ledsNum; i++) {
              leds0[i] = CRGB::Violet;
              leds1[i] = CRGB::Violet;
              leds2[i] = CRGB::Violet;
              leds3[i] = CRGB::Violet;
              leds4[i] = CRGB::Violet;
              leds5[i] = CRGB::Violet;
              leds6[i] = CRGB::Violet;
              leds7[i] = CRGB::Violet;
            }
          } else if (periodCounter0 >= 7) {
            Serial.println("ROYGBIV visualization passed");
            visCounterReset(&periodCounter0);
          }
          FastLED.show();
          break;                          
      }
      break;

    case 2:

      switch (modeAttribute) {
        case 0:
          for (int i = 0; i < ledsNum; i++) {
            leds0[i] = CRGB::White;
            leds1[i] = CRGB::White;
            leds2[i] = CRGB::White;
            leds3[i] = CRGB::White;
            leds4[i] = CRGB::White;
            leds5[i] = CRGB::White;
            leds6[i] = CRGB::White;
            leds7[i] = CRGB::White;
          }
          break;

        case 1:
          for (int i = 0; i < ledsNum; i++) {
            leds0[i] = CRGB::Yellow;
            leds1[i] = CRGB::Yellow;
            leds2[i] = CRGB::Yellow;
            leds3[i] = CRGB::Yellow;
            leds4[i] = CRGB::Yellow;
            leds5[i] = CRGB::Yellow;
            leds6[i] = CRGB::Yellow;
            leds7[i] = CRGB::Yellow;
          }
          break;

        case 2:
          for (int i = 0; i < ledsNum; i++) {
            leds0[i] = CRGB::Orange;
            leds1[i] = CRGB::Orange;
            leds2[i] = CRGB::Orange;
            leds3[i] = CRGB::Orange;
            leds4[i] = CRGB::Orange;
            leds5[i] = CRGB::Orange;
            leds6[i] = CRGB::Orange;
            leds7[i] = CRGB::Orange;
          }
          break;
      }
      FastLED.show();      
      break;
  }


  visTimerReset(&periodPassed0);
  visTimerReset(&periodPassed1);
  // Serial.println("loop passed"); Serial.println();
}