#include <bot.h>

bot bot;

int maxPos = 180;
int minPos = 0;

void setup()
{
    Serial.begin(9600);

    bot.servoEnable(1);
    bot.servoAttach(1);
    bot.wait_button(1);
}

void loop () {
    
    for (int i = minPos; i <= maxPos; i++) {

        bot.servoWrite(1, i);

        Serial.print("i = ");
        Serial.println(i);

        delay(50);  
    }

    delay(1000);

    for (int i = maxPos; i >= minPos; i--) {

        bot.servoWrite(1, i);

        Serial.print("i = ");
        Serial.println(i);

        delay(50);  
    }

    delay(1000);
}