/*
  Gregor's library for "no stop" delay.
  This is example sketch of implementation of non stopable delay function.
  September 2022.
*/

#include <MyDelay.h>

//Create delay object and set interval in milliseconds
MyDelay myDelay1(1000);
MyDelay myDelay2(5000);

void setup() {
  Serial.begin(9600);

  //Start method must be called for delay to start executing
  myDelay1.start();
  myDelay2.start(false); //Optional parameter (resetTimer), if false interval will not reset automatically. Usefull for countdown timer

  //Stop method can be called to stop executing the delay
  //myDelay1.stop();
  //myDelay2.stop();

  //Resume metod resumes executing the delay and takes into account the remaining time
  //myDelay1.resume();
  //myDelay2.resume();

}

void loop() {

  //When the interval expires then execute my code
  if(myDelay1.isInterval())
  {
    //Here is my code to be executed
    Serial.println("Timer1 executed");
  }

  //Another delay
  if(myDelay2.isInterval())
  {
    //Here is my code to be executed
    Serial.println("Timer2 executed");
  }

  //Example how to change interval time on existing delay
  //myDelay1.setInterval(200);

  //Resets timer. It is usually used when we want to reset (extend) the expiration time due to some event
  //myDelay1.reset();

}