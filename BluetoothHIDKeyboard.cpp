#include "BluetoothHIDKeyboard.h"

BluetoothHIDKeyboard::BluetoothHIDKeyboard() { }

BluetoothHIDKeyboard::BluetoothHIDKeyboard(int8_t csPin, int8_t irqPin, int8_t rstPin) {
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

  this->ble->sendCommandCheckOK(F("AT+GAPDEVNAME=BluefruitKeyboard"));
  this->ble->sendCommandCheckOK(F("AT+BleHIDEn=On"));
}

void BluetoothHIDKeyboard::begin(int8_t csPin, int8_t irqPin, int8_t rstPin) {
  this->csPin = csPin;
  this->irqPin = irqPin;
  this->rstPin = rstPin;

  this->begin();
}
