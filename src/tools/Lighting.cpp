#include "Lighting.h"

void Lighting_setup()
{
    M5.begin();
    M5.Lcd.fillScreen(WHITE);
    pinMode(M5_BUTTON_HOME, INPUT);
    pinMode(G39, INPUT);
}

void Lighting_loop()
{
    Lighting_setup();
    int i = 7;
    while(true)
    {
    if(digitalRead(M5_BUTTON_HOME) == LOW){
        while(digitalRead(M5_BUTTON_HOME) == LOW);
        M5.Axp.ScreenBreath(i++);
        if (i > 15) i = 7;
    }
    if(digitalRead(G39) == LOW){
    while(digitalRead(G39) == LOW);
    return;
    }
    delay(50);
    }
}
