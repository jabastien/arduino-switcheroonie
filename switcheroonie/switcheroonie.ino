/*******************************************************************
 *  A simple Macro keyboard built with Arduino                     *
 *                                                                 *
 *  By Brian Lough                                                 *
 *  https://www.youtube.com/brianlough                             *
 *  https://twitch.tv/brianlough                                   *
 *******************************************************************/


#include <Keypad.h>

#include "Keyboard.h"

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {6, 7, 8, 9 }; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
}

void sendMacroCommand(uint8_t key) {
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(KEY_LEFT_SHIFT);
  Keyboard.press(KEY_LEFT_ALT);
  Keyboard.press(key);
}

void loop() {
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    switch (key) {
      case '1':
        sendMacroCommand(KEY_F1);
        break;
      case '2':
        sendMacroCommand(KEY_F2);
        break;
      case '3':
        sendMacroCommand(KEY_F3);
        break;
      case '4':
        sendMacroCommand(KEY_F4);
        break;
      case '5':
        sendMacroCommand(KEY_F5);
        break;
      case '6':
        sendMacroCommand(KEY_F6);
        break;
      case '7':
        sendMacroCommand(KEY_F7);
        break;
      case '8':
        sendMacroCommand(KEY_F8);
        break;
      case '9':
        sendMacroCommand(KEY_F9);
        break;
      case '0':
        sendMacroCommand(KEY_F10);
        break;
      case '*':
        sendMacroCommand(KEY_F11);
        break;
      case '#':
        sendMacroCommand(KEY_F12);
        break;
      case 'A':
        sendMacroCommand('a');
        break;
      case 'B':
        sendMacroCommand('b');
        break;
      case 'C':
        sendMacroCommand('c');
        break;
      case 'D':
        sendMacroCommand('d');
        break;
    }

    delay(100);
    Keyboard.releaseAll();
  }
}
