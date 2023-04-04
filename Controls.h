#pragma once


class Button {
  public:
    volatile bool buttonState;
    int buttonPresses;
    int buttonPin;

    Button(int pin) {
      buttonState = false;
      buttonPresses = 0;
      buttonPin = pin;
    }

  inline void Button_ISR(void)
  {
    buttonState = true;
  }

};

class Potentiometer {
  public:
    int potValue;
    int brightness;
    int potPin;

    Potentiometer(int pin) {
      potPin = pin;
    }
};

void controlsOutput(int*, int, Button);

// void controlsOutput(Button);

void controlsOutput(Potentiometer);