
#include <Adafruit_NeoPixel.h>
#define PIN            6
#define NUMLEDS        60
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMLEDS, PIN, NEO_GRB + NEO_KHZ800);
int a = 5;
int j = 0;

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.show();
}


void loop() {
  if (Serial.available() > 0) {
    strip.setBrightness(255);;
    while (a > 1) {
      int inByte = Serial.read();       //read input

      if (inByte == 'a') {
        for (int j = 0; j < 5; j++) {
          colorWipe(strip.Color(255, 0, 0), 20);
          delay(100);
          colorWipe(strip.Color(0, 0, 0), 20);
        }
      }
      else if (inByte == 'b') {
        for (int j = 0; j < 5; j++) {
          colorWipe(strip.Color(0, 255, 0), 20);
          delay(100);
          colorWipe(strip.Color(0, 0, 0), 20);
        }
      }
      else if (inByte == 'c') {
        for (int j = 0; j < 5; j++) {
          colorWipe(strip.Color(0, 0, 255), 20);
          delay(100);
          colorWipe(strip.Color(0, 0, 0), 20);
        }
      }
      else if (inByte == 'd') {
        colorWipe(strip.Color(0, 0, 0), 20);
      }
      else if (inByte == 'e') {
        { for (int i = 0; i < 5; i++)
          { for (int j = 0; j < 60; j++)
            {
              strip.setPixelColor(j, strip.Color(255, 0, 0));
              strip.setPixelColor(j + 1, strip.Color(255, 0, 0));
              strip.setPixelColor(j + 2, strip.Color(255, 0, 0));
              strip.setPixelColor(j + 3, strip.Color(255, 0, 0));
              strip.setPixelColor(j + 4, strip.Color(255, 0, 0));
              strip.setPixelColor(j + 5, strip.Color(255, 0, 0));
              strip.show();
              delay(50);
              strip.setPixelColor(j, strip.Color(0, 0, 0));
              strip.setPixelColor(j + 1, strip.Color(0, 0, 0));
              strip.setPixelColor(j + 2, strip.Color(0, 0, 0));
              strip.setPixelColor(j + 3, strip.Color(0, 0, 0));
              strip.setPixelColor(j + 4, strip.Color(0, 0, 0));
              strip.setPixelColor(j + 5, strip.Color(0, 0, 0));
              strip.show();
            }
          }
        }
      }
      else if (inByte == 'f') {
        theaterChase(strip.Color(255, 0, 0), 20);
        colorWipe(strip.Color(0, 0, 0), 20);
      }
      else if (inByte == 'g') {
        { for (int i = 0; i < 5; i++)
          { for (int j = 0; j < 60; j++)
            {
              strip.setPixelColor(j, strip.Color(255, 0, 0));
              strip.setPixelColor(j + 1, strip.Color(255, 0, 0));;
              strip.setPixelColor(j + 2, strip.Color(255, 0, 0));
              strip.show();
              delay(50);
              strip.setPixelColor(j, strip.Color(0, 0, 0));
              strip.setPixelColor(j + 1, strip.Color(0, 0, 0));
              strip.setPixelColor(j + 2, strip.Color(0, 0, 0));
              strip.show();
            }
          }
        }
      }
      else if (inByte == 'h') {
        for (int l = 0; l < 5; l++) {
          for (int k = 0; k < 256; k = k + 30) {
            colorWipe(strip.Color(0, 0, 0), 0);
            strip.setBrightness(k);
            colorWipe(strip.Color(255, 127, 127), 30);
          }
        }
      }
    }
  }
}

void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 20; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();
      delay(wait);
      for (int i = 0; i < strip.numPixels(); i = i + 2) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

