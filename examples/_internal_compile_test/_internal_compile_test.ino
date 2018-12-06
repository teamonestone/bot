/*
    WARNING!!!
    This Example is only used for internal testing of the library.
    It don't represent a propper usecase for this library.

    So please ignore this file!
*/





























































































#include "bot.h"

bot bot;

bool f(uint64_t) {
    return true;  
}

void setup() {

    bot.button(0);
    bot.wait_button(0);
    bot.leds_on();
    bot.leds_off();
    bot.led_on(0);
    bot.led_off(0);

    bot.set_io_mode(0, 0);
    bot.digital_read(0);
    bot.digital_write(0, 0);

    bot.analog_read(0);

    bot.servoEnable(0);
    bot.servoDisable(0);
    bot.servoEnabled(0);
    bot.servoAttach(0);
    bot.servoAttach(0, 0, 0);
    bot.servoAttached(0);
    bot.servoWrite(0, 0);
    bot.servoWriteMicroseconds(0, 0);
    bot.servoRead(0);
    bot.servoDetach(0);

    bot.get_version();
    bot.delay(0);
    bot.micro_delay(0);
    bot.delay_f(0, &f);
    bot.micro_delay_f(0, &f);
    bot.delay_with_condition(0, &f);
    bot.micro_delay_with_condition(0, &f);
}

void loop() {
}