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
	SerialArduToArdu(bool serialOutput = false);
	// Public methods and variables
	void setPortSend(HardwareSerial *serialPortSend);
	void setPortReceive(HardwareSerial *serialPortReceive);
	void sendString(String a, String b);
	void sendState(String a, int b);
	void sendBool(String a, bool b);
	void sendInteger(String a, int b);
	void sendDouble(String a, double b);
	void readSerial();
	String getKey();
	String getValueString(bool endCharacter = true);
	bool getValueBool(bool endCharacter = true);
	int getValueState(bool endCharacter = true);
	int getValueInteger(bool endCharacter = true);
	double getValueDouble(bool endCharacter = true);
	
	private:
	// Private methods and variables
	HardwareSerial *_serialPortSend;
	HardwareSerial *_serialPortReceive;
	bool _serialOutput;
	String _key, _value;
	void sendSerial(String x, String y);
	void checkStringSize(String myKey, String myValue = "");
	String getValue(bool endCharacter);
	
};

#endif