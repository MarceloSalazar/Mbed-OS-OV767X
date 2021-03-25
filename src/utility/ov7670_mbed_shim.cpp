// SPDX-License-Identifier: GPL-2.0-only
/*
 * This file is based on the Arduino_OX767X library.
 * https://github.com/arduino-libraries/Arduino_OV767X
 */

#include "mbed.h"

#ifndef OV760_DEBUG
#define OV760_DEBUG
#endif


//I2C i2c(I2C_SDA, I2C_SCL);


extern "C" {
  void msleep(unsigned long ms)
  {
    ThisThread::sleep_for(ms);
  }

  int mbed_i2c_read(unsigned short address, unsigned char reg, unsigned char *value)
  {
#ifdef OV760_DEBUG
    printf("mbed_i2c_read: address = 0x%x", address);
    //printf(address, HEX);
    printf(", reg = 0x%", reg);
    //printf(reg, HEX);
#endif

    // TODO
    //Wire.beginTransmission(address);

    // TODO
    //Wire.write(reg);
    /*
    if (Wire.endTransmission() != 0) {
#ifdef OV760_DEBUG
    Serial.println();
#endif
      return -1;
    }*/

    /*
    if (Wire.requestFrom(address, 1) != 1) {
#ifdef OV760_DEBUG
      Serial.println();
#endif
      return -1;
    }

    *value = Wire.read();
    */

#ifdef OV760_DEBUG
    printf(", value = 0x%x", value);
    //Serial.println(*value, HEX);
#endif

    return 0;
  }

  int mbed_i2c_write(unsigned short address, unsigned char reg, unsigned char value)
  {
#ifdef OV760_DEBUG
    printf("mbed_i2c_write: address = 0x%x", address);
    //printf(address, HEX);
    printf(", reg = 0x%x", reg);
    //printf(reg, HEX);
    printf(", value = 0x%x", value);
    //Serial.println(value, HEX);
#endif

    // TODO
    //Wire.beginTransmission(address);
    //Wire.write(reg);
    //Wire.write(value);
   
    /*
    if (Wire.endTransmission() != 0) {
      return -1;
    }
    */

    return 0;
  }

};