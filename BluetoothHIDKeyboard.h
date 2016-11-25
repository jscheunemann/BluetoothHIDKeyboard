#ifndef BluetoothHIDKeyboard_h
#define BluetoothHIDKeyboard_h

#include <Arduino.h>
#include <stdlib.h>
#include <SPI.h>
#include "Adafruit_BLE.h"
#include "Adafruit_BluefruitLE_SPI.h"

#define BUFSIZE 128
#define BLUEFRUIT_SPI_CS 8
#define BLUEFRUIT_SPI_IRQ 7
#define BLUEFRUIT_SPI_RST 6

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
