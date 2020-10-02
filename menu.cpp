#include "menu.h"

float menu_map(float a, float aMax, float aMin, float bMax, float bMin)
{
  float b;
  b=(a-aMin)/(aMax-aMin)*(bMax-bMin)+bMin;
  return b;
}

void menu_select(int f,bool flag)
{
  switch(f)
  {
    case 1:
      M5.Lcd.drawRect(80, 0, 80, 40, flag?BLUE:BLACK);
      break;
    case 2:
      M5.Lcd.drawRect(0, 0, 80, 40, flag?BLUE:BLACK);
      break;
    case 3:
      M5.Lcd.drawRect(0, 40, 80, 40, flag?BLUE:BLACK);
      break;
    case 4:
      M5.Lcd.drawRect(80, 40, 80, 40, flag?BLUE:BLACK);
      break;
  }
}

void menu_setup()
{
    pinMode(M5_BUTTON_HOME, INPUT);
    pinMode(G39, INPUT);
    M5.IMU.Init();
    M5.Lcd.setTextSize(0);
}

void menu_loop(void(*fuc1)(),char str1[],void(*fuc2)(),char str2[],void(*fuc3)(),char str3[],void(*fuc4)(),char str4[])
{
  menu_setup();
  float accX = 0.0F;
  float accY = 0.0F;
  float accZ = 0.0F;
  int x,y,x_d,y_d;
  int old = 0xff;
  while(1)
  {
    M5.IMU.getAccelData(&accX,&accY,&accZ);
    //M5.Lcd.fillScreen(BLACK);
    M5.Lcd.setCursor(0+5, 0+5);//2
    M5.Lcd.print(str1);
    M5.Lcd.setCursor(80+5, 0+5);//1
    M5.Lcd.print(str2);
    M5.Lcd.setCursor(0+5, 40+5);//3
    M5.Lcd.print(str3);
    M5.Lcd.setCursor(80+5, 40+5);//4
    M5.Lcd.print(str4);
    x_d = x;
    y_d = y;
    y = (int)menu_map(accX, 1.13, -0.87, 80, 0);
    x = (int)menu_map(accY, 1.19, -0.81, 160, 0);
    if(x<80)
      if(y<40)//2
        if(old!=2)
        {
          menu_select(old,false);
          old = 2;
          menu_select(old,true);
        }
        else{}
      else//3
        if(old!=3)
        {
          menu_select(old,false);
          old = 3;
          menu_select(old,true);
        }
        else{}
    else
      if(y<40)//1
        if(old!=1)
        {
          menu_select(old,false);
          old = 1;
          menu_select(old,true);
        }
        else{}
      else//4
        if(old!=4)
        {
          menu_select(old,false);
          old = 4;
          menu_select(old,true);
        }
        else{}
    if(digitalRead(M5_BUTTON_HOME) == LOW)
    {
      while(digitalRead(M5_BUTTON_HOME) == LOW);
      switch(old)
      {
        case 1:
          fuc2();
          break;
        case 2:
          fuc1();
          break;
        case 3:
          fuc3();
          break;
        case 4:
          fuc4();
          break;
      }
      M5.Lcd.fillScreen(BLACK);
      M5.Lcd.setCursor(0+5, 0+5);//2
      M5.Lcd.print(str1);
      M5.Lcd.setCursor(80+5, 0+5);//1
      M5.Lcd.print(str2);
      M5.Lcd.setCursor(0+5, 40+5);//3
      M5.Lcd.print(str3);
      M5.Lcd.setCursor(80+5, 40+5);//4
      M5.Lcd.print(str4);
    }
    if(x_d != x || y_d != y)
    {
      M5.Lcd.drawPixel(x_d,y_d,BLACK);
      M5.Lcd.drawPixel(x,y,GREEN);
    }
    if(digitalRead(G39) == LOW)
    {
      while(digitalRead(G39) == LOW);
      return;
    }
  }
}
