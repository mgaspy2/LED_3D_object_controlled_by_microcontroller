#include <Arduino.h>
#include <FastLED.h>
#include "Visualizations.h"
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