#include <Arduino.h>
#include "Visualizations.h"
#include "Timer.h"


void UAI_vis(uint8_t red, uint8_t green, uint8_t blue) {
  visCounter(&periodCounter0, &periodPassed0);
  if (periodCounter0 < 4) {
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
      } else {
        leds0[i] = CRGB(red, green, blue);
        leds1[i] = CRGB(red, green, blue);
        leds2[i] = CRGB(red, green, blue);
        leds3[i] = CRGB(red, green, blue);
        leds4[i] = CRGB(red, green, blue);
        leds5[i] = CRGB(red, green, blue);
        leds6[i] = CRGB(red, green, blue);
        leds7[i] = CRGB(red, green, blue);
      }
    }
  } else if (periodCounter0 < 6) {
    clcLED();
    for (int i = 0; i < ledsNum; i++) {
      if (ALPHA_U[i] == 1) {
        leds2[i] = CRGB(red, green, blue);
        leds3[i] = CRGB(red, green, blue);
        leds4[i] = CRGB(red, green, blue);
        leds5[i] = CRGB(red, green, blue);
      }
    }
  } else if (periodCounter0 < 8) {
    clcLED();
    for (int i = 0; i < ledsNum; i++) {
      if (ALPHA_A[i] == 1) {
        leds2[i] = CRGB(red, green, blue);
        leds3[i] = CRGB(red, green, blue);
        leds4[i] = CRGB(red, green, blue);
        leds5[i] = CRGB(red, green, blue);
      }
    }
  } else if (periodCounter0 < 10) {
    clcLED();
    for (int i = 0; i < ledsNum; i++) {
      if (ALPHA_I[i] == 1) {
        leds2[i] = CRGB(red, green, blue);
        leds3[i] = CRGB(red, green, blue);
        leds4[i] = CRGB(red, green, blue);
        leds5[i] = CRGB(red, green, blue);
      }
    }
  } else if (periodCounter0 >= 10) {
    Serial.println("VUT visualization passed");
    visCounterReset(&periodCounter0);
  }
  FastLED.show();
}


void LED_vis(uint8_t bpm, uint8_t fade) {
  uint8_t sinWave0 = beatsin8(bpm, 0, ledsNum - 1, 0, 0);
  uint8_t sinWave1 = beatsin8(bpm, 0, ledsNum - 1, 0, 8);
  uint8_t sinWave2 = beatsin8(bpm, 0, ledsNum - 1, 0, 16);
  uint8_t sinWave3 = beatsin8(bpm, 0, ledsNum - 1, 0, 24);
  uint8_t sinWave4 = beatsin8(bpm, 0, ledsNum - 1, 0, 32);
  uint8_t sinWave5 = beatsin8(bpm, 0, ledsNum - 1, 0, 40);
  uint8_t sinWave6 = beatsin8(bpm, 0, ledsNum - 1, 0, 48);
  uint8_t sinWave7 = beatsin8(bpm, 0, ledsNum - 1, 0, 56);

  leds0[sinWave0] = CRGB::Red;
  fadeToBlackBy(leds0, ledsNum, fade);
  leds1[sinWave1] = CRGB::Orange;
  fadeToBlackBy(leds1, ledsNum, fade);
  leds2[sinWave2] = CRGB::Yellow;
  fadeToBlackBy(leds2, ledsNum, fade);
  leds3[sinWave3] = CRGB::Green;
  fadeToBlackBy(leds3, ledsNum, fade);
  leds4[sinWave4] = CRGB::Blue;
  fadeToBlackBy(leds4, ledsNum, fade);
  leds5[sinWave5] = CRGB::Indigo;
  fadeToBlackBy(leds5, ledsNum, fade);
  leds6[sinWave6] = CRGB::Violet;
  fadeToBlackBy(leds6, ledsNum, fade);
  leds7[sinWave7] = CRGB::White;
  fadeToBlackBy(leds7, ledsNum, fade);
  FastLED.show();
}

