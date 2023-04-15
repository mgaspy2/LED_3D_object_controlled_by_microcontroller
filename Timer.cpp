#include <Arduino.h>
#include <FastLED.h>
#include "Timer.h"
#include "Variables.h"


void visTimer(unsigned long *previous, unsigned long *period, bool *check) {
  unsigned long current = millis();
  if (current - *previous >= *period) {
    *previous = current;
    *check = true;
  }
}

void visTimerReset(bool *check) {
  if(*check)
    *check = false;
}

void visCounter(int *counter, bool *check) {
  if (*check == true) {
    *counter += 1;
  }
}

void visCounterReset(int *counter) {
  if(*counter != 0)
    *counter = 0;
}

// --- Timer ---------------------------------

void visTimer0() {
  unsigned long current = millis();
  if (current - previousTime0 >= timePeriod0) {
    previousTime0 = current;
    periodPassed0 = true;
  }
}

void visTimerReset0() {
  if(periodPassed0)
    periodPassed0 = false;
}

void visCounter0() {
  if (periodPassed0 == true) {
    periodCounter0 += 1;
  }
}

void visCounterReset0() {
  if(periodCounter0 != 0)
    periodCounter0 = 0;
}













