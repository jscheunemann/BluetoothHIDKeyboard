/**************************************************************************/
/*!
    @file     BluetoothHIDKeyboard.cpp
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

#include "BluetoothHIDKeyboard.h"

BluetoothHIDKeyboard::BluetoothHIDKeyboard() {
  this->deviceName = "Bluefruit Keyboard";
}

BluetoothHIDKeyboard::BluetoothHIDKeyboard(String bluetooth_device_name) {
  this->deviceName = bluetooth_device_name;
}

BluetoothHIDKeyboard::BluetoothHIDKeyboard(int8_t csPin, int8_t irqPin, int8_t rstPin) {
  this->deviceName = "Bluefruit Keyboard";
  this->csPin = csPin;
  this->irqPin = irqPin;
  this->rstPin = rstPin;
}

BluetoothHIDKeyboard::BluetoothHIDKeyboard(String bluetooth_device_name, int8_t csPin, int8_t irqPin, int8_t rstPin) {
  this->deviceName = bluetooth_device_name;
  this->csPin = csPin;
  this->irqPin = irqPin;
  this->rstPin = rstPin;
}

void BluetoothHIDKeyboard::sendKeys(char text[]) {
  char buffer[BUFSIZE];
  sprintf(buffer, "AT+BleKeyboard=%s\\r", text);
  this->ble->println(buffer);
}

void BluetoothHIDKeyboard::begin() {
  this->ble = new Adafruit_BluefruitLE_SPI(this->csPin, this->irqPin, this->rstPin);
  delay(200);
  this->ble->begin(false);
  this->ble->echo(false);

  String devNameString = "AT+GAPDEVNAME=" + this->deviceName;

  this->ble->sendCommandCheckOK(devNameString.c_str());
  this->ble->sendCommandCheckOK(F("AT+BleHIDEn=On"));
}

void BluetoothHIDKeyboard::begin(int8_t csPin, int8_t irqPin, int8_t rstPin) {
  this->csPin = csPin;
  this->irqPin = irqPin;
  this->rstPin = rstPin;

  this->begin();
}

void BluetoothHIDKeyboard::setDeviceName(String bluetooth_device_name) {
  this->deviceName = bluetooth_device_name;

  if (this->ble) {
    String devNameString = "AT+GAPDEVNAME=" + this->deviceName;
    this->ble->sendCommandCheckOK(devNameString.c_str());
  }
}
