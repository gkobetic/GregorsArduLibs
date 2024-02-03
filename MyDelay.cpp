/*
  SOURCE FILE
  Gregor's library for "no stop" delay.
  September 2022.
*/

#include "arduino.h"
#include "MyDelay.h"

//Constructor
MyDelay::MyDelay(unsigned long milliseconds) {
	delaytime = milliseconds; //Set input parameter in private variable
	preMills = millis();
	canExecute = false; //Parameter for executing the time interval
}

//Main logic
bool MyDelay::isInterval() {
	if (!canExecute) return false; //If this parameter is false than we don't execute the code

	//Calcualte when time interval expires
	curMills = millis();
	if (preMills > curMills) preMills = 0; //Safety if millis() overflows
	if (curMills - preMills >= delaytime) {
		if(_resetMillis) preMills = curMills;
        return true;
	}
	else {
        return false;
	}		
}

//Method to start calculating intervals
void MyDelay::start(bool resetTimer = true) {
	_resetMillis = resetTimer; //if false then preMills will never reset automatically. Usefull for countdown timer
	canExecute = true;
	preMills = millis();
}

//Method for stop calculating interval
void MyDelay::stop() {
	canExecute = false;
}

//Method resumes calcualtion of interval and doesn't reset preMills variable as start method does
void MyDelay::resume() {
	canExecute = true;
}

//Method resets preMills variable
void MyDelay::reset() {
	preMills = millis();
}

//Method for change the interval time
void MyDelay::setInterval(unsigned long milliseconds) {
	delaytime = milliseconds;
}