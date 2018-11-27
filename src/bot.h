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
#define BOT_A1
#define BOT_A2
#define BOT_A3
#define BOT_A4
#define BOT_A5
#define BOT_A6

// digital ports
#define BOT_D1
#define BOT_D2
#define BOT_D3
#define BOT_D4
#define BOT_D5
#define BOT_D6

// button ports
#define BOT_B1
#define BOT_B2
#define BOT_B3
#define BOT_B4

// servo ports
#define BOT_S1
#define BOT_S2
#define BOT_S3
#define BOT_S4

// led ports 
#define BOT_LED1
#define BOT_BOT_LED2
#define BOT_BOT_LED3
#define BOT_BOT_LED4
#define BOT_BOT_LED5
#define BOT_BOT_LED6

class bot
{
	private:
        uint16_t const _lib_version = 100;
	
	public:

		// Constructor
		bot();
		~bot();
		
		// util functions
        uint16_t get_version();                                         // get the version of the library
		void delay(uint32_t _delay_time);			                    // delay based on millis() (milliseconds resolution)
		void micro_delay(uint32_t _delay_time);		                    // delay based on micros() (microseconds resolution)
        void delay_f(uint32_t _delay_time, void (*_funct)());			// delay based on millis() (milliseconds resolution) with function funct
		void micro_delay_f(uint32_t _delay_time, void (*_funct)()));	// delay based on micros() (microseconds resolution) with funktion funct
};

#endif
