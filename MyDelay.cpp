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
	preMills = 0;
	canExecute = false; //Parameter for executing the time interval
}

//Main logic
bool MyDelay::isInterval() {
	if (!canExecute) return false; //If this parameter is false than we don't execute the code

	//Calcualte when time interval expires
	curMills = millis();
	if (curMills - preMills >= delaytime) {
		preMills = curMills;
        return true;
	}
	else {
        return false;
	}		
}

//Method to start calculating intervals. This method resets preMills
void MyDelay::start() {
	canExecute = true;
	preMills = 0;
}

//Method for stop calculating interval
void MyDelay::stop() {
	canExecute = false;
}

//Method resumes calcualtion of interval and doesn't reset preMills variable as start method does
void MyDelay::resume() {
	canExecute = true;
}