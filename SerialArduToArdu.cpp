/*
  SOURCE FILE
  Gregor's library for Arduino to Arduino serial communication.
  October 2022.
*/

#include "arduino.h"
#include "SerialArduToArdu.h"

//Constructor
SerialArduToArdu::SerialArduToArdu(int serialPortSend, int speedSend, int serialPortReceive, int speedReceive, bool serialOutput) {
	_serialPortSend = serialPortSend; // Serial port number for sending data
  _speedSend = speedSend; // Sets the data rate in bits per second (baud) for send serial data
  _serialPortReceive = serialPortReceive; // Serial port number for receiving data
  _speedReceive = speedReceive; // Sets the data rate in bits per second (baud) for receive serial data
  _serialOutput = serialOutput;
}

// Setup method
void SerialArduToArdu::begin() {
  // Send port
  if (_serialPortSend == 0) {
  	Serial.begin(_speedSend);
  }
  else if (_serialPortSend == 1) {
	  Serial1.begin(_speedSend);
  }
  else if (_serialPortSend == 2) {
	  //Serial2.begin(_speedSend);
  }
  else if (_serialPortSend == 3) {
	  //Serial3.begin(_speedSend);
  }

  // Receive port
  if (_serialPortReceive == 0) {
  	Serial.begin(_speedReceive);
  }
  else if (_serialPortReceive == 1) {
	  Serial1.begin(_speedReceive);
  }
  else if (_serialPortReceive == 2) {
	  //Serial2.begin(_speedReceive);
  }
  else if (_serialPortReceive == 3) {
	  //Serial3.begin(_speedReceive);
  }
}

/*********** METHODS FOR SENDING DATA - BEGIN ***********/
//Common method for sending data
void SerialArduToArdu::sendSerial(String x, String y) {
  x = x + ":"; 

  if (_serialPortSend == 0) {
  	Serial.println(x + y);
  }
  else if (_serialPortSend == 1) {
	  Serial1.println(x + y);
  }
  else if (_serialPortSend == 2) {
	  //Serial2.println(x + y);	
  }
  else if (_serialPortSend == 3) {
	  //Serial3.println(x + y);
  }

  if (_serialOutput) Serial.println(x + y);
}

//Method for sending String
void SerialArduToArdu::sendString(String a, String b) {
  sendSerial(a, b);   
  checkStringSize(a, b);
}
//Method for sending Status
void SerialArduToArdu::sendStatus(String a, int b) {
  if (b != 1) {
    b = 0;
  }
  sendSerial(a, String(b)); 
  checkStringSize(a); 
}
//Method for sending Integer
void SerialArduToArdu::sendInteger(String a, int b) {
  sendSerial(a, String(b));   
  checkStringSize(a);
}
//Method for sending Decimal
void SerialArduToArdu::sendDecimal(String a, double b) {
  sendSerial(a, String(b));   
  checkStringSize(a);
}

//Method to check KEY and VALUE size for sending data
void SerialArduToArdu::checkStringSize(String myKey, String myValue) {
  if (_serialOutput) {
    if (myKey.length() != 6) Serial.println("Key text sent: " + myKey + ", wrong size. Must be 6 characters!");
    if (myValue.length() > 30) Serial.println("Value text sent: " + myValue + ", be carefull with String size. Serial buffer is 64 bytes and overflow can occur!");
  }
}
/*********** METHODS FOR SENDING DATA - END ***********/

/*********** METHODS FOR RECEIVING DATA - BEGIN ***********/
//Method for reading serial port. Must be in main loop
void SerialArduToArdu::readSerial() {
  String myString = "";

  //Reading serial until I get new line character
  if (_serialPortReceive == 0) {
  	if(Serial.available() > 0) myString = Serial.readStringUntil('\n'); 
  }
  else if (_serialPortReceive == 1) {
	  if(Serial1.available() > 0) myString = Serial.readStringUntil('\n'); 
  }
  else if (_serialPortReceive == 2) {
	  //if(Serial2.available() > 0) myString = Serial.readStringUntil('\n'); 
  }
  else if (_serialPortReceive == 3) {
	  //if(Serial3.available() > 0) myString = Serial.readStringUntil('\n'); 
  }

  //Parse data
  _key = myString.substring(0, 6);
  _value = myString.substring(7, myString.length()); 
}
String SerialArduToArdu::getKey() {
    if (_serialOutput) Serial.println("Key text received: " + _key);
    return _key;
}
String SerialArduToArdu::getValue(bool nullCharacter) {
  if (nullCharacter) {
    if (_serialOutput) Serial.println("Value text received: " + _value);
    return _value;
  }
  else {
    if (_serialOutput) Serial.println("Value text received: " + _value);
    return _value.substring(0, _value.length() -1);
  }
}
/*********** METHODS FOR RECEIVING DATA - END ***********/