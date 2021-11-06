#include <FastLED.h>
#include <OneButton.h>

#define NUM_LEDS  65
#define LED_PIN   6
#define BTN1_PIN   3  
#define BTN2_PIN   4

CRGB leds[NUM_LEDS];

uint8_t colorIndex[NUM_LEDS];
uint8_t whichNum = 0;

OneButton btn1 = OneButton(BTN1_PIN, true, true);
OneButton btn2 = OneButton(BTN2_PIN, true, true);

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(255);

  Serial.begin(57600);

  btn1.attachClick(NextNum);
  btn2.attachClick(PrevNum);

  //Fill the colorIndex array with random numbers
  for (int i = 0; i < NUM_LEDS; i++) {
    colorIndex[i] = random8();
  }
}

void NextNum() {
  whichNum = (whichNum + 1) % 5;           // Change the number after the % to the number of patterns you have
}

void PrevNum() {
  whichNum = (whichNum + 1) % 5;           // Change the number after the % to the number of patterns you have
}

void loop() {

    switch (whichNum) {
    case 0:
      Num0();
      break;
    case 1:
      Num1();
      break;
    case 2:
      Num2();
      break;
    case 3:
      Num3();
      break;
  }
  

  FastLED.show();
  btn1.tick();
  btn2.tick();
  
}
