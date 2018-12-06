#include "bot.h"

bot bot;

void setup() {  
    bot.wait_button(1);
}

void loop() {
    bot.leds_on();
    bot.delay(500);
    bot.leds_off();
    bot.delay(500);
}