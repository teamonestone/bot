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
#include "Arduino.h"

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
	
	public:

		// Constructor
		bot();
		~bot();
		
		// basic functions
		bool button(uint8_t button);				// get the state of the button
		void wait_button(uint8_t button);			// wait until the button is pressed
		void leds_on();								// turn all leds on
		void leds_off();							// turn all leds off
		void led_on(uint8_t led);					// turn led on
		void led_off(uint8_t led);					// turn led off

		// digital io functions
		void set_io_mode(uint8_t pin, uint8_t pin_mode);	// set io mode
		bool digital_read(uint8_t pin);						// read digital pin
		void digital_write(uint8_t pin, bool state);		// wirte to digital pin

		// analog io functions
		uint16_t analog_read(uint8_t pin);			// read analog pin

		// util functions
        uint16_t get_version();                                         						// get the version of the library
		void delay(uint32_t _delay_time);			                    						// delay based on millis() (milliseconds resolution)
		void micro_delay(uint32_t _delay_time);		                    						// delay based on micros() (microseconds resolution)
        void delay_f(uint32_t _delay_time, void (*_funct)(uint64_t));							// delay based on millis() (milliseconds resolution) with function funct
		void micro_delay_f(uint32_t _delay_time, void (*_funct)(uint64_t)));					// delay based on micros() (microseconds resolution) with funktion funct
		void delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t));			// delay based on millis() (milliseconds resolution) with additional break condition
		void micro_delay_with_condition(uint32_t _delay_time, bool (*_condition)(uint64_t));	// delay based on micros() (microseconds resolution) with additional break condition
};

#endif
