/**************************************************************************/
/*!
    @file     hidkeyboard.ino
    @author   Jason Scheunemann <jason.scheunemann@gmail.com>

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2016, Jason Scheunemann
    All rights reserved.
*/
/**************************************************************************/

//https://github.com/jscheunemann/Button
#include <Button.h>

//https://github.com/jscheunemann/BluetoothHIDKeyboard
#include <BluetoothHIDKeyboard.h>

Button button = Button(12);

BluetoothHIDKeyboard keyboard = BluetoothHIDKeyboard();

void setup(void) {
  button.clickHandler(onClick);
  keyboard.begin();
}


void loop(void) {
  button.read();
}

void onClick(Button &btn) {
  keyboard.sendKeys("Test");
}
