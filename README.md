# A320 MCDU LSK buttons

## Description
Reads press from tact buttons from two 6-button keyboard.

Each button has its own 10 kOhm resistor and common ground, with 10 kOhm pullup resistor.

While the button is pressed, a command is sent to the serial port: "MCDU:LSK:1L" (or 1R if it is right matrix).