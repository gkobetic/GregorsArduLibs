/*
  Gregor's library for Arduino to Arduino or Arduino to ESP8266 (ESP32) serial communication over hardware serial ports.
  This is example sketch for RECEIVING DATA over hardware serial. See also other sketch for sending data. Can be implemented in single sketch if needed.
  Library includes different methods (with KEY-VALUE pairs) for receiving text, number, number with decimals, state like HIGH or LOW, true or false, etc.
  KEY text must have 6 characters and VALUE text is not limited. However be carefull with String (text) size. Default serial buffer is 64 bytes and overflow can occur!

  This is example for Arduino MEGA 2560 to NodeMcu 1.0 (ESP8266 chip). Arduino Mega on Serial1 (pins 18, 19) send data and NodeMcu receives data on Serial0 (pins rx, tx, aka: gpio1, gpio3).

  For any doubt feel free to ask on gregor@notics.si
  September 2022.
*/

#include <SerialArduToArdu.h>

//Create serial Arduino to Arduino object. 
//SerialArduToArdu sata1;
SerialArduToArdu sata1(true);  // paramether=true for debug mode

void setup() {
    
  // Initialize Serial
  Serial.begin(9600);
  // We have to declare Serial for receiving data. Must be called after Serial.begin()
  sata1.setPortReceive(&Serial);

}

void loop() {

  //Method for reading serial port. Must be called in loop()
  sata1.readSerial();

  // Get KEY-VALUE pairs that are received over Serial port
  // String
  if (sata1.getKey() == "text01") {
    String text01 = sata1.getValueString();
    //Serial.println(text01); 
  }

  // String second example. Last character is always new line (\n). Can be ommitted if input parameter = false
  if (sata1.getKey() == "text02") {
    String text02 = sata1.getValueString(false);
    //Serial.println(text02); 
  }

  // State HIGH, LOW
  if (sata1.getKey() == "stat01") {
    int stat01 = sata1.getValueState();
    digitalWrite(LED_BUILTIN, stat01); 
    //Serial.println(stat01); 
  }
  // Boolean true, false
  if (sata1.getKey() == "stat02") {
    bool stat02 = sata1.getValueBool();
    //Serial.println(stat02); 
  }
  // Number without decimal places
  if (sata1.getKey() == "numb01") {
    int numb01 = sata1.getValueInteger(); 
    //Serial.println(numb01); 
  }  
  // Number with decimal places
  if (sata1.getKey() == "deci01") {  
    double deci01 = sata1.getValueDouble();
    //Serial.println(deci01); 
  }  

}