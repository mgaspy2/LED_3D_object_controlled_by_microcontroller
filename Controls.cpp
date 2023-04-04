#include <Arduino.h>
#include <FastLED.h>
#include "Visualizations.h"
#include "Controls.h"


void controlsOutput(int *mode, int num, Button but) {
  if (but.buttonState && but.buttonPin == 26){
    Serial.println("left button push"); Serial.println();
    but.buttonState = false;
    *mode -= 1;
    if (*mode < 0)
      *mode = num - 1;
    else if (*mode > num - 1)
      *mode = 0;
    Serial.println("left button reset"); Serial.println();
  }
  else if (but.buttonState && but.buttonPin == 27){
    Serial.println("right button push"); Serial.println();
    but.buttonState = false;
    *mode += 1;
    if (*mode < 0)
      *mode = num - 1;
    else if (*mode > num - 1)
      *mode = 0;
    Serial.println("right button reset"); Serial.println();
  }
}


// void controlsOutput(Button but) {
//   if (but.buttonState == true && but.buttonPin == 14){
    
//   }
//   else if (but.buttonState == true && but.buttonPin == 12){
    
//   }
// }


void controlsOutput(Potentiometer pot) {
  pot.potValue = analogRead(pot.potPin);
  pot.brightness = map(pot.potValue, 0, 4095, 0, 255);
  FastLED.setBrightness(pot.brightness);
}