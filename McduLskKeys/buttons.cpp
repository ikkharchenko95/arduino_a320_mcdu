#include "McduLskKeys.h"

unsigned long lastDebounceTime = 0;
const int debounceDelay = 60;
int lastValidKey = -1;
char lastValidSide = ' ';

void initButtons() {
  pinMode(PIN_LEFT_LSK, INPUT);
  pinMode(PIN_RIGHT_LSK, INPUT);
}

int getButtonNumber(int analogVal) {
  if (analogVal > 950) {
    return -1;
  }
  if (analogVal >= 70  && analogVal < 110) {
    return 6;
  }
  if (analogVal >= 145 && analogVal < 190) {
    return 5;
  }
  if (analogVal >= 215 && analogVal < 250) {
    return 4;
  }
  if (analogVal >= 270 && analogVal < 310) {
    return 3;
  }
  if (analogVal >= 320 && analogVal < 355) {
    return 2;
  }
  if (analogVal >= 360 && analogVal < 400) {
    return 1;
  }
  
  return -1;
}

void processButtons() {
  int leftVal  = analogRead(PIN_LEFT_LSK);
  int rightVal = analogRead(PIN_RIGHT_LSK);

  int currentKey = -1;
  char currentSide = ' ';

  int leftKey  = getButtonNumber(leftVal);
  int rightKey = getButtonNumber(rightVal);

  if (leftKey != -1) {
    currentKey = leftKey;
    currentSide = 'L'; // Left LSK
  } else if (rightKey != -1) {
    currentKey = rightKey;
    currentSide = 'R'; // Right LSK
  }

  if (currentKey != lastValidKey || currentSide != lastValidSide) {
    if (currentKey != -1) {
      String command = currentSide + String(currentKey);
      sendCommand(command);
    }
    
    lastValidKey = currentKey;
    lastValidSide = currentSide;
    delay(debounceDelay); 
  }
}