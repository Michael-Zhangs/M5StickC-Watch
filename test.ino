/*
    note: need add library Adafruit_BMP280 from library manage
    Github: https://github.com/adafruit/Adafruit_BMP280_Library
*/

#include "main.h"

void setup()
{
  M5.begin();
  M5.Lcd.setRotation(3);
}

void Clock()
{

}

void tools()
{
  menu_loop(Lighting_loop,"Lighting",IMU_loop,"IMU",ENV_loop,"ENV",Clock,"CLOCK");
}

void settings()
{

}

void Wireless()
{

}

void wake()
{
  M5.Axp.SetSleep(); 
}

void loop()
{
  menu_loop(tools,"tools",settings,"settings",Wireless,"Wireless",wake,"wake");
}
