/*!
 * @file bot.h
 *
 * This is the documentation for the 'bot' library. The library is 
 * designed to work with <a href="https://github.com/team-onestone/ArduinoMegaShields/tree/master/DistributionBoard">
 * this</a> shield for an arduino mega 2560.
 * 
 * Written by Jonas Merkle [JJM] for Team Onestone.
 * 
 * GNU General Public License v3.0
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
#define BOT_A1 10		///< Port A1 on the shield mapped to arduino analog pin 10.
#define BOT_A2 11		///< Port A2 on the shield mapped to arduino analog pin 11.
#define BOT_A3 12		///< Port A3 on the shield mapped to arduino analog pin 12.
#define BOT_A4 13		///< Port A4 on the shield mapped to arduino analog pin 13.
#define BOT_A5 14		///< Port A5 on the shield mapped to arduino analog pin 14.
#define BOT_A6 15		///< Port A6 on the shield mapped to arduino analog pin 15.

// digital ports
#define BOT_D1 48		///< Port D1 on the shield mapped to arduino digital pin 48.
#define BOT_D2 49		///< Port D2 on the shield mapped to arduino digital pin 49.
#define BOT_D3 46		///< Port D3 on the shield mapped to arduino digital pin 46.
#define BOT_D4 47		///< Port D4 on the shield mapped to arduino digital pin 47.
#define BOT_D5 44		///< Port D5 on the shield mapped to arduino digital pin 44.
#define BOT_D6 45		///< Port D6 on the shield mapped to arduino digital pin 45.

// button ports
#define BOT_B1 41		///< Button 1 on the shield mapped to arduino digital pin 41.
#define BOT_B2 40		///< Button 2 on the shield mapped to arduino digital pin 40.
#define BOT_B3 43		///< Button 3 on the shield mapped to arduino digital pin 43.
#define BOT_B4 42		///< Button 4 on the shield mapped to arduino digital pin 42.

// servo ports
#define BOT_S1 12 		///< Servo port 1 on the shield mapped to arduino digital pin 12.
#define BOT_S2 11		///< Servo port 2 on the shield mapped to arduino digital pin 11.
#define BOT_S3 10		///< Servo port 3 on the shield mapped to arduino digital pin 10.
#define BOT_S4  9		///< Servo port 4 on the shield mapped to arduino digital pin 9.

// servo enable port
#define BOT_SE1 28		///< Servo enable port 1 on the shield mapped to arduino digital pin 28.
#define BOT_SE2 29		///< Servo enable port 2 on the shield mapped to arduino digital pin 29.
#define BOT_SE3 30		///< Servo enable port 3 on the shield mapped to arduino digital pin 30.
#define BOT_SE4 31		///< Servo enable port 4 on the shield mapped to arduino digital pin 31.

// led ports 
#define BOT_LED1 32		///< LED 1 on the shield mapped to arduino digital pin 32.
#define BOT_LED2 33		///< LED 2 on the shield mapped to arduino digital pin 33.
#define BOT_LED3 34		///< LED 3 on the shield mapped to arduino digital pin 34.
#define BOT_LED4 35		///< LED 4 on the shield mapped to arduino digital pin 35.
#define BOT_LED5 36		///< LED 5 on the shield mapped to arduino digital pin 36.
#define BOT_LED6 37		///< LED 6 on the shield mapped to arduino digital pin 37.

/**
 * The main bot class.
 */
class bot				///< The main bot class.
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
		bot();				///< Basic constructor for the bot class.
		~bot();				///< Basic destructor for the bot class.
		
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
		uint16_t analog_read(uint8_t pin);			///< Read the analog value on the selected pin.

		// servo functions
		void servoEnable(uint8_t pin);										///< Enables the selected servo pin.
		void servoDisable(uint8_t pin);										///< Disables the selected servo pin.
		bool servoEnabled(uint8_t pin);										///< Checks if a given servo pin is enabled.
		void servoAttach(uint8_t pin);										///< Attach a servo on a given pin.
		void servoAttach(uint8_t pin, uint16_t min, uint16_t max);			///< Attach a servo on a given pin and set minimum an maximum position values.
		bool servoAttached(uint8_t pin);									///< Checks if a servor is attached to the selected pin.
		void servoWrite(uint8_t pin, uint16_t angle);						///< Wirte a new position value in degree to the servo on the selected pin.
		void servoWriteMicroseconds(uint8_t pin, uint16_t micro_seconds);	///< Wirte a new position value in micro-seconds to the servo on the selected pin.
		uint16_t servoRead(uint8_t pin);									///< Read the current postion of the selected servo.
		void servoDetach(uint8_t pin);										///< Detach a servo from the selected servo pin.

		// util functions
        uint16_t get_version();                                         						///< Get the version of the library.
		void delay(uint32_t delay_time);			                    						///< Delay based on millis() (milliseconds resolution).
		void micro_delay(uint32_t delay_time);		                    						///< Delay based on micros() (microseconds resolution).
        void delay_f(uint32_t delay_time, void (*funct)(uint64_t));								///< Delay based on millis() with function call during the delay (milliseconds resolution).
		void micro_delay_f(uint32_t delay_time, void (*funct)(uint64_t));						///< Delay based on micros() with function call during the delay  (microseconds resolution).
		void delay_with_condition(uint32_t delay_time, bool (*condition)(uint64_t));			///< Delay based on millis() with additional break condition (milliseconds resolution).
		void micro_delay_with_condition(uint32_t delay_time, bool (*condition)(uint64_t));		///< Delay based on micros() with additional break condition (microseconds resolution).
};

#endif