void RGB_ani(Potentiometer pot) {
  uint32_t ms = millis();
  int32_t yHueDelta32 = ((int32_t)cos16(ms * (27 / 1)) * (350 / kMatrixWidth));
  int32_t xHueDelta32 = ((int32_t)cos16(ms * (39 / 1)) * (310 / kMatrixHeight));
  DrawOneFrame(ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);
  if (ms < 5000) {
    FastLED.setBrightness(scale8(pot.brightness, (ms * 256) / 5000));
  } else {
    FastLED.setBrightness(pot.brightness);
  }
  FastLED.show();
}

void RGB_aniOffset(Potentiometer pot) {
  uint32_t ms = millis();
  int32_t yHueDelta32 = ((int32_t)cos16(ms * (27 / 1)) * (350 / kMatrixWidth));
  int32_t xHueDelta32 = ((int32_t)cos16(ms * (39 / 1)) * (310 / kMatrixHeight));
  DrawOneFrameOffset(ms / 65536, yHueDelta32 / 32768, xHueDelta32 / 32768);
  if (ms < 5000) {
    FastLED.setBrightness(scale8(pot.brightness, (ms * 256) / 5000));
  } else {
    FastLED.setBrightness(pot.brightness);
  }
  FastLED.show();
}


void caramelldansen() {
  visCounter(&periodCounter1, &periodPassed1);
  if (periodCounter1 < 1) {
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
  } else if (periodCounter1 < 2) {
    for (int i = 0; i < ledsNum; i++) {
      leds0[i] = CRGB::Orange;
      leds1[i] = CRGB::Orange;
      leds2[i] = CRGB::Orange;
      leds3[i] = CRGB::Orange;
      leds4[i] = CRGB::Orange;
      leds5[i] = CRGB::Orange;
      leds6[i] = CRGB::Orange;
      leds7[i] = CRGB::Orange;
    }
  } else if (periodCounter1 < 3) {
    for (int i = 0; i < ledsNum; i++) {
      leds0[i] = CRGB::Yellow;
      leds1[i] = CRGB::Yellow;
      leds2[i] = CRGB::Yellow;
      leds3[i] = CRGB::Yellow;
      leds4[i] = CRGB::Yellow;
      leds5[i] = CRGB::Yellow;
      leds6[i] = CRGB::Yellow;
      leds7[i] = CRGB::Yellow;
    }
  } else if (periodCounter1 < 4) {
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
  } else if (periodCounter1 < 5) {
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
  } else if (periodCounter1 < 6) {
    for (int i = 0; i < ledsNum; i++) {
      leds0[i] = CRGB::Indigo;
      leds1[i] = CRGB::Indigo;
      leds2[i] = CRGB::Indigo;
      leds3[i] = CRGB::Indigo;
      leds4[i] = CRGB::Indigo;
      leds5[i] = CRGB::Indigo;
      leds6[i] = CRGB::Indigo;
      leds7[i] = CRGB::Indigo;
    }
  } else if (periodCounter1 < 7) {
    for (int i = 0; i < ledsNum; i++) {
      leds0[i] = CRGB::Violet;
      leds1[i] = CRGB::Violet;
      leds2[i] = CRGB::Violet;
      leds3[i] = CRGB::Violet;
      leds4[i] = CRGB::Violet;
      leds5[i] = CRGB::Violet;
      leds6[i] = CRGB::Violet;
      leds7[i] = CRGB::Violet;
    }
  } else if (periodCounter1 >= 7) {
    visCounterReset(&periodCounter1);
  }
  FastLED.show();
}


void RGB_vis() {
  visCounter(&periodCounter0, &periodPassed0);
  if (periodCounter0 < 1) {
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
  } else if (periodCounter0 < 2) {
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
  } else if (periodCounter0 < 3) {
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
  } else if (periodCounter0 >= 3) {
    Serial.println("RGB visualization passed");
    visCounterReset(&periodCounter0);
  }
  FastLED.show();
}


