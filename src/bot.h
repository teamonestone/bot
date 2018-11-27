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
