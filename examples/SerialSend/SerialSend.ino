/*
  Gregor's library for Arduino to Arduino or Arduino to ESP8266 (ESP32) serial communication over hardware serial ports.
  This is example sketch for SENDING DATA over hardware serial. See also other sketch for receiving data. Can be implemented in single sketch if needed.
  Library includes different methods (with KEY-VALUE pairs) for sending text, number, number with decimals, state like HIGH or LOW, true or false, etc.
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
    
  // Initialize Serial for debuging
  Serial.begin(9600);
  // Initialize Serial1 for sending data
  Serial1.begin(9600);
  // We have to declare Serial1 for sending data. Must be called after Serial1.begin()
  sata1.setPortSend(&Serial1);

}

void loop() {

  // Send KEY-VALUE pairs. KEY text must have 6 characters, not more, not less. VALUE text is limited to default serial buffer size (64 bytes)
  // After each method there is a delay() so that the Arduino on the receiving side can process the data and the buffer does not fill up
  sata1.sendString("text01", "Sunny day");
  delay(100);

  sata1.sendString("text02", "rainbow");
  delay(100);

  sata1.sendState("stat01", LOW);
  delay(100);

  sata1.sendState("stat02", HIGH);
  delay(100);

  sata1.sendBool("bool01", false);
  delay(100);

  sata1.sendBool("bool02", true);
  delay(100);

  sata1.sendInteger("numb01", 12);
  delay(100);
  
  sata1.sendDouble("deci01", 33.56);
  delay(100);

}