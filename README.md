# Gregor's Arduino Libraries
- Library for Arduino to Arduino hardware serial communication. Name: SerialArduToArdu
- Library Non stopable delay. Name: MyDelay


### 1. Arduino to Arduino hardware serial communication (SerialArduToArdu)
Library for Arduino to Arduino or Arduino to ESP8266 (ESP32) serial communication over hardware serial ports.
Sending and receiving data can be implemented in single sketch on different Serial ports if needed.
Library includes several methods (with KEY-VALUE pairs) for sending text, number, number with decimals, state like HIGH or LOW, true or false.
KEY text must be fix size 6 characters and VALUE text is not limited. However be carefull with String (text) size. Default Serial buffer is 64 bytes and overflow can occur!

#### Create serial communication:
- SerialArduToArdu sata1(1, 9600, 0, 9600); -> Serial number and port for send and receive data on the same sketch if needed

#### Here are implemented functions:
- begin(); -> call in setup to inicialize communication
##### For sending data:
- sendString(); -> self-explanatory 
- sendState(); -> sends state HIGH, LOW for example use with digitalWrite(LED_BUILTIN, .sendState()); 
- sendBool(); -> sends boolean value true or false
- sendInteger(); -> sends number
- sendDecimal(); -> sends number with decimal places
##### For receiving data:
- readSerial(); -> reads serial in main loop()
- getKey(); -> get KEY text, since data are in KEY-VALUE pairs
- getValueString(); -> get VALUE in String
- getValueBool(); -> get VALUE in boolean
- getValueState(); -> get VALUE in state (HIGH, LOW)
- getValueInteger(); -> get VALUE in number
- getValueDouble(); -> get VALUE in number with decimals
 
### 2. Non stopable delay (MyDelay)
Library for delays (time intervals) that do not stop the main loop from executing.

#### Create delay:
- MyDelay myDelay1(1000); -> 1000 is interval time in milliseconds when your code can be executed.
Add as many delays as you want. Name them like myDelay2(), myDelay3(), myDelay4(),...

#### Here are implemented functions:
- isInterval(); -> check if interval time has expired and execute your code
- start(); -> starts executing delay
- stop(); -> stop executing delay
- resume(); -> resumes executing delay
- reset(); -> resets timer and start counting interval time from the beginning
- setInterval(200); -> change interval time on existing delay. 200 is new interval time in milliseconds 

Please see code example in Arduino IDE.

You can contact me any time:
- gregor@notics.si
- https://www.notics.si/

Best regards!
