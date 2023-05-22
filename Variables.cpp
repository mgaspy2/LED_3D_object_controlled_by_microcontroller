#include "Variables.h"

// --- Controls ------------------------------
int cubeMode = 0;
const uint8_t cubeMQ = 4;

int modeAttribute = 0;
const uint8_t attributeQ = 3;
// --- Controls ------------------------------

// --- Timer ---------------------------------
unsigned long previousTime0 = 0;
unsigned long timePeriod0 = 1000;
bool periodPassed0 = false;
int periodCounter0 = 0;

unsigned long previousTime1 = 0;
unsigned long timePeriod1 = 100;
bool periodPassed1 = false;
int periodCounter1 = 0;

unsigned long lastMillis = 0;
unsigned long aniFPS120 = 8;
unsigned long aniFPS90 = 11;
unsigned long aniFPS60 = 16;
unsigned long aniFPS30 = 33;
unsigned long aniFPS10 = 100;
// --- Timer ---------------------------------

// --- Visualizations ------------------------
// --- Visualizations ------------------------

// --- FastLED -------------------------------
CRGB leds0[ledsNum];
CRGB leds1[ledsNum];
CRGB leds2[ledsNum];
CRGB leds3[ledsNum];
CRGB leds4[ledsNum];
CRGB leds5[ledsNum];
CRGB leds6[ledsNum];
CRGB leds7[ledsNum];
// --- FastLED -------------------------------