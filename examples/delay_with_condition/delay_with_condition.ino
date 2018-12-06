/*
    bot_delay_example.ino

    this example demonstrate how the delay_with_condition function of the
    bot library can be used. In this case all leds will be on for 5 seconds
    and the turned off for 5 seconds. Each delay can be interrupted by
    pressing button 1.
*/

// include the bot library
#include "bot.h"

// Create an instance of the bot object and initialize it.
bot bot;

// function which provides an additional break condition
// to stop a system delay when button 1 is pressed.
bool breakCondition(uint64_t time) {
    return ~(bot.button(1));        // read the state of button 1 an invert it.
}

// Setup routine which is call once on startup.
void setup() {

    // Setup the serial connection to the computer and send
    // information about this library.
    Serial.begin(9600);
    Serial.print("You are using the 'bot' library version ");
    Serial.print(bot.get_version());
    Serial.println(" provided by Team Onestone (team-onestone.net).");
}

// main loop which is runthrough over an over 
void loop() {
    bot.leds_on();                                      // turn all leds on
    bot.delay_with_condition(5000, &breakCondition);    // waits up to 5 seconds if the breakCondition funktion never returns false
    bot.leds_off();                                     // trun all leds off
    bot.delay_with_condition(5000, &breakCondition);    // waits up to 5 seconds if the breakCondition funktion never returns false
}