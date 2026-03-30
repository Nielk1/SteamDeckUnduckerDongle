#include <Arduino.h>
#include "DigiKeyboard.h"

#define MODS (MOD_CONTROL_LEFT | MOD_ALT_LEFT)
#ifndef KEY_SEMICOLON
  #define KEY_SEMICOLON 0x33                 // HID usage code for semicolon
#endif
#define KEY KEY_SEMICOLON

void setup() {
  DigiKeyboard.update();
  delay(4000); // wait for USB to enumerate
}

void loop() {
  // press combo
  DigiKeyboard.sendKeyPress(KEY, MODS);
  DigiKeyboard.update();
  delay(100);

  // release
  DigiKeyboard.sendKeyPress(0, 0);
  DigiKeyboard.update();
  delay(200);

  // repeat forever
}
