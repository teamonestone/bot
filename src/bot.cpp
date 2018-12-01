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

    // set the pins to the default values
    leds_off();
    disableServo(1);
    disableServo(2);
    disableServo(3);
    disableServo(4);
}

bot::~bot() {
    ;
}

/////////////////////
// basic functions //
/////////////////////

/**
 * Read the state of a button.
 * 
 * @param button number of selected button
 * @retrun 1 if button is pressed, else 0
 */
bool bot::button(uint8_t button) {
    // check if input is in range
    if (button < 1 || button > 4) return false;

    switch(button) {
        case 1: 
            return ~(digitalRead(BOT_B1));

        case 2:
            return ~(digitalRead(BOT_B2));

        case 3:
            return ~(digitalRead(BOT_B3));

        case 4:
            return ~(digitalRead(BOT_B4));

        default:
            return false;
    }

    // button debounce
    delay(20);
}

/**
 * Wait until a button is pressed.
 * 
 * @param button number of selected button
 */
void bot::wait_button(uint8_t button) {
    // check if input is in range
    if (button < 1 || button > 4) return;

    switch(button) {
        case 1: 
            while(digitalRead(BOT_B1));
        break;

        case 2:
            while(digitalRead(BOT_B2));
        break;

        case 3:
            while(digitalRead(BOT_B3));
        break;

        case 4:
            while(digitalRead(BOT_B4));
        break;

        default:
            return;
    }
    // button debounce
    delay(20);
}

/**
 * Turn all leds on.
 */
void bot::leds_on() {
    digitalWrite(BOT_LED1, 1);
    digitalWrite(BOT_LED2, 1);
    digitalWrite(BOT_LED3, 1);
    digitalWrite(BOT_LED4, 1);
    digitalWrite(BOT_LED5, 1);
    digitalWrite(BOT_LED6, 1);
}

/**
 * Turn all leds off.
 */
void bot::leds_off() {
    digitalWrite(BOT_LED1, 0);
    digitalWrite(BOT_LED2, 0);
    digitalWrite(BOT_LED3, 0);
    digitalWrite(BOT_LED4, 0);
    digitalWrite(BOT_LED5, 0);
    digitalWrite(BOT_LED6, 0);
}

/**
 * Turn a specific led on.
 * 
 * @param led number of selected led
 */
void bot::led_on(uint8_t led) {
    // check if input is in range
    if (led < 1 || led > 6) return;

    switch(led) {
        case 1: 
            digitalWrite(BOT_LED1, 1);
        break;

        case 2:
            digitalWrite(BOT_LED2, 1);
        break;

        case 3:
            digitalWrite(BOT_LED3, 1);
        break;

        case 4:
            digitalWrite(BOT_LED4, 1);
        break;

        case 5:
            digitalWrite(BOT_LED5, 1);
        break;

        case 6:
            digitalWrite(BOT_LED6, 1);
        break;

        default:
            return;
    }
}

/**
 * Turn a specific led off.
 * 
 * @param led number of selected led
 */
void bot::led_off(uint8_t led) {
    // check if input is in range
    if (led < 1 || led > 6) return;

    switch(led) {
        case 1: 
            digitalWrite(BOT_LED1, 0);
        break;

        case 2:
            digitalWrite(BOT_LED2, 0);
        break;

        case 3:
            digitalWrite(BOT_LED3, 0);
        break;

        case 4:
            digitalWrite(BOT_LED4, 0);
        break;

        case 5:
            digitalWrite(BOT_LED5, 0);
        break;

        case 6:
            digitalWrite(BOT_LED6, 0);
        break;

        default:
            return;
    }
}

//////////////////////////
// digital io functions //
//////////////////////////

/**
 * Turn a specific led off.
 * 
 * @param pin number of selected pin.
 * @param pin_mode pin is input -> use INPUT, pin is output -> OUTPUT
 */
