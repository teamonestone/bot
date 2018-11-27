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

////////////7
// defines //
/////////////

//////////////////
// constructors //
//////////////////

bot::bot() {

}

bot::~bot() {
    ;
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