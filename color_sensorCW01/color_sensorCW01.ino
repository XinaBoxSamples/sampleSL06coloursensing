/***************************************************************************
  This is a library for the APDS9960 digital proximity, ambient light, RGB, and gesture sensor

  This sketch puts the sensor in color mode and reads the RGB and clear values.

  Designed specifically to work with the Adafruit APDS9960 breakout
  ----> http://www.adafruit.com/products/3595

  These sensors use I2C to communicate. The device's I2C address is 0x39

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Dean Miller for Adafruit Industries.
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/

#include "Adafruit_APDS9960.h"
#include <xCore.h>
#include <xOD01.h>

Adafruit_APDS9960 apds;

void setup() {
  
  Wire.begin(2, 14);
  OLED.begin();
  Serial.begin(115200);

  if(!apds.begin()){
    OD01.println("failed to initialize device! Please check your wiring.");
  }
  else OD01.println("Device initialized!");

  //enable color sensign mode
  apds.enableColor(true);
}

void loop() {
  //create some variables to store the color data in
  uint16_t r, g, b, c;
  
  //wait for color data to be ready
  while(!apds.colorDataReady()){
    delay(5);
  }

  //get the data and print the different channels
  apds.getColorData(&r, &g, &b, &c);
  OD01.print("red: ");
  OD01.println(r);
  
  OD01.print(" green: ");
  OD01.println(g);
  
  OD01.print(" blue: ");
  OD01.println(b);
  
  OD01.print(" clear: ");
  OD01.println(c);
  OD01.println();
  
  delay(500);
}
