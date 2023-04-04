#include "HardwareSerial.h"
#include <Arduino.h>
#include <FastLED.h>
#include "Visualizations.h"


void visTimer(unsigned long *previous, unsigned long* period, bool *check) {
  unsigned long current = millis();
  if (current - *previous >= *period) {
    // Serial.println("Counter condition Y"); Serial.println();
    *previous = current;
    *check = true;
  }
}

/*
void visTimer(unsigned long *previous, long period, volatile bool *check, volatile int *counter) {
  unsigned long current = millis();
  if (current - *previous >= period) {
    *previous = current;
    *check = true;
    *counter++;
  }
}
*/

void visTimerReset(bool *check) {
  // Serial.println("vis timer reset passed"); Serial.println();
  *check = false;
  // Serial.println("check "); Serial.println(*check); Serial.println();
}

void visCounter(int *counter, bool *check) {
  if (*check == true){
    // Serial.println("vis counter passed"); Serial.println();
    *counter += 1;
    // Serial.println("counter "); Serial.println(*counter); Serial.println();
  }
}

void visCounterReset(int *counter) {
  *counter = 0;
  // Serial.println("vis counter reset passed"); Serial.println();
  // Serial.println("counter "); Serial.println(*counter); Serial.println();
}
