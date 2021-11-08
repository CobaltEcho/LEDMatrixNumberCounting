#include <FastLED.h>
#include <OneButton.h>

#define NUM_LEDS  35
#define LED_PIN   6
#define NextShow_PIN   3  
#define NumCountUp_PIN   4

CRGB leds[NUM_LEDS];

uint8_t whichNum = 0;
uint8_t whichShow = 0;

OneButton NextShowBtn(NextShow_PIN, true, true);
OneButton NumCountUpBtn(NumCountUp_PIN, true, true);

void checkTickShow() {
    NextShowBtn.tick();
}
void checkTickNum() {
    NumCountUpBtn.tick(); // just call tick() to check the state.
}

void setup() {
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(100);

  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(NextShow_PIN),checkTickShow,CHANGE);
  attachInterrupt(digitalPinToInterrupt(NumCountUp_PIN),checkTickNum,CHANGE);
  NextShowBtn.attachClick(IncrementNextShow);
  NumCountUpBtn.attachClick(IncrementNumberShow);
}

void loop() {
  NextShowBtn.tick();
  NumCountUpBtn.tick();
  FastLED.show();
}

void IncrementNextShow() {
whichShow = (whichShow + 1) % 3;
DisplayNextShow();
}

void DisplayNextShow() {
  switch (whichShow){
    case 0:
    BlinkShow();
    break;
    case 1:
    FlagShow();
    break;
    case 2:
    DisplayNumberShow();
    break;
  }
}

void IncrementNumberShow() {
whichNum = (whichNum + 1) % 7;
DisplayNumberShow();
}

void DisplayNumberShow() {
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
    case 4:
      Num4();
      break;
    case 5:
      Num5();
      break;
    case 6:
      Num6();
      break;
   }
}
