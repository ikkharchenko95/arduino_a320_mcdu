#include "McduLskKeys.h"

void initSerial() {
  Serial.begin(9600);
}

void sendCommand(String command) {
  Serial.print(COMMAND_PREFIX);
  Serial.println(command);
}