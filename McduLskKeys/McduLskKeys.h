#ifndef MCDU_LSK_KEYS_H
#define MCDU_LSK_KEYS_H

#include <Arduino.h>

#define COMMAND_PREFIX "MCDU:"

const int PIN_LEFT_LSK  = A3; // Left matrix (LSK L1 - L6)
const int PIN_RIGHT_LSK = A0; // Right matrix (LSK R1 - R6)

// Process buttons
void initButtons();
int getButtonNumber(int analogVal);
void processButtons();

// Process serial
void initSerial();
void sendCommand(String command);

#endif