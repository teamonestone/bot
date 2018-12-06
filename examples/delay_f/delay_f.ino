/**
 * Example for the usage of the delay_f() method, because this one uses fuctions pointers which make it a bit more difficult to
 * understand. 
 * @author Dominik
 */

//Never forget including the library!
#include "bot.h";

 /*
  * Creation of the object, which is necessary, sice this libray uses the object oriented paradigm. The main difference to the
  * imperative programming paradigm is, that methods and variables are grouped together to objects. Thus it's not possible do 
  * use the methods definded in the class bot without an instance of the class (except for static methods, which aren't used here). 
  * This can be also seen in the structure when calling such an method, which is "object-name"."method-name" 
  * (compare it to Serial.begin(), you've used object oriented parts all the 
  * time, although the Serial.begin() method is static and therefore needs no real instance of the class Serial. Looking at the line
  * below, the first "bot" stands for the name of the class, and the second "bot" is the name of the new created object. It's almost
  * the same as the creation of primitive variables. All the stuff you can do with them can be also done with objects, e.g. summing 
  * them up in arrays.
  */
bot bot;

/*
 * Showing the compiler the structure of the methods later defined. It's not necessary to specify the names of the params, but 
 * their type is essential. Please be aware, that the structure is the same as stated in der bot.h, where the method delay_f() is 
 * defined. There it's stated, that the method returns nothing (thus type void) and takes on param with the type uint64_t. This type
 * stands for an unsigned integer with 64 bits. 
 */ 
void toTrigger(uint64_t);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Beginning delay");
  //Using a function pointer as param for a method is quite simple, the only thing you need to do is writing the name of the method ;)
  bot.delay_f(500, toTrigger);
  Serial.println("End of Delay");

  //To compare it to the normal delay --> there's nothing triggered while waiting for the end!
  delay(500);
}

/*
 * This is the method we want to trigger whilst waiting until the specified time in the delay has passed. The method receives 
 * the remaining time to the end of the delay (in milliseconds), therefore this method could be used to trigger the ultrasonic
 * measures whilst waiting a certain time. To implement this, there will be also the need of a global variable, which saves, when
 * the last measurement was started. The system time can be evaluated by calling millis().
 */
void toTrigger(uint64_t) {
    Serial.println("Triggered");
}

