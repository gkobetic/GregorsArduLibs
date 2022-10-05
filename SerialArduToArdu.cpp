/*
  SOURCE FILE
  Gregor's library for Arduino to Arduino serial communication.
  October 2022.
*/

#include "arduino.h"
#include "SerialArduToArdu.h"

//Constructor
SerialArduToArdu::SerialArduToArdu(int serialPortSend) {
	serialPortSend = serialPortSend; //Serial number for sending data, example: Serial1
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

  if (serialPortSend == 1) {
  	Serial1.println(x + y);
  }
  else if (serialPortSend == 2) {
	Serial2.println(x + y);
  }
  else if (serialPortSend == 3) {
	Serial3.println(x + y);	
  }
  else if (serialPortSend == 4) {
	Serial4.println(x + y);
  }
}

//Method for sending String
void SerialArduToArdu::sendString(String a, String b) {
  sendSerial(a, b);   
}
//Method for sending Status
void SerialArduToArdu::sendStatus(String a, int b) {
  if (b != 1) {
    b = 0;
  }
  sendSerial(a, String(b));  
}
//Method for sending Integer
void SerialArduToArdu::sendInteger(String a, int b) {
  sendSerial(a, String(b));   
}
//Method for sending Decimal
void SerialArduToArdu::sendDecimal(String a, double b) {
  sendSerial(a, String(b));   
}