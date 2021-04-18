// SPDX-License-Identifier: GPL-2.0-only
/*
 * This file is based on the Arduino_OX767X library.
 * https://github.com/arduino-libraries/Arduino_OV767X
 */

#include "mbed.h"
#include "SoftI2C.h"
#include <chrono>

#ifndef OV760_DEBUG
#define OV760_DEBUG
#endif

SoftI2C i2c(I2C_SDA, I2C_SCL);

extern "C" {
  void msleep(unsigned long time_ms)
  {
    ThisThread::sleep_for((chrono::milliseconds)time_ms);
  }

  int mbed_i2c_read(unsigned int address, unsigned char reg, unsigned char *value)
  { 
    // Write register address
    i2c.start();
    i2c.write(address & ~0x01);
    wait_us(20);
    i2c.write(reg);
    i2c.stop();
    wait_us(20);    
 
    // Read data
    i2c.start();
    i2c.write(address | 0x01);
    wait_us(20);
    *value = i2c.read(0);
    i2c.stop();
 
    return 0;

  }

int mbed_i2c_write(unsigned int address, unsigned char reg, unsigned char value)
  {
    i2c.start();
    i2c.write(address & ~0x01);
    wait_us(20);
    i2c.write(reg);
    wait_us(20);
    i2c.write(value);
    i2c.stop();

    return 0;
  }

};