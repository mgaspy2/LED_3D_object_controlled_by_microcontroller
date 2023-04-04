#include "Controls.h"
#include "Visualizations.h"
#include <FastLED.h>


// --- Controls ------------------------------
int cubeMode = 0;
const uint8_t cubeMQ = 2;

Button leftButton(26);
Button rightButton(27);
/*
Button minusButton(14);
Button plusButton(12);
*/
Potentiometer potentiometer(13);
// --- Controls ------------------------------

// --- Visualizations ------------------------
unsigned long millisPeriod = 1000;
unsigned long previousMillis = 0;
int periodCounter = 0;
bool periodPassed = false;
/*
void timer() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= millisPeriod) {
    previousMillis = currentMillis;
    periodPassed = true;
    periodCounter++;
  }
}

void timerReset() {
  periodPassed = false;
}

void counterReset() {
  periodCounter = 0;
}
*/
// --- Visualizations ------------------------

// --- FastLED -------------------------------
#define ledsNum 64

#define ledsPin0 23
#define ledsPin1 22
#define ledsPin2 2
#define ledsPin3 4
#define ledsPin4 21
#define ledsPin5 19
#define ledsPin6 18
#define ledsPin7 5

CRGB leds0[ledsNum];
CRGB leds1[ledsNum];
CRGB leds2[ledsNum];
CRGB leds3[ledsNum];
CRGB leds4[ledsNum];
CRGB leds5[ledsNum];
CRGB leds6[ledsNum];
CRGB leds7[ledsNum];

volatile bool but[2];

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
// --- FastLED -------------------------------

// --- Interupts -----------------------------
void IRAM_ATTR leftButtonInterrupt() {
  leftButton.buttonState = true;
  // leftButton.buttonPresses += 1;  
}

void IRAM_ATTR rightButtonInterrupt() {
  rightButton.buttonState = true;
  
  // rightButton.buttonPresses += 1;
}
/*
void IRAM_ATTR minusButtonInterrupt() {
  minusButton.buttonState = true;
  minusButton.buttonPresses += 1;
}

void IRAM_ATTR plusButtonInterrupt() {
  plusButton.buttonState = true;
  plusButton.buttonPresses += 1;
}
*/
// --- Interupts -----------------------------


void setup() {
  Serial.begin(9600);
  
  // --- Controls ------------------------------
  pinMode(leftButton.buttonPin, INPUT);
  pinMode(rightButton.buttonPin, INPUT);
  /*
  pinMode(minusButton.buttonPin, INPUT);
  pinMode(plusButton.buttonPin, INPUT);
  */
  // --- Controls ------------------------------
  
  // --- FastLED -----------------------------
  FastLED.addLeds<WS2812, 23>(leds0, ledsNum);
  FastLED.addLeds<WS2812, 22>(leds1, ledsNum);
  FastLED.addLeds<WS2812,  2>(leds2, ledsNum);
  FastLED.addLeds<WS2812,  4>(leds3, ledsNum);
  FastLED.addLeds<WS2812, 21>(leds4, ledsNum);
  FastLED.addLeds<WS2812, 19>(leds5, ledsNum);
  FastLED.addLeds<WS2812, 18>(leds6, ledsNum);
  FastLED.addLeds<WS2812,  5>(leds7, ledsNum);
  
  FastLED.setBrightness(50);
  // --- FastLED -----------------------------
  
  // --- Interupts ---------------------------
  attachInterrupt(digitalPinToInterrupt(leftButton.buttonPin),
                  leftButtonInterrupt, 
                  RISING);

  attachInterrupt(digitalPinToInterrupt(rightButton.buttonPin),
                  rightButtonInterrupt, 
                  RISING);
/*
  attachInterrupt(digitalPinToInterrupt(minusButton.buttonPin),
                  minusButtonInterrupt, 
                  RISING);

  attachInterrupt(digitalPinToInterrupt(plusButton.buttonPin),
                  plusButtonInterrupt, 
                  RISING);          
*/
  // --- Interupts ---------------------------  

}


void loop() {
  visTimer(&previousMillis, &millisPeriod, &periodPassed);
  
  // Serial.println("previous millis "); Serial.println(previousMillis); Serial.println();
  // Serial.println("check "); Serial.println(periodPassed); Serial.println();
  // Serial.println("counter "); Serial.println(periodCounter); Serial.println();
  
  controlsOutput(&cubeMode, cubeMQ, leftButton);
  controlsOutput(&cubeMode, cubeMQ, rightButton);
  // Serial.println("cubeMode"); Serial.println(cubeMode); Serial.println();

  /*
  controlsOutput(minusButton);
  controlsOutput(plusButton);
  */
  
  controlsOutput(potentiometer);

  switch (cubeMode) {
    case 0:
      visCounter(&periodCounter, &periodPassed);        
      
      if (periodCounter < 3) {
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
          }
          else {
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
        FastLED.show();
      }
      else if (periodCounter < 5) {
      clcLED();
        for (int i = 0; i < ledsNum; i++) {
          if (ALPHA_U[i] == 1) {
            leds2[i] = CRGB::Blue;
            leds3[i] = CRGB::Blue;
            leds4[i] = CRGB::Blue;
            leds5[i] = CRGB::Blue;
          }            
        }
        FastLED.show();
      }
      else if (periodCounter < 7) {
      clcLED();
        for (int i = 0; i < ledsNum; i++) {
          if (ALPHA_A[i] == 1) {
            leds2[i] = CRGB::Blue;
            leds3[i] = CRGB::Blue;
            leds4[i] = CRGB::Blue;
            leds5[i] = CRGB::Blue;
          }            
        }
        FastLED.show();
      }
      else if (periodCounter < 9) {
      clcLED();
        for (int i = 0; i < ledsNum; i++) {
          if (ALPHA_I[i] == 1) {
            leds2[i] = CRGB::Blue;
            leds3[i] = CRGB::Blue;
            leds4[i] = CRGB::Blue;
            leds5[i] = CRGB::Blue;
          }            
        }
        FastLED.show();          
      }
      else if (periodCounter >= 9){
        Serial.println("counter VUT "); Serial.println(periodCounter); Serial.println();
        visCounterReset(&periodCounter);
        //counterReset();
      }
      break;
      
    case 1:
      visCounter(&periodCounter, &periodPassed);  
      if (periodCounter < 2) {
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
      }
      else if (periodCounter < 4) {
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
      }
      else if (periodCounter < 6) {
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
      }
      else if (periodCounter >= 6){
        Serial.println("counter RGB "); Serial.println(periodCounter); Serial.println();
        visCounterReset(&periodCounter);
        //counterReset();
      }
      break;
  }


  // Serial.println("mode "); Serial.println(cubeMode); Serial.println();
  // Serial.println("working"); Serial.println();
  
  visTimerReset(&periodPassed);  
}
  
  
  

/*
else if (periodCounter < ) {
        for (int i = 0; i < ledsNum; i++) {

        }           
      }
*/