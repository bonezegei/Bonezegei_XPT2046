/*
  This Library is written for XPT2046
  Author: Bonezegei (Jofel Batutay)
*/
#include "Bonezegei_XPT2046.h"


Bonezegei_XPT2046::Bonezegei_XPT2046() {
}

Bonezegei_XPT2046::Bonezegei_XPT2046(uint8_t cs, uint8_t irq) {
  _cs = cs;
  _irq = irq;
}

Bonezegei_XPT2046::Bonezegei_XPT2046(uint8_t cs) {
  _cs = cs;
}

void Bonezegei_XPT2046::begin() {
  vspi = new SPIClass(VSPI);
  vspi->begin();
  vspi->setFrequency(XPT2046_SPISPEED);
  vspi->setDataMode(SPI_MODE0);
  vspi->setBitOrder(MSBFIRST);

  pinMode(_cs, OUTPUT);
  /*   pinMode(_irq, INPUT);
  attachInterrupt(digitalPinToInterrupt(_irq), irq_callback, FALLING); */
}

void Bonezegei_XPT2046::setCallBack(void (*cb)()) {
  irq_callback = cb;
}


uint8_t Bonezegei_XPT2046::getInput() {

  vspi->setFrequency(XPT2046_SPISPEED);
  digitalWrite(_cs, LOW);
  vspi->transfer(0xB1);
  int16_t z1 = vspi->transfer16(0xC1) >> 3;
  int16_t z2 = vspi->transfer16(0x91) >> 3;
  x = vspi->transfer16(0xD0) >> 3;
  y = vspi->transfer16(0) >> 3;
  digitalWrite(_cs, HIGH);
  z = z1 + 4095 - z2;

  if (z > 500) {
    return 1;
  } else {
    return 0;
  }
}
