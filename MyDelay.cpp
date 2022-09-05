/*
  SOURCE FILE
  Gregor's library for "no stop" delay.
  September 2022.
*/

#include "arduino.h"
#include "MyDelay.h"

//Konstruktor
MyDelay::MyDelay(unsigned long milliseconds) {
	delaytime = milliseconds; //Podam input parameter v private v variablo
	preMills = 0;
	canExecute = false; //Po defaultu je zadevscina ugasnjena
}

//Glavna logika
bool MyDelay::isInterval() {
	if (!canExecute) return false; //ce je ugasnjen ne izvajam kode

	//Takole se izracuna interval
	curMills = millis();
	if (curMills - preMills >= delaytime) {
		preMills = curMills;
        return true;
	}
	else {
        return false;
	}		
}

//Metoda za start, ki poresetira variablo preMills. Posledicno se takoj sprozi interval
void MyDelay::start() {
	canExecute = true;
	preMills = 0;
}

//Metoda za stop
void MyDelay::stop() {
	canExecute = false;
}

//Metoda resume dela kot start, le da ne poresetira preMills
void MyDelay::resume() {
	canExecute = true;
}