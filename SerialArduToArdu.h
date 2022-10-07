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
	SerialArduToArdu(int serialPortSend, int speedSend, int serialPortReceive, int speedReceive, bool serialOutput = false);
	// Public methods and variables
	void begin();
	void sendString(String a, String b);
	void sendStatus(String a, int b);
	void sendInteger(String a, int b);
	void sendDecimal(String a, double b);
	void readSerial();
	String getKey();
	String getValueString(bool endCharacter = true);
	bool getValueBool(bool endCharacter = true);
	int getValueState(bool endCharacter = true);
	int getValueInteger(bool endCharacter = true);
	double getValueDouble(bool endCharacter = true);
	
	private:
	// Private methods and variables
	int _serialPortSend, _speedSend, _serialPortReceive, _speedReceive;
	bool _serialOutput;
	String _key, _value;
	void sendSerial(String x, String y);
	void checkStringSize(String myKey, String myValue = "");
	String getValue(bool endCharacter);
	
};

#endif