void bot::set_io_mode(uint8_t pin, uint8_t pin_mode) {
    // check if input is in range
    if (pin < 1 || pin > 6) return;

    switch(pin) {
        case 1:
            pinMode(BOT_D1, pin_mode);
        break;

        case 2:
            pinMode(BOT_D2, pin_mode);
        break;

        case 3:
            pinMode(BOT_D3, pin_mode);
        break;

        case 4:
            pinMode(BOT_D4, pin_mode);
        break;

        case 5:
            pinMode(BOT_D5, pin_mode);
        break;

        case 6:
            pinMode(BOT_D6, pin_mode);
        break;

        default:
            return;
    }

}

bool bot::digital_read(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 6) return false;

    switch(pin) {
        case 1:
            return digitalRead(BOT_D1);
        
        case 2:
            return digitalRead(BOT_D2);
        
        case 3:
            return digitalRead(BOT_D3);
        
        case 4:
            return digitalRead(BOT_D4);

        case 5:
            return digitalRead(BOT_D5);
        
        case 6:
            return digitalRead(BOT_D6);

        default:
            return false;
    }
}

void bot::digital_write(uint8_t pin, bool state) {
    // check if input is in range
    if (pin < 1 || pin > 6) return;

    switch(pin) {
        case 1: 
            digitalWrite(BOT_D1, state);
        break;

        case 2:
            digitalWrite(BOT_D2, state);
        break;

        case 3:
            digitalWrite(BOT_D3, state);
        break;

        case 4:
            digitalWrite(BOT_D4, state);
        break;

        case 5:
            digitalWrite(BOT_D5, state);
        break;

        case 6:
            digitalWrite(BOT_D6, state);
        break;

        default:
            return;
    }
}

/////////////////////////
// analog io functions //
/////////////////////////

uint16_t bot::analog_read(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 6) return 0;

    switch(pin) {
        case 1:
            return analogRead(BOT_A1);

        case 2:
            return analogRead(BOT_A2);

        case 3:
            return analogRead(BOT_A3);

        case 4:
            return analogRead(BOT_A4);

        case 5:
            return analogRead(BOT_A5);

        case 6:
            return analogRead(BOT_A6);
        
        default:
            return 0;
    }
}

/////////////////////
// servo functions //
/////////////////////

void bot::enableServo(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            digitalWrite(BOT_SE1, 1);
        break;

        case 2:
            digitalWrite(BOT_SE2, 1);
        break;

        case 3:
            digitalWrite(BOT_SE3, 1);
        break;

        case 4:
            digitalWrite(BOT_SE4, 1);
        break;

        default:
            return;
    }
}

void bot::enableServo(uint8_t pin) {
// check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            digitalWrite(BOT_SE1, 0);
        break;

        case 2:
            digitalWrite(BOT_SE2, 0);
        break;

        case 3:
            digitalWrite(BOT_SE3, 0);
        break;

        case 4:
            digitalWrite(BOT_SE4, 0);
        break;

        default:
            return;
    }
}

bool bot::servoEnabled(uint8_t pin);
void bot::servoAttach(uint8_t pin);
void bot::servoAttach(uint8_t pin, uint16_t min, uint16_t max);
bool bot::servoAttached(uint8_t pin);
void bot::servoWrite(uint8_t pin, uint16_t angle);
void bot::servoWriteMicroseconds(uint8_t pin, uint16_t micro_second);
uint16_t bot::servoRead(uint8_t pin);
void bot::servoDetach(uint8_t pin);

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

void bot::delay_f(uint32_t _delay_time, void (*_funct)(uint64_t)) {
    uint64_t _time_to_wait = millis() + _delay_time;

    while (millis() <= _time_to_wait) {
        _funct(_time_to_wait);
    }
}

void bot::micro_delay_f(uint32_t _delay_time, void (*_funct)(uint64_t)) {
    uint64_t _time_to_wait = micros() + _delay_time;

    while (micros() <= _time_to_wait) {
        _funct(_time_to_wait);
    }
}

void bot::delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t)) {
    uint64_t _time_to_wait = millis() + _delay_time;

    while (millis() <= _time_to_wait && _condition(_time_to_wait));
}

void bot::micro_delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t)) {
    uint64_t _time_to_wait = micros() + _delay_time;

    while (micros() <= _time_to_wait && _condition(_time_to_wait));
}