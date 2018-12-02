/*!
 * @file bot.cpp
 *
 * @mainpage The 'bot' Library
 *
 * @section intro_sec Introduction
 *
 * This is the documentation for the 'bot' library. this library is 
 * designed to work with <a href="https://github.com/team-onestone/ArduinoMegaShields/tree/master/DistributionBoard">
 * this</a> shield for an arduino mega 2560.
 *
 * @section dependencies Dependencies
 *
 * In order to use this library you need to have the <a href="https://www.arduino.cc/en/Reference/Servo">
 * Servo.h</a> Library installed on your system.
 *
 * @section author Author
 *
 * Written by Jonas Merkle [JJM] for Team Onestone.
 *
 * @section license License
 *
 * GNU General Public License v3.0
 *
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

/**
 * Basic constructor for the bot class.
 */
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
    servoDisable(1);
    servoDisable(2);
    servoDisable(3);
    servoDisable(4);
}

/**
 * Basic destructor for the bot class.
 */
bot::~bot() {
    ;
}

/////////////////////
// basic functions //
/////////////////////

/**
 * Read the state of a button.
 * 
 * @param button number of selected button.
 * @retrun 1 if button is pressed, else 0.
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
 * @param button number of selected button.
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
 * @param led number of selected led.
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
 * @param led number of selected led.
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
 * @param pin_mode pin is input -> use INPUT, pin is output -> OUTPUT.
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

/**
 * Read digital value of the selected pin pin.
 * 
 * @param pin number of selected pin.
 * @return 1 if digital pin reads a logic 1, else 0.
 */
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

/**
 * Wirte to the selected digital pin.
 * 
 * @param pin number of selected pin.
 * @param state .
 */
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

/**
 * Read the analog value on the selected pin.
 * 
 * @param pin number of selected pin.
 * @return analog value as integer value from 0 to 1023 from the 10 bit ADC.
 */
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

/**
 * Enables the selected servo pin.
 * 
 * @param pin number of selected servo pin.
 */
void bot::servoEnable(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            digitalWrite(BOT_SE1, 1);
            _SERVO_1_enabled = true;
        break;

        case 2:
            digitalWrite(BOT_SE2, 1);
            _SERVO_2_enabled = true;
        break;

        case 3:
            digitalWrite(BOT_SE3, 1);
            _SERVO_3_enabled = true;
        break;

        case 4:
            digitalWrite(BOT_SE4, 1);
            _SERVO_4_enabled = true;
        break;

        default:
            return;
    }
}

/**
 * Disables the selected servo pin.
 * 
 * @param pin number of selected servo pin.
 */
void bot::servoDisable(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            digitalWrite(BOT_SE1, 0);
            _SERVO_1_enabled = false;
        break;

        case 2:
            digitalWrite(BOT_SE2, 0);
            _SERVO_2_enabled = false;
        break;

        case 3:
            digitalWrite(BOT_SE3, 0);
            _SERVO_3_enabled = false;
        break;

        case 4:
            digitalWrite(BOT_SE4, 0);
            _SERVO_4_enabled = false;
        break;

        default:
            return;
    }
}

/**
 * Checks if a given servo pin is enabled.
 * 
 * @param pin number of selected servo pin.
 * @return 1 if selected servo pin is enabled, else 0.
 */
bool bot::servoEnabled(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return false;

    switch(pin) {
        case 1: 
            return _SERVO_1_enabled;
        break;

        case 2:
            return _SERVO_1_enabled;
        break;

        case 3:
            return _SERVO_1_enabled;
        break;

        case 4:
            return _SERVO_1_enabled;
        break;

        default:
            return false;
    }
}

/**
 * Attach a servo on a given pin.
 * 
 * @param pin number of selected servo pin.
 */
void bot::servoAttach(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            _SERVO_1.attach(BOT_S1);
        break;

        case 2:
            _SERVO_2.attach(BOT_S2);
        break;

        case 3:
            _SERVO_3.attach(BOT_S3);
        break;

        case 4:
            _SERVO_4.attach(BOT_S4);
        break;

        default:
            return;
    }
}

/**
 * Attach a servo on a given pin and set minimum an maximum position values.
 * 
 * @param pin number of selected servo pin.
 * @param min minimum position value of the servo.
 * @param max maximum position value of the servo.
 */
void bot::servoAttach(uint8_t pin, uint16_t min, uint16_t max) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            _SERVO_1.attach(BOT_S1, min, max);
        break;

        case 2:
            _SERVO_2.attach(BOT_S2, min, max);
        break;

        case 3:
            _SERVO_3.attach(BOT_S3, min, max);
        break;

        case 4:
            _SERVO_4.attach(BOT_S4, min, max);
        break;

        default:
            return;
    }
}

