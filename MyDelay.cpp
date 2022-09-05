/*
  SOURCE FILE
  Gregor's library for "no stop" delay.
  September 2022.
*/

#include "arduino.h"
#include "MyDelay.h"

//Konstruktor. Podam input parameter v private v variablo
MyDelay::MyDelay(unsigned long milliseconds) {
	delaytime = milliseconds;
	preMills = 0;
}

bool MyDelay::execute() {
	curMills = millis();
	if (curMills - preMills >= delaytime) {
		preMills = curMills;
        	return true;
	}
	else {
        	return false;
	}		
}