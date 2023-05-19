#include <Arduino.h>
#include <FastLED.h>
#include "Visualizations.h"
#include "Timer.h"
#include "Variables.h"



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


// // Params for width and height
// const uint8_t kMatrixWidth = 8;
// const uint8_t kMatrixHeight = 8;

// #define NUM_LEDS (kMatrixWidth * kMatrixHeight)
// CRGB leds[ NUM_LEDS ];
// #define LAST_VISIBLE_LED 63
// uint8_t XY (uint8_t x, uint8_t y) {
//   // any out of bounds address maps to the first hidden pixel
//   if ( (x >= kMatrixWidth) || (y >= kMatrixHeight) ) {
//     return (LAST_VISIBLE_LED + 1);
//   }

//   const uint8_t XYTable[] = {
//      7,   8,  23,  24,  39,  40,  55,  56,
//      6,   9,  22,  25,  38,  41,  54,  57,
//      5,  10,  21,  26,  37,  42,  53,  58,
//      4,  11,  20,  27,  36,  43,  52,  59,
//      3,  12,  19,  28,  35,  44,  51,  60,
//      2,  13,  18,  29,  34,  45,  50,  61,
//      1,  14,  17,  30,  33,  46,  49,  62,
//      0,  15,  16,  31,  32,  47,  48,  63
//   };

//   uint8_t i = (y * kMatrixWidth) + x;
//   uint8_t j = XYTable[i];
//   return j;
// }