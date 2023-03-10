// Adafruit_NeoMatrix example for tiled NeoPixel matrices.  Scrolls
// 'Howdy' across three 10x8 NeoPixel grids that were created using
// NeoPixel 60 LEDs per meter flex strip.

#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>
#include <Adafruit_NeoPixel.h>
#ifndef PSTR
#define PSTR  // Make Arduino Due happy
#endif

int sensorPin = 14;
int sensorState = 0;
#define PIN 13

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(8, 8, 4, 1, PIN,
                                               NEO_TILE_TOP + NEO_TILE_LEFT + NEO_TILE_COLUMNS + NEO_TILE_PROGRESSIVE + NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
                                               NEO_GRB + NEO_KHZ800);

const uint16_t colors[] = {
  matrix.Color(255, 0, 0), matrix.Color(0, 255, 0), matrix.Color(0, 0, 255)
};

void setup() {
  pinMode(sensorPin, INPUT);
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
  Serial.begin(9600);
}

int x = matrix.width();
int pass = 0;

void loop() {
  sensorState = analogRead(sensorPin);
  //  A slow fade out
  matrix.fillScreen(0);
  matrix.setCursor(x, 0);
  if (--x < -120) {
    x = matrix.width();
    if (++pass >= 3) pass = 0;
    matrix.setTextColor(colors[pass]);
  }

  Serial.println(sensorState);
  if (sensorState == LOW) {
    matrix.print(F("Juan Pablo"));
    matrix.print(F(" Inclinado"));
  } else {
    matrix.print(F("Juan Pablo"));
    matrix.print(F(" No Inclinado"));
  }
  matrix.show();
  delay(100);
}