void star(unsigned long *lastMil0, unsigned long *lastMil1, unsigned long *lastMil2, unsigned long period0, unsigned long period1, uint8_t chance, Potentiometer pot, int *memory) {
  unsigned long currentMil = millis();
  chance = chance % 100;

  if (currentMil - *lastMil0 >= period0) {
    *lastMil0 = currentMil;

    memory[0] = random(0, 100);
    memory[1] = random(0, 7);
    memory[2] = random(0, 63);
    memory[3] = 0;
  }

  if (currentMil - *lastMil1 >= 10) {
    *lastMil1 = currentMil;

    if (memory[0] >= 100 - chance) {
      if (memory[1] == 0)
        leds0[memory[2]].setRGB(memory[3], memory[3], memory[3]);
      if (memory[1] == 1)
        leds1[memory[2]].setRGB(memory[3], memory[3], memory[3]);
      if (memory[1] == 2)
        leds2[memory[2]].setRGB(memory[3], memory[3], memory[3]);
      if (memory[1] == 3)
        leds3[memory[2]].setRGB(memory[3], memory[3], memory[3]);
      if (memory[1] == 4)
        leds4[memory[2]].setRGB(memory[3], memory[3], memory[3]);
      if (memory[1] == 5)
        leds5[memory[2]].setRGB(memory[3], memory[3], memory[3]);
      if (memory[1] == 6)
        leds6[memory[2]].setRGB(memory[3], memory[3], memory[3]);
      if (memory[1] == 7)
        leds7[memory[2]].setRGB(memory[3], memory[3], memory[3]);

      memory[3] += 1;
      if (memory[3] > 255)
        memory[3] = 255;
    }
  }

  FastLED.show();

  if (currentMil - *lastMil2 >= period1) {
    *lastMil2 = currentMil;
    fadeToBlackBy(leds0, ledsNum, 1);
    fadeToBlackBy(leds1, ledsNum, 1);
    fadeToBlackBy(leds2, ledsNum, 1);
    fadeToBlackBy(leds3, ledsNum, 1);
    fadeToBlackBy(leds4, ledsNum, 1);
    fadeToBlackBy(leds5, ledsNum, 1);
    fadeToBlackBy(leds6, ledsNum, 1);
    fadeToBlackBy(leds7, ledsNum, 1);
  }
}


void stars(unsigned long *lastMil0, unsigned long *lastMil1, unsigned long *lastMil2, unsigned long period0, unsigned long period1, uint8_t chance, Potentiometer pot, int *memory) {
  unsigned long currentMil = millis();
  chance = chance % 100;

  if (currentMil - *lastMil0 >= period0) {
    *lastMil0 = currentMil;
    memory[0] = random(0, 100);
    memory[1] = random(0, 100);
    memory[2] = random(0, 100);
    memory[3] = random(0, 100);
    memory[4] = random(0, 100);
    memory[5] = random(0, 100);
    memory[6] = random(0, 100);
    memory[7] = random(0, 100);

    memory[8] = random(0, 63);
    memory[9] = random(0, 63);
    memory[10] = random(0, 63);
    memory[11] = random(0, 63);
    memory[12] = random(0, 63);
    memory[13] = random(0, 63);
    memory[14] = random(0, 63);
    memory[15] = random(0, 63);

    memory[16] = 0;
  }

  if (currentMil - *lastMil1 >= 10) {
    *lastMil1 = currentMil;

    if (memory[0] >= 100 - chance)
      leds0[memory[8]].setRGB(memory[16], memory[16], memory[16]);
    if (memory[1] >= 100 - chance)
      leds1[memory[9]].setRGB(memory[16], memory[16], memory[16]);
    if (memory[2] >= 100 - chance)
      leds2[memory[10]].setRGB(memory[16], memory[16], memory[16]);
    if (memory[3] >= 100 - chance)
      leds3[memory[11]].setRGB(memory[16], memory[16], memory[16]);
    if (memory[4] >= 100 - chance)
      leds4[memory[12]].setRGB(memory[16], memory[16], memory[16]);
    if (memory[5] >= 100 - chance)
      leds5[memory[13]].setRGB(memory[16], memory[16], memory[16]);
    if (memory[6] >= 100 - chance)
      leds6[memory[14]].setRGB(memory[16], memory[16], memory[16]);
    if (memory[7] >= 100 - chance)
      leds7[memory[15]].setRGB(memory[16], memory[16], memory[16]);

    memory[16] += 1;
    if (memory[16] > 255)
      memory[16] = 255;
  }

  FastLED.show();

  if (currentMil - *lastMil2 >= period1) {
    *lastMil2 = currentMil;
    fadeToBlackBy(leds0, ledsNum, 1);
    fadeToBlackBy(leds1, ledsNum, 1);
    fadeToBlackBy(leds2, ledsNum, 1);
    fadeToBlackBy(leds3, ledsNum, 1);
    fadeToBlackBy(leds4, ledsNum, 1);
    fadeToBlackBy(leds5, ledsNum, 1);
    fadeToBlackBy(leds6, ledsNum, 1);
    fadeToBlackBy(leds7, ledsNum, 1);
  }
}


