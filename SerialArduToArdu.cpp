/*
  SOURCE FILE
  Gregor's library for Arduino to Arduino serial communication.
  October 2022.
*/

#include "arduino.h"
#include "SerialArduToArdu.h"

//Constructor
SerialArduToArdu::SerialArduToArdu(bool serialOutput) {
  _serialOutput = serialOutput; // If true, print all serial data to Serial0(Connected to USB) for debuging. Default = false
}

// Definition of serial port number for send and receive. Must be called in Setup()
void SerialArduToArdu::setPortSend(HardwareSerial *serialPortSend) {
  _serialPortSend = serialPortSend;
}
void SerialArduToArdu::setPortReceive(HardwareSerial *serialPortReceive) {
  _serialPortReceive = serialPortReceive;
}

/*********** METHODS FOR SENDING DATA - BEGIN ***********/
//Common method for sending data
void SerialArduToArdu::sendSerial(String x, String y) {
  x = x + ":"; 

  _serialPortSend->println(x + y);

  // For USB debuging if true
  if (_serialOutput) Serial.println(x + y);
}

//Method for sending String
void SerialArduToArdu::sendString(String a, String b) {
  sendSerial(a, b);   
  checkStringSize(a, b);
}
//Method for sending State
void SerialArduToArdu::sendState(String a, int b) {
  // That's how Arduino does it for bool type
  if (b != 0)
    b = 1;
  sendSerial(a, String(b)); 
  checkStringSize(a); 
}
//Method for sending State
void SerialArduToArdu::sendBool(String a, bool b) {
  // That's how Arduino does it for bool type
  if (b != 0)
    b = 1;
  sendSerial(a, String(b)); 
  checkStringSize(a); 
}
//Method for sending Integer
void SerialArduToArdu::sendInteger(String a, int b) {
  sendSerial(a, String(b));   
  checkStringSize(a);
}
//Method for sending Decimal
void SerialArduToArdu::sendDouble(String a, double b) {
  sendSerial(a, String(b));   
  checkStringSize(a);
}

//Method to check KEY and VALUE size for sending data. For USB debuging if _serialOutput = true
void SerialArduToArdu::checkStringSize(String myKey, String myValue) {
  if (_serialOutput) {
    if (myKey.length() != 6) Serial.println("Key text sent: " + myKey + ", wrong size. Must be 6 characters!");
    if (myValue.length() > 30) Serial.println("Value text sent: " + myValue + ", be carefull with String size. Serial buffer is 64 bytes and overflow can occur!");
  }
}
/*********** METHODS FOR SENDING DATA - END ***********/

/*********** METHODS FOR RECEIVING DATA - BEGIN ***********/
//Method for reading serial port. Must be called in main loop()
void SerialArduToArdu::readSerial() {
  String myString = "";

  //Reading serial until I get new line character
  if(_serialPortReceive->available() > 0) {
    myString = _serialPortReceive->readStringUntil('\n'); 
    
    // For USB debuging if true
    if (_serialOutput) Serial.println("Serial received: " + myString);
  }

  //Parse data. KEY must be 6 characters
  _key = myString.substring(0, 6);
  _value = myString.substring(7, myString.length()); 
}

// Returns KEY text
String SerialArduToArdu::getKey() {
  return _key;
}
// Commom method for VALUE text. Last character is new line (\n). Can be ommitted if endCharacter = false
String SerialArduToArdu::getValue(bool endCharacter) {
  if (endCharacter) {
    return _value;
  }
  else {
    return _value.substring(0, _value.length() -1);
  }
}

// Methods for different return types
// Returns VALUE text in String
String SerialArduToArdu::getValueString(bool endCharacter) {
  return getValue(endCharacter);
}
// Returns VALUE text in bool
bool SerialArduToArdu::getValueBool(bool endCharacter) {
  // That's how Arduino does it for bool type
  if (getValue(endCharacter).toInt() == 0)
    return false;
  else
    return true;
}
// Returns VALUE text in state (HIGH, LOW)
int SerialArduToArdu::getValueState(bool endCharacter) {
  // That's how Arduino does it for bool type
  if (getValue(endCharacter).toInt() == 0)
    return false;
  else
    return true;
}
// Returns VALUE text in integer
int SerialArduToArdu::getValueInteger(bool endCharacter) {
  return getValue(endCharacter).toInt();
}
// Returns VALUE text in double
double SerialArduToArdu::getValueDouble(bool endCharacter) {
  return getValue(endCharacter).toDouble();
}
/*********** METHODS FOR RECEIVING DATA - END ***********/