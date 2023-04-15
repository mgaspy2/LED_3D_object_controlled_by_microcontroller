#ifndef VARIABLES_H
#define VARIABLES_H


#include <FastLED.h>

// --- Controls ------------------------------
extern int cubeMode;
extern const uint8_t cubeMQ;

extern int modeAttribute;
extern const uint8_t attributeQ;
// --- Controls ------------------------------

// --- Timer ---------------------------------
extern unsigned long previousTime0;
extern unsigned long timePeriod0;
extern bool periodPassed0;
extern int periodCounter0;

extern unsigned long previousTime1;
extern unsigned long timePeriod1;
extern bool periodPassed1;
extern int periodCounter1;
// --- Timer ---------------------------------

// --- FastLED -------------------------------
#define ledsNum  64

#define ledsPin0 23
#define ledsPin1 22
#define ledsPin2  2
#define ledsPin3  4
#define ledsPin4 21
#define ledsPin5 19
#define ledsPin6 18
#define ledsPin7  5

extern CRGB leds[];

extern CRGB leds0[];
extern CRGB leds1[];
extern CRGB leds2[];
extern CRGB leds3[];
extern CRGB leds4[];
extern CRGB leds5[];
extern CRGB leds6[];
extern CRGB leds7[];

extern CRGB letterLeds[];

extern CRGB otherLeds[];
// --- FastLED -------------------------------


#endif