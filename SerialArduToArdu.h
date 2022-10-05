/*
  HEADER FILE
  Gregor's library for Arduino to Arduino serial communication.
  October 2022.
*/

#ifndef SerialArduToArdu_h
#define SerialArduToArdu_h

#include "Arduino.h"

// Class definition
class SerialArduToArdu
{
 	public:
	// Constructor
	SerialArduToArdu(int serialNumberSend);
	// Public methods and variables
	sendString();
	sendStatus();
	sendInteger();
	sendDecimal();
	
	private:
	// Private methods and variables
	int serialNumberSend;
	sendSerial();
	
};

#endif