void staticColor(uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < ledsNum; i++) {
    leds0[i] = CRGB(red, green, blue);
    leds1[i] = CRGB(red, green, blue);
    leds2[i] = CRGB(red, green, blue);
    leds3[i] = CRGB(red, green, blue);
    leds4[i] = CRGB(red, green, blue);
    leds5[i] = CRGB(red, green, blue);
    leds6[i] = CRGB(red, green, blue);
    leds7[i] = CRGB(red, green, blue);
  }
  FastLED.show();
}





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

uint8_t XY(uint8_t x, uint8_t y) {
  // any out of bounds address maps to the first hidden pixel
  if ((x >= kMatrixWidth) || (y >= kMatrixHeight)) {
    return (LAST_VISIBLE_LED + 1);
  }

  const uint8_t XYTable[] = {
    7, 8, 23, 24, 39, 40, 55, 56,
    6, 9, 22, 25, 38, 41, 54, 57,
    5, 10, 21, 26, 37, 42, 53, 58,
    4, 11, 20, 27, 36, 43, 52, 59,
    3, 12, 19, 28, 35, 44, 51, 60,
    2, 13, 18, 29, 34, 45, 50, 61,
    1, 14, 17, 30, 33, 46, 49, 62,
    0, 15, 16, 31, 32, 47, 48, 63
  };

  uint8_t i = (y * kMatrixWidth) + x;
  uint8_t j = XYTable[i];
  return j;
}

uint8_t XYcorrection(uint8_t index) {
  uint8_t i = index;
  if (index > 63)
    i = index - 64;
  return i;
}

void DrawOneFrame(uint8_t startHue8, int8_t yHueDelta8, int8_t xHueDelta8) {
  uint8_t lineStartHue = startHue8;
  for (uint8_t y = 0; y < kMatrixHeight; y++) {
    lineStartHue += yHueDelta8;
    uint8_t pixelHue = lineStartHue;
    for (uint8_t x = 0; x < kMatrixWidth; x++) {
      pixelHue += xHueDelta8;
      leds0[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds1[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds2[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds3[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds4[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds5[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds6[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds7[XY(x, y)] = CHSV(pixelHue, 255, 255);
    }
  }
}

void DrawOneFrameOffset(uint8_t startHue8, int8_t yHueDelta8, int8_t xHueDelta8) {
  uint8_t lineStartHue = startHue8;
  for (uint8_t y = 0; y < kMatrixHeight; y++) {
    lineStartHue += yHueDelta8;
    uint8_t pixelHue = lineStartHue;
    for (uint8_t x = 0; x < kMatrixWidth; x++) {
      pixelHue += xHueDelta8;
      leds0[XY(x, y)] = CHSV(pixelHue, 255, 255);
      leds1[XYcorrection(XY(x, y) + 1)] = CHSV(pixelHue, 255, 255);
      leds2[XYcorrection(XY(x, y) + 2)] = CHSV(pixelHue, 255, 255);
      leds3[XYcorrection(XY(x, y) + 3)] = CHSV(pixelHue, 255, 255);
      leds4[XYcorrection(XY(x, y) + 4)] = CHSV(pixelHue, 255, 255);
      leds5[XYcorrection(XY(x, y) + 5)] = CHSV(pixelHue, 255, 255);
      leds6[XYcorrection(XY(x, y) + 6)] = CHSV(pixelHue, 255, 255);
      leds7[XYcorrection(XY(x, y) + 7)] = CHSV(pixelHue, 255, 255);
    }
  }
}
