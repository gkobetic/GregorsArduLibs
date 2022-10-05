/*
  HEADER FILE
  Gregor's library for Arduino to Arduino serial communication.
  October 2022.
*/

#ifndef SerialArduToArdu_h
#define SerialArduToArdu_h

#include "Arduino.h"

//Class definition
class SerialArduToArdu
{
 	public:
	//Constructor
	SerialArduToArdu(int serialNumberSend);
	//Public methods and variables
	sendSerial();
	sendString();
	sendStatus();
	sendInteger();
	sendDecimal();

	// bool isInterval();
	// void start();
	// void stop();
	// void resume();
	// void reset();
	// void setInterval(unsigned long milliseconds);
	
	
	private:
	//Private methods and variables
	int serialNumberSend;

	// unsigned long preMills, curMills, delaytime;
	// bool canExecute;
};

#endif