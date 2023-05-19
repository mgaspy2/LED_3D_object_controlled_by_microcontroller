#ifndef CONTROLS_H
#define CONTROLS_H


// --- Button --------------------------------
class Button {
public:
  bool buttonState;
  int buttonPresses;
  const uint8_t buttonPin;
  unsigned long lastTime = 0;

  Button(int pin)
    : buttonPin(pin) {
    buttonState = false;
    buttonPresses = 0;
    pinMode(buttonPin, INPUT);
    buttonState = digitalRead(buttonPin);
  }

  bool isPressed();

  void controlsOutput(int*, const uint8_t*);

  void controlsOutput(int*);
};
// --- Button utilities ----------------------
void attributeCheck(int*, const uint8_t);
void attributeReset(int*);
// --- Button --------------------------------


// --- Potentiometer -------------------------
class Potentiometer {
private:
  int potValueOld = 0;
public:
  int potValue;
  int brightness;
  int potPin;

  Potentiometer(int pin) {
    potPin = pin;
  }

  void controlsOutput();
};
// --- Potentiometer -------------------------
#endif