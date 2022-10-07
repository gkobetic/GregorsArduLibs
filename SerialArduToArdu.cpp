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
  _speedSend = speedSend; // Sets the data rate in bits per second (baud) for sending data
  _serialPortReceive = serialPortReceive; // Serial port number for receiving data
  _speedReceive = speedReceive; // Sets the data rate in bits per second (baud) for receiving data
  _serialOutput = serialOutput; // If true, print all serial data to Serial0(Connected to USB) for debuging. Default = false
}

// Definition of serial numbers for send and receive. Must be called in Setup()
void SerialArduToArdu::begin() {
  // Send ports
  if (_serialPortSend == 0) {
    #if defined(HAVE_HWSERIAL0)
  	  Serial.begin(_speedSend);
    #endif
  }
  else if (_serialPortSend == 1) {
    #if defined(HAVE_HWSERIAL1)
	    Serial1.begin(_speedSend);
    #endif
  }
  else if (_serialPortSend == 2) {
    #if defined(HAVE_HWSERIAL2)
	    Serial2.begin(_speedSend);
    #endif
  }
  else if (_serialPortSend == 3) {
    #if defined(HAVE_HWSERIAL3)
	    Serial3.begin(_speedSend);
    #endif
  }
  else {
    #if defined(HAVE_HWSERIAL0)
      // Error
      if (_serialOutput) Serial.println("Serial port number for sending data not declared or does not exists");
    #endif
  }

  // Receive ports
  if (_serialPortReceive == 0) {
    #if defined(HAVE_HWSERIAL0)
  	  Serial.begin(_speedReceive);
    #endif
  }
  else if (_serialPortReceive == 1) {
    #if defined(HAVE_HWSERIAL1)
	    Serial1.begin(_speedReceive);
    #endif
  }
  else if (_serialPortReceive == 2) {
    #if defined(HAVE_HWSERIAL2)
	    Serial2.begin(_speedReceive);
    #endif
  }
  else if (_serialPortReceive == 3) {
    #if defined(HAVE_HWSERIAL3)
	    Serial3.begin(_speedReceive);
    #endif
  }
  else {
    #if defined(HAVE_HWSERIAL0)
      // Error
      if (_serialOutput) Serial.println("Serial port number for receiving data not declared or does not exists");
    #endif
  }
}

/*********** METHODS FOR SENDING DATA - BEGIN ***********/
//Common method for sending data
void SerialArduToArdu::sendSerial(String x, String y) {
  x = x + ":"; 

  if (_serialPortSend == 0) {
    #if defined(HAVE_HWSERIAL0)
  	  Serial.println(x + y);
    #endif
  }
  else if (_serialPortSend == 1) {
    #if defined(HAVE_HWSERIAL1)
	    Serial1.println(x + y);
    #endif
  }
  else if (_serialPortSend == 2) {
    #if defined(HAVE_HWSERIAL2)
	    Serial2.println(x + y);	
    #endif
  }
  else if (_serialPortSend == 3) {
	  #if defined(HAVE_HWSERIAL3)
      Serial3.println(x + y);
    #endif
  }

  #if defined(HAVE_HWSERIAL0)
    // For USB debuging if true
    if (_serialOutput) Serial.println(x + y);
  #endif
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

//Method to check KEY and VALUE size for sending data. For USB debuging if _serialOutput = true
void SerialArduToArdu::checkStringSize(String myKey, String myValue) {
  if (_serialOutput) {
    #if defined(HAVE_HWSERIAL0)
      if (myKey.length() != 6) Serial.println("Key text sent: " + myKey + ", wrong size. Must be 6 characters!");
      if (myValue.length() > 30) Serial.println("Value text sent: " + myValue + ", be carefull with String size. Serial buffer is 64 bytes and overflow can occur!");
    #endif
  }
}
/*********** METHODS FOR SENDING DATA - END ***********/

/*********** METHODS FOR RECEIVING DATA - BEGIN ***********/
//Method for reading serial port. Must be called in loop()
void SerialArduToArdu::readSerial() {
  String myString = "";

  //Reading serial until I get new line character
  if (_serialPortReceive == 0) {
    #if defined(HAVE_HWSERIAL0)
  	  if(Serial.available() > 0) myString = Serial.readStringUntil('\n'); 
    #endif
  }
  else if (_serialPortReceive == 1) {
    #if defined(HAVE_HWSERIAL1)
	    if(Serial1.available() > 0) myString = Serial.readStringUntil('\n'); 
    #endif
  }
  else if (_serialPortReceive == 2) {
    #if defined(HAVE_HWSERIAL2)
	    if(Serial2.available() > 0) myString = Serial.readStringUntil('\n'); 
    #endif
  }
  else if (_serialPortReceive == 3) {
    #if defined(HAVE_HWSERIAL3)
	    if(Serial3.available() > 0) myString = Serial.readStringUntil('\n'); 
    #endif
  }

  //Parse data
  _key = myString.substring(0, 6);
  _value = myString.substring(7, myString.length()); 
}
// Returns KEY text
String SerialArduToArdu::getKey() {
  #if defined(HAVE_HWSERIAL0)
    // For USB debuging if true
    if (_serialOutput) Serial.println("Key text received: " + _key);
  #endif
  return _key;
}
// Commom method for VALUE text. Last character is new line (\n). Can be ommitted if endCharacter = false
String SerialArduToArdu::getValue(bool endCharacter) {
  if (endCharacter) {
    #if defined(HAVE_HWSERIAL0)
      // For USB debuging if true
      if (_serialOutput) Serial.println("Value text received: " + _value);
    #endif
    return _value;
  }
  else {
    #if defined(HAVE_HWSERIAL0)
      // For USB debuging if true
      if (_serialOutput) Serial.println("Value text received: " + _value);
    #endif
    return _value.substring(0, _value.length() -1);
  }
}
// Returns VALUE text in String format
String SerialArduToArdu::getValueString(bool endCharacter) {
  return getValue(endCharacter);
}
// Returns VALUE text in bool format
bool SerialArduToArdu::getValueBool(bool endCharacter) {
  if (getValue(endCharacter) == 0) {
    return false;
  }
  else {
    return true;
  }
}
// Returns VALUE text in state (HIGH, LOW) format
int SerialArduToArdu::getValueState(bool endCharacter) {
  if (getValue(endCharacter) == 0) {
    return 0;
  }
  else {
    return 1;
  }
}
// Returns VALUE text in integer format
int SerialArduToArdu::getValueInteger(bool endCharacter) {
  return getValue(endCharacter).toInt();
}


/*********** METHODS FOR RECEIVING DATA - END ***********/