/**
 * Checks if a servor is attached to the selected pin.
 * 
 * @param pin number of selected servo pin.
 * @return 1 if selected servo is attached to the pin, else 0.
 */
bool bot::servoAttached(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return false;

    switch(pin) {
        case 1: 
            return _SERVO_1.attached();
        break;

        case 2:
            return _SERVO_2.attached();
        break;

        case 3:
            return _SERVO_3.attached();
        break;

        case 4:
            return _SERVO_4.attached();
        break;

        default:
            return;
    }
}

/**
 * Wirte a new position value in degree to the servo on the selected pin.
 * 
 * @param pin number of selected servo pin.
 * @param angle new position of the selected servo in degree.
 */
void bot::servoWrite(uint8_t pin, uint16_t angle) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            _SERVO_1.write(angle);
        break;

        case 2:
            _SERVO_2.write(angle);
        break;

        case 3:
            _SERVO_3.write(angle);
        break;

        case 4:
            _SERVO_4.write(angle);
        break;

        default:
            return;
    }
}

/**
 * Wirte a new position value in micro-seconds to the servo on the selected pin.
 * 
 * @param pin number of selected servo pin.
 * @param microseconds new position of the selected servo in microseconds.
 */
void bot::servoWriteMicroseconds(uint8_t pin, uint16_t micro_seconds) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            _SERVO_1.writeMicroseconds(micro_seconds);
        break;

        case 2:
            _SERVO_2.writeMicroseconds(micro_seconds);
        break;

        case 3:
            _SERVO_3.writeMicroseconds(micro_seconds);
        break;

        case 4:
            _SERVO_4.writeMicroseconds(micro_seconds);
        break;

        default:
            return;
    }
}

/**
 * Read the current postion of the selected servo.
 * 
 * @param pin number of selected servo pin.
 * @return current position of the selected servo.
 */
uint16_t bot::servoRead(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return 0;

    switch(pin) {
        case 1: 
            return _SERVO_1.read();
        break;

        case 2:
            return _SERVO_2.read();
        break;

        case 3:
            return _SERVO_3.read();
        break;

        case 4:
            return _SERVO_4.read();
        break;

        default:
            return;
    }
}

/**
 * Detach a servo from the selected servo pin.
 * 
 * @param pin number of selected servo pin.
 */
void bot::servoDetach(uint8_t pin) {
    // check if input is in range
    if (pin < 1 || pin > 4) return;

    switch(pin) {
        case 1: 
            _SERVO_1.detach();
        break;

        case 2:
            _SERVO_2.detach();
        break;

        case 3:
            _SERVO_3.detach();
        break;

        case 4:
            _SERVO_4.detach();
        break;

        default:
            return;
    }
}

////////////////////
// util functions //
////////////////////

/**
 * Get the version of the library.
 */
uint16_t bot::get_version() {
    return _lib_version;
}

/**
 * Delay based on millis() (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 */
void bot::delay(uint32_t delay_time) {
    uint64_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait);
}

/**
 * Delay based on micros() (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds.
 */
void bot::micro_delay(uint32_t delay_time) {
    uint64_t time_to_wait = micros() + delay_time;

    while (micros() <= time_to_wait);
}

/**
 * Delay based on millis() with function call during the delay (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 * @param funct function pointer to a void function with a uint64_t argument.
 */
void bot::delay_f(uint32_t delay_time, void (*funct)(uint64_t)) {
    uint64_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait) {
        funct(time_to_wait);
    }
}

/**
 * Delay based on micros() with function call during the delay  (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds.
 * @param funct function pointer to a void function with a uint64_t argument.
 */
void bot::micro_delay_f(uint32_t delay_time, void (*funct)(uint64_t)) {
    uint64_t time_to_wait = micros() + delay_time;

    while (micros() <= time_to_wait) {
        funct(time_to_wait);
    }
}

/**
 * Delay based on millis() with additional break condition (milliseconds resolution).
 * 
 * @param delay_time time to wait in milliseconds.
 * @param funct function pointer to a bool function with a uint64_t argument.
 */
void bot::delay_with_condition(uint32_t delay_time, bool (*condition)(uint64_t)) {
    uint64_t time_to_wait = millis() + delay_time;

    while (millis() <= time_to_wait && condition(time_to_wait));
}

/**
 * Delay based on micros() with additional break condition (microseconds resolution).
 * 
 * @param delay_time time to wait in microseconds
 * @param funct function pointer to a bool function with a uint64_t argument.
 */
void bot::micro_delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t)) {
    uint64_t _time_to_wait = micros() + _delay_time;

    while (micros() <= _time_to_wait && _condition(_time_to_wait));
}