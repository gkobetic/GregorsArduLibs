/*
  Gregor's library for Arduino to Arduino or Arduino to ESP8266 (ESP32) serial communication over hardware serial ports.
  This is example sketch for SENDING DATA over hardware serial. See also other sketch for receiving data. Can be implemented in single sketch if needed.
  Library includes different methods (with KEY-VALUE pairs) for sending text, number, number with decimals, state like HIGH or LOW, true or false, etc.
  KEY text must have 6 characters and VALUE text is not limited. However be carefull with String (text) size. Serial buffer is 64 bytes and overflow can occur!

  This is example for Arduino MEGA 2560 to NodeMcu 1.0 (ESP8266 chip). Arduino Mega on Serial1 (pins 18, 19) send data and NodeMcu receives data on Serial0 (pins rx, tx, aka: gpio1, gpio3).

  For any doubt feel free to ask on gregor@notics.si
  September 2022.
*/

#include <SerialArduToArdu.h>

//Create serial Arduino to Arduino object. 
//Description of input parameters: 
//SerialArduToArdu sata1(serial port number for send data, baud rate for send data, serial port number for receive data, baud rate for receive data, optional: if true send (verbose) data to Serial(USB) for debuging).
SerialArduToArdu sata1(1, 9600, null, null); // for send data only
//SerialArduToArdu sata1(1, 9600, null, null, true);  // last paramether=true for debug mode
//SerialArduToArdu sata1(1, 9600, 0, 9600); // for send and receive data on the same sketch if needed

void setup() {
    
    // Serial connected to USB for debuging
    Serial.begin(9600);
    // Initialization of serial Arduino to Arduino communication
    sata1.begin();
}

void loop() {

    // Send KEY-VALUE pairs. KEY text must have 6 characters, not more, not less. VALUE text is limited to serial buffer size (64 bytes)
    // After each method there is a delay() so that the Arduino on the receiving side can process the data and the buffer does not fill up
    sata1.sendString("text01", "Sunny day");
    delay(100);

    sata1.sendString("text02", "rainbow");
    delay(100);

    sata1.sendStatus("stat01", HIGH);
    delay(100);

    sata1.sendStatus("stat02", false);
    delay(100);

    sata1.sendInteger("numb01", 12);
    delay(100);
    
    sata1.sendDecimal("deci01", 33.56);
    delay(100);

}