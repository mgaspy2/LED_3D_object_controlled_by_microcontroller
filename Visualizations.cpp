#include <Arduino.h>
#include <FastLED.h>
#include "Visualizations.h"
#include "Timer.h"
#include "Variables.h"



void UAI_vis(uint8_t red, uint8_t green, uint8_t blue) {
  visCounter(&periodCounter0, &periodPassed0);
  if (periodCounter0 < 4) {
    clcLED();
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
        leds0[i] = CRGB(red, green, blue);
        leds1[i] = CRGB(red, green, blue);
        leds2[i] = CRGB(red, green, blue);
        leds3[i] = CRGB(red, green, blue);
        leds4[i] = CRGB(red, green, blue);
        leds5[i] = CRGB(red, green, blue);
        leds6[i] = CRGB(red, green, blue);
        leds7[i] = CRGB(red, green, blue);
      }
    } 
  } else if (periodCounter0 < 6) {
      clcLED();
      for (int i = 0; i < ledsNum; i++) {
        if (ALPHA_U[i] == 1) {
          leds2[i] = CRGB(red, green, blue);
          leds3[i] = CRGB(red, green, blue);
          leds4[i] = CRGB(red, green, blue);
          leds5[i] = CRGB(red, green, blue);
        }
      }
    } else if (periodCounter0 < 8) {
      clcLED();
      for (int i = 0; i < ledsNum; i++) {
        if (ALPHA_A[i] == 1) {
          leds2[i] = CRGB(red, green, blue);
          leds3[i] = CRGB(red, green, blue);
          leds4[i] = CRGB(red, green, blue);
          leds5[i] = CRGB(red, green, blue);
        }
      }
    } else if (periodCounter0 < 10) {
      clcLED();
      for (int i = 0; i < ledsNum; i++) {
        if (ALPHA_I[i] == 1) {
          leds2[i] = CRGB(red, green, blue);
          leds3[i] = CRGB(red, green, blue);
          leds4[i] = CRGB(red, green, blue);
          leds5[i] = CRGB(red, green, blue);
        }
      }
    } else if (periodCounter0 >= 10) {
      Serial.println("VUT visualization passed");
      visCounterReset(&periodCounter0);
    }
  FastLED.show();
}


void RGB_ani(Potentiometer pot) {
  uint32_t ms = millis();
  int32_t yHueDelta32 = ((int32_t)cos16( ms * (27/1) ) * (350 / kMatrixWidth));
  int32_t xHueDelta32 = ((int32_t)cos16( ms * (39/1) ) * (310 / kMatrixHeight));
  DrawOneFrame( ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);
  if( ms < 5000 ) {
    FastLED.setBrightness( scale8( pot.brightness, (ms * 256) / 5000));
  } else {
    FastLED.setBrightness(pot.brightness);
  }
  FastLED.show();
}

void RGB1_ani(Potentiometer pot) {
  uint32_t ms = millis();
  int32_t yHueDelta32 = ((int32_t)cos16( ms * (27/1) ) * (350 / kMatrixWidth));
  int32_t xHueDelta32 = ((int32_t)cos16( ms * (39/1) ) * (310 / kMatrixHeight));
  DrawOneFrame1( ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);
  if( ms < 5000 ) {
    FastLED.setBrightness( scale8( pot.brightness, (ms * 256) / 5000));
  } else {
    FastLED.setBrightness(pot.brightness);
  }
  FastLED.show();
}




void caramelldansen() {
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
}


void RGB_vis() {
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
}


void staticColor(uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < ledsNum; i++) {
    leds0[i] = CRGB(red, green, blue);
    leds1[i] = CRGB(red, green, blue);
    leds2[i] = CRGB(red, green, blue);
    leds3[i] = CRGB(red, green, blue);
    leds4[i] = CRGB(red, green, blue);
    leds5[i] = CRGB(red, green, blue);
    leds6[i] = CRGB(red, green, blue);
    leds7[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}



void clcLED() {
  for (int i = 0; i < ledsNum; i++) {
    leds0[i] = CRGB::Black;
    leds1[i] = CRGB::Black;
    leds2[i] = CRGB::Black;
    leds3[i] = CRGB::Black;
    leds4[i] = CRGB::Black;
    leds5[i] = CRGB::Black;
    leds6[i] = CRGB::Black;
    leds7[i] = CRGB::Black;
  }
}

uint8_t XY (uint8_t x, uint8_t y) {
  // any out of bounds address maps to the first hidden pixel
  if ( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint8_t XYTable[] = {
     7,   8,  23,  24,  39,  40,  55,  56,
     6,   9,  22,  25,  38,  41,  54,  57,
     5,  10,  21,  26,  37,  42,  53,  58,
     4,  11,  20,  27,  36,  43,  52,  59,
     3,  12,  19,  28,  35,  44,  51,  60,
     2,  13,  18,  29,  34,  45,  50,  61,
     1,  14,  17,  30,  33,  46,  49,  62,
     0,  15,  16,  31,  32,  47,  48,  63
  };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = XYTable[i];
  return j;
}

void DrawOneFrame(uint8_t startHue8, int8_t yHueDelta8, int8_t xHueDelta8) {
  uint8_t lineStartHue = startHue8;
  for( uint8_t y = 0; y < kMatrixHeight; y++) {
    lineStartHue += yHueDelta8;
    uint8_t pixelHue = lineStartHue;      
    for( uint8_t x = 0; x < kMatrixWidth; x++) {
      pixelHue += xHueDelta8;
      leds0[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds1[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds2[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds3[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds4[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds5[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds6[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds7[XY(x, y)]  = CHSV( pixelHue, 255, 255);
    }
  }
}

void DrawOneFrame1(uint8_t startHue8, int8_t yHueDelta8, int8_t xHueDelta8) {
  uint8_t lineStartHue = startHue8;
  for( uint8_t y = 0; y < kMatrixHeight; y++) {
    lineStartHue += yHueDelta8;
    uint8_t pixelHue = lineStartHue;      
    for( uint8_t x = 0; x < kMatrixWidth; x++) {
      pixelHue += xHueDelta8;
      leds0[XY(x, y)]  = CHSV( pixelHue, 255, 255);
      leds1[XYcorrection(XY(x, y) + 1)]  = CHSV( pixelHue, 255, 255);
      leds2[XYcorrection(XY(x, y) + 2)]  = CHSV( pixelHue, 255, 255);
      leds3[XYcorrection(XY(x, y) + 3)]  = CHSV( pixelHue, 255, 255);
      leds4[XYcorrection(XY(x, y) + 4)]  = CHSV( pixelHue, 255, 255);
      leds5[XYcorrection(XY(x, y) + 5)]  = CHSV( pixelHue, 255, 255);
      leds6[XYcorrection(XY(x, y) + 6)]  = CHSV( pixelHue, 255, 255);
      leds7[XYcorrection(XY(x, y) + 7)]  = CHSV( pixelHue, 255, 255);
    }
  }
}

uint8_t XYcorrection(uint8_t index) {
  uint8_t i = index;
  if (index >= 63)
    i = index - 63;
  return i;
}
