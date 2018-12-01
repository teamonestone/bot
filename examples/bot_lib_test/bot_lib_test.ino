#include "bot.h"

bot bot;

void setup() {

    // test the functions with fake values
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
    //bot.delay_f(0, null);
    //bot.micro_delay_f(0, null);
    //bot.delay_with_condition(0, null);
    //bot.micro_delay_with_condition(0, null);
  
    bot.wait_button(1);
}

void loop() {
    bot.leds_on();
    bot.delay(500);
    bot.leds_off();
    bot.delay(500);
}