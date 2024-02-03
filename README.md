# Gregor's Arduino Libraries

[![Hits](https://hits.sh/github.com/gkobetic/GregorsArduLibs.svg?label=Repository%20views)](https://hits.sh/github.com/gkobetic/GregorsArduLibs/)

### Table of Contents
   * [Library for Arduino to Arduino (ESP8266) hardware serial communication](#1-arduino-to-arduino-hardware-serial-communication-serialardutoardu)
   * [Library Non stopable delay](#2-non-stopable-delay-mydelay)
   * [Library various functions](#3-variousvfunctions-myFunctions)

<br />

### 1. Arduino to Arduino hardware serial communication (SerialArduToArdu)
Library for Arduino to Arduino or Arduino to ESP8266 (ESP32) serial communication over hardware serial ports.
Sending and receiving data can be implemented in single sketch on different Serial ports if needed.
Library includes several methods (with KEY-VALUE pairs) for sending and receiving text, number, number with decimals, state like HIGH or LOW, true or false.
KEY text must be fix size 6 characters and VALUE text is not limited. However be carefull with String (text) size. Default Serial buffer is 64 bytes and overflow can occur!

#### Create serial communication:
- SerialArduToArdu sata1(false); -> paramether=true for debug mode, to print sent/received data on serial monitor

#### Here are implemented functions:
- setPortSend(&Serial1); -> defines serial port for sending data
- setPortReceive(&Serial); -> defines serial port for receiving data
##### For sending data:
- sendString(); -> sends text
- sendState(); -> sends state HIGH, LOW for example use with digitalWrite(LED_BUILTIN, .sendState()); 
- sendBool(); -> sends boolean value true or false
- sendInteger(); -> sends number
- sendDouble(); -> sends number with decimal places
##### For receiving data:
- readSerial(); -> reads serial in main loop()
- getKey(); -> get KEY text, since data are in KEY-VALUE pairs
- getValueString(); -> get VALUE in String
- getValueBool(); -> get VALUE in boolean
- getValueState(); -> get VALUE in state (HIGH, LOW)
- getValueInteger(); -> get VALUE in number
- getValueDouble(); -> get VALUE in number with decimals
 
 For more details see code examples in Arduino IDE.

<br />

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

For more details see code example in Arduino IDE.

<br />

### 3. Various functions (MyFunctions)
I created this method, becouse embeded Arduino map() function returns negative values when mapping higher numbers. 
Example: Arduino map() function returns some unacurate values in this case: map(x, 1000, 2000, -255, 255).

#### Create myFunctions:
- Create object, with no arguments

#### Here are implemented functions:
- map(double value, double fromLow, double fromHigh, double toLow, double toHigh);

For more details see code example in Arduino IDE.

#### My contacts:
- gkobetic@gmail.com

#### Connect with me:
<p align="left">
<a href="https://linkedin.com/in/gregor-kobetič" target="blank"><img align="center" src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/linked-in-alt.svg" alt="gkobetic" height="30" width="40" /></a>
</p>

<!-- #### 💰 You can help me by Donating
[![PayPal](https://img.shields.io/badge/PayPal-00457C?style=for-the-badge&logo=paypal&logoColor=white)](https://paypal.me/gkobetic) 
popravi link !!!! -->