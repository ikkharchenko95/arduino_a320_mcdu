#include "McduLskKeys.h"

void setup() {
  initSerial();
  
  initButtons();
}

void loop() {
  processButtons();
}
