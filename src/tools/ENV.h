#ifndef __ENV_H
#define __ENV_H

#include <M5StickC.h>
#include "DHT12.h"
#include <Wire.h>
#include "Adafruit_Sensor.h"
#include <Adafruit_BMP280.h>
#include "bmm150.h"
#include "bmm150_defs.h"

void calibrate(uint32_t timeout);
void ENV_setup();
void ENV_loop();

#endif