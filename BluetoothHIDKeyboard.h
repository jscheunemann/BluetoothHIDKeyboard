/**************************************************************************/
/*!
    @file     BluetoothHIDKeyboard.h
    @author   Jason Scheunemann <jason.scheunemann@gmail.com>

    @section LICENSE

    Software License Agreement (BSD License)

    Copyright (c) 2016, Jason Scheunemann
    All rights reserved.

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions are met:
    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.
    3. Neither the name of the copyright holders nor the
    names of its contributors may be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS ''AS IS'' AND ANY
    EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
    WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER BE LIABLE FOR ANY
    DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
    (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
    ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
    (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
    SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
/**************************************************************************/

#ifndef BluetoothHIDKeyboard_h
#define BluetoothHIDKeyboard_h

#include <Arduino.h>
#include <stdlib.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"

#define BUFSIZE 128

#ifdef Serial1    // this makes it not complain on compilation if there's no Serial1
  #define BLUEFRUIT_HWSERIAL_NAME      Serial1
#endif

class BluetoothHIDKeyboard {
  public:
    BluetoothHIDKeyboard();
    BluetoothHIDKeyboard(int8_t csPin, int8_t irqPin, int8_t rstPin);
    void BluetoothHIDKeyboard::sendKeys(char text[]);
    void BluetoothHIDKeyboard::begin();
    void BluetoothHIDKeyboard::begin(int8_t csPin, int8_t irqPin, int8_t rstPin);

  private:
    Adafruit_BluefruitLE_SPI* ble;
    int8_t csPin = 8;
    int8_t irqPin = 7;
    int8_t rstPin = 6;

};

#endif
