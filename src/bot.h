/*
/////////////////////////////////////////////////////	
/////		  bot Library for Arduino			/////
/////	Copyright (c) 2018 by Jonas J. Merkle	/////
/////	      Version 1.0.0 -27.11.2018- 		/////
/////////////////////////////////////////////////////
*/

#ifndef bot_h
#define bot_h

#include <inttypes.h>
#include <Arduino.h>
#include <Servo.h>

///////////////////////
// some port defines //
///////////////////////

// analog ports 
#define BOT_A1 10
#define BOT_A2 11
#define BOT_A3 12
#define BOT_A4 13
#define BOT_A5 14
#define BOT_A6 15

// digital ports
#define BOT_D1 48
#define BOT_D2 49
#define BOT_D3 46
#define BOT_D4 47
#define BOT_D5 44
#define BOT_D6 45

// button ports
#define BOT_B1 41
#define BOT_B2 40
#define BOT_B3 43
#define BOT_B4 42

// servo ports
#define BOT_S1 12
#define BOT_S2 11
#define BOT_S3 10
#define BOT_S4  9

// servo enable port
#define BOT_SE1 28
#define BOT_SE2 29
#define BOT_SE3 30
#define BOT_SE4 31

// led ports 
#define BOT_LED1 32
#define BOT_LED2 33
#define BOT_LED3 34
#define BOT_LED4 35
#define BOT_LED5 36
#define BOT_LED6 37

class bot
{
	private:
        uint16_t const _lib_version = 100;

		Servo _SERVO_1;
		Servo _SERVO_2;
		Servo _SERVO_3;
		Servo _SERVO_4;
		bool _SERVO_1_enabled;
		bool _SERVO_2_enabled;
		bool _SERVO_3_enabled;
		bool _SERVO_4_enabled;

	public:

		// Constructor
		bot();
		~bot();
		
		// basic functions
		bool button(uint8_t button);				///< Read the state of a button.
		void wait_button(uint8_t button);			///< Wait until a button is pressed.
		void leds_on();								///< Turn all leds on.
		void leds_off();							///< Turn all leds off.
		void led_on(uint8_t led);					///< Turn a specific led on.
		void led_off(uint8_t led);					///< Turn a specific led off.

		// digital io functions
		void set_io_mode(uint8_t pin, uint8_t pin_mode);	///< Set the i/o mode of the selected digital pin.
		bool digital_read(uint8_t pin);						///< Read digital value of the selected pin pin.
		void digital_write(uint8_t pin, bool state);		///< Wirte to the selected digital pin.

		// analog io functions
		uint16_t analog_read(uint8_t pin);			///< read analog pin.

		// servo functions
		void servoEnable(uint8_t pin);				///< Enables the selected servo pin.
		void servoDisable(uint8_t pin);				///< Disables the selected servo pin.
		bool servoEnabled(uint8_t pin);
		void servoAttach(uint8_t pin);
		void servoAttach(uint8_t pin, uint16_t min, uint16_t max);
		bool servoAttached(uint8_t pin);
		void servoWrite(uint8_t pin, uint16_t angle);
		void servoWriteMicroseconds(uint8_t pin, uint16_t micro_seconds);
		uint16_t servoRead(uint8_t pin);
		void servoDetach(uint8_t pin);

		// util functions
        uint16_t get_version();                                         						///< get the version of the library
		void delay(uint32_t _delay_time);			                    						///< delay based on millis() (milliseconds resolution)
		void micro_delay(uint32_t _delay_time);		                    						///< delay based on micros() (microseconds resolution)
        void delay_f(uint32_t _delay_time, void (*_funct)(uint64_t));							///< delay based on millis() (milliseconds resolution) with function funct
		void micro_delay_f(uint32_t _delay_time, void (*_funct)(uint64_t));						///< delay based on micros() (microseconds resolution) with funktion funct
		void delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t));			///< delay based on millis() (milliseconds resolution) with additional break condition
		void micro_delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t));	///< delay based on micros() (microseconds resolution) with additional break condition
};

#endif
