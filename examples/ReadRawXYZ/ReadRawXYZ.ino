/*
  Author: Jofel Batutay
  Date: July 2023

  XPT2046 Get Raw X, Y and Z
    ------------------------
  | XPT2046PIN   |  ESP32  |
  | MOSI         |   23    |
  | SCK          |   18    |
  | MISO         |   19    | 
  | CS           |   33    | Can be Assign to other pin
  | IRQ          |   32    | Can be Assign to other pin
  --------------------------
*/

#include <Bonezegei_XPT2046.h>

#define TS_CS 33
#define TS_IRQ 32
Bonezegei_XPT2046 ts(TS_CS, TS_IRQ);

void setup() {

  Serial.begin(115200);
  ts.begin();
}

void loop() {

  ts.getInput();

  Serial.print("X: ");
  Serial.print(ts.x);
  Serial.print(" Y: ");
  Serial.print(ts.y);
  Serial.print(" Z: ");
  Serial.println(ts.z);

  delay(10);
}
