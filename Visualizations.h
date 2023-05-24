#pragma once
#include <FastLED.h>
#include "Variables.h"
#include "Controls.h"

// --- Visualization -------------------------
void UAI_vis(uint8_t, uint8_t, uint8_t);

void LED_vis(uint8_t, uint8_t);

void RGB_ani(Potentiometer);
void RGB_aniOffset(Potentiometer);

void caramelldansen();

void RGB_vis();

void star(unsigned long*, unsigned long*, unsigned long*, unsigned long, unsigned long, uint8_t, Potentiometer, int*);
void stars(unsigned long*, unsigned long*, unsigned long*, unsigned long, unsigned long, uint8_t, Potentiometer, int*);

void staticColor(uint8_t, uint8_t, uint8_t);
// --- Utility functions ---------------------
void clcLED();
uint8_t XY(uint8_t, uint8_t);
uint8_t XYcorrection(uint8_t);
void DrawOneFrame(uint8_t, int8_t, int8_t);
void DrawOneFrameOffset(uint8_t, int8_t, int8_t);
// --- Visualization -------------------------

// --- Vis. variables ------------------------
#define LAST_VISIBLE_LED 63
const uint8_t kMatrixWidth = 8;
const uint8_t kMatrixHeight = 8;

const bool gReverseDirection = true;
#define COOLING  55
#define SPARKING 120
// --- Vis. variables ------------------------

// --- VUT LOGO ------------------------------
const int VUT_LOGO[] = {0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0};

// --- ALPHABET ------------------------------
const int ALPHA_A[] = {1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1};

const int ALPHA_B[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0};

const int ALPHA_C[] = {0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0};

const int ALPHA_D[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 0};

const int ALPHA_E[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1};

const int ALPHA_F[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0};

const int ALPHA_G[] = {0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1};

const int ALPHA_H[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const int ALPHA_I[] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0};

const int ALPHA_J[] = {0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};

const int ALPHA_K[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1};

const int ALPHA_L[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};

// const int ALPHA_M[] = {0};

// const int ALPHA_N[] = {0};

// const int ALPHA_O[] = {0};

// const int ALPHA_P[] = {0};

// const int ALPHA_Q[] = {0};

// const int ALPHA_R[] = {0};

// const int ALPHA_S[] = {0};

// const int ALPHA_T[] = {0};

const int ALPHA_U[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 };

// const int ALPHA_V[] = {0};

// const int ALPHA_W[] = {0};

// const int ALPHA_X[] = {0};

// const int ALPHA_Y[] = {0};

// const int ALPHA_Z[] = {0};

// --- alphabet ------------------------------
// const int alpha_a[] = {0};

// const int alpha_b[] = {0};

// const int alpha_c[] = {0};

// const int alpha_d[] = {0};

// const int alpha_e[] = {0};

// const int alpha_f[] = {0};

// const int alpha_g[] = {0};

// const int alpha_h[] = {0};

// const int alpha_i[] = {0};

// const int alpha_j[] = {0};

// const int alpha_k[] = {0};

// const int alpha_l[] = {0};

// const int alpha_m[] = {0};

// const int alpha_n[] = {0};

// const int alpha_o[] = {0};

// const int alpha_p[] = {0};

// const int alpha_q[] = {0};

// const int alpha_r[] = {0};

// const int alpha_s[] = {0};

// const int alpha_t[] = {0};

// const int alpha_u[] = {0};

// const int alpha_v[] = {0};

// const int alpha_q[] = {0};

// const int alpha_x[] = {0};

// const int alpha_y[] = {0};

// const int alpha_z[] = {0};

// --- Numbers -------------------------------
// const int num_1[] = {0};

// const int num_2[] = {0};

// const int num_3[] = {0};

// const int num_4[] = {0};

// const int num_5[] = {0};

// const int num_6[] = {0};

// const int num_7[] = {0};

// const int num_8[] = {0};

// const int num_9[] = {0};

// const int num_0[] = {0};