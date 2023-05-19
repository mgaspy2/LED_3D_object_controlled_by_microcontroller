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
