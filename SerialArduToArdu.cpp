/*
  SOURCE FILE
  Gregor's library for Arduino to Arduino serial communication.
  October 2022.
*/

#include "arduino.h"
#include "SerialArduToArdu.h"

//Constructor
SerialArduToArdu::SerialArduToArdu(int serialPortSend, int speed, bool serialOutput) {
	mySerialPortSend = serialPortSend; // Serial port number for sending data.
  mySpeed = speed; // Sets the data rate in bits per second (baud) for serial data transmission
  isSerialOutput = serialOutput;
}

// Setup method
void SerialArduToArdu::begin() {
  if (mySerialPortSend == 0) {
  	Serial.begin(mySpeed);
  }
  else if (mySerialPortSend == 1) {
	Serial1.begin(mySpeed);
  }
  else if (mySerialPortSend == 2) {
	Serial2.begin(mySpeed);
  }
  else if (mySerialPortSend == 3) {
	Serial3.begin(mySpeed);
  }
}

//Main loop method
// bool MyDelay::isInterval() {
// 	if (!canExecute) return false; //If this parameter is false than we don't execute the code

// 	//Calcualte when time interval expires
// 	curMills = millis();
// 	if (preMills > curMills) preMills = 0; //Safety if millis() overflows
// 	if (curMills - preMills >= delaytime) {
// 		preMills = curMills;
//         return true;
// 	}
// 	else {
//         return false;
// 	}		
// }

//Common method for sending data
void SerialArduToArdu::sendSerial(String x, String y) {
  x = x + ":"; 

  if (mySerialPortSend == 0) {
  	Serial.println(x + y);
  }
  else if (mySerialPortSend == 1) {
	Serial1.println(x + y);
  }
  else if (mySerialPortSend == 2) {
	Serial2.println(x + y);	
  }
  else if (mySerialPortSend == 3) {
	Serial3.println(x + y);
  }

  if (isSerialOutput) Serial.println(x + y);
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

//Method to check KEY and VALUE size
void SerialArduToArdu::checkStringSize(String myKey, String myValue = "") {
  if (isSerialOutput) {
    if (myKey.length() != 6) Serial.println("Key text: " + myKey + ", wrong size. Must be 6 characters!");
    if (myValue.length() > 30) Serial.println("Value text: " + myValue + ", be carefull with String size. Serial buffer is 64 bytes and overflow can occur!");
  }
}