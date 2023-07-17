/*
  This Library is written for XPT2046
  Author: Bonezegei (Jofel Batutay)
*/
#ifndef _BONEZEGEI_XPT2046_H_
#define _BONEZEGEI_XPT2046_H_
#include <SPI.h>
#include <Arduino.h>

static const int XPT2046_SPISPEED = 1000000;  // 80 MHz

class Bonezegei_XPT2046 {
public:
  Bonezegei_XPT2046();
  Bonezegei_XPT2046(uint8_t cs, uint8_t irq);

  void begin();
  void setCallBack(void (*cb)());
  void getInput();

  uint8_t _cs;
  uint8_t _irq;

  uint16_t x;
  uint16_t y;
  uint16_t z;


  void (*irq_callback)();


  SPIClass *vspi = NULL;
};


#endif