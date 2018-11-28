/*
/////////////////////////////////////////////////////	
/////		  bot Library for Arduino			/////
/////	Copyright (c) 2018 by Jonas J. Merkle	/////
/////	      Version 1.0.0 -27.11.2018- 		/////
/////////////////////////////////////////////////////
*/

/////////////
// Include //
/////////////
#include "bot.h"

/////////////
// defines //
/////////////

//////////////////
// constructors //
//////////////////

bot::bot() {

    // set pinMode's
    pinMode(BOT_LED1, OUTPUT);
    pinMode(BOT_LED2, OUTPUT);
    pinMode(BOT_LED3, OUTPUT);
    pinMode(BOT_LED4, OUTPUT);
    pinMode(BOT_LED5, OUTPUT);
    pinMode(BOT_LED6, OUTPUT);

    pinMode(BOT_B1, INPUT_PULLUP);
    pinMode(BOT_B2, INPUT_PULLUP);
    pinMode(BOT_B3, INPUT_PULLUP);
    pinMode(BOT_B4, INPUT_PULLUP);

    pinMode(BOT_S1, OUTPUT);
    pinMode(BOT_S2, OUTPUT);
    pinMode(BOT_S3, OUTPUT);
    pinMode(BOT_S4, OUTPUT);

    pinMode(BOT_SE1, OUTPUT);
    pinMode(BOT_SE2, OUTPUT);
    pinMode(BOT_SE3, OUTPUT);
    pinMode(BOT_SE4, OUTPUT);
}

bot::~bot() {
    ;
}
/////////////////////
// basic functions //
/////////////////////

bool button(uint8_t button) {
    // check if input is in range
    if (button < 1 || button > 4) return false;
}

void wait_botton(uint8_t button) {
    // check if input is in range
    if (button < 1 || button > 4) return;
}

void leds_on() {
    
}

void leds_off() {

}

void led_on(uint8_t led) {
    // check if input is in range
    if (led < 1 || led > 6) return;
}

void led_off(uint8_t led) {
    // check if input is in range
    if (led < 1 || led > 6) return;
}

//////////////////////////
// digital io functions //
//////////////////////////

void set_io_mode(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 6) return;
}

bool digital_read(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 6) return false;
}

void digital_write(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 6) return;
}

/////////////////////////
// analog io functions //
/////////////////////////

uint16_t analog_read(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 6) return 0;
}

////////////////////
// util functions //
////////////////////

uint16_t bot::get_version() {
    return _lib_version;
}

void bot::delay(uint32_t _delay_time) {
    uint64_t _time_to_wait = millis() + _delay_time;

    while (millis() <= _time_to_wait);
}

void bot::micro_delay(uint32_t _delay_time) {
    uint64_t _time_to_wait = micros() + _delay_time;

    while (micros() <= _time_to_wait);
}

void bot::delay_f(uint32_t _delay_time, void (*_funct)()) {
    uint64_t _time_to_wait = millis() + _delay_time;

    while (millis() <= _time_to_wait) {
        _funct();
    }
}

void bot::micro_delay_f(uint32_t _delay_time, void (*_funct)())) {
    uint64_t _time_to_wait = micros() + _delay_time;

    while (micros() <= _time_to_wait) {
        _funct();
    }
}