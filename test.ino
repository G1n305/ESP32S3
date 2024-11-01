#include <Arduino.h>
#include <WiFi.h>
#include "Wire.h"
#include <Adafruit_NeoPixel.h>
#define LED_PIN 48  
#define NUMPIXELS 1
#define DELAYVAL  10    // Delay time between color changes (lower = faster transitions)

Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Function to fade between RGB colors
void fadeRGB() {
  int r, g, b;
  
  // Fade from Red to Green
  for (r = 255, g = 0, b = 0; g <= 255; g++) {
    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();
    delay(DELAYVAL);
  }
  
  // Fade from Green to Blue
  for (r = 255, g = 255, b = 0; r >= 0; r--) {
    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();
    delay(DELAYVAL);
  }

  // Fade from Blue to Red
  for (r = 0, g = 255, b = 0; b <= 255; b++) {
    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();
    delay(DELAYVAL);
  }

  // Fade from Red back to Green
  for (g = 255, r = 0; g >= 0; g--) {
    pixels.setPixelColor(0, pixels.Color(r, g, 255));
    pixels.show();
    delay(DELAYVAL);
  }

  // Fade from Blue to complete the cycle
  for (r = 0, b = 255, g = 0; r <= 255; r++) {
    pixels.setPixelColor(0, pixels.Color(r, g, b));
    pixels.show();
    delay(DELAYVAL);
  }
}

void setup() {
  pixels.begin();           // Initialize the NeoPixel library
  pixels.setBrightness(100); // Adjust brightness if needed (0-255)
}

void loop() {
  fadeRGB();
}
