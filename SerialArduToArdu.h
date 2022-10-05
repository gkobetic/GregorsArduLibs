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
	void sendSerial(String x, String y);
	void sendString(String a, String b);
	void sendStatus(String a, int b);
	void sendInteger(String a, int b);
	void sendDecimal(String a, double b);
	
	private:
	// Private methods and variables
	int serialPortSend;
	

};

#endif