/*
  Gregor's library for "no stop" delay.
  September 2022.
*/

#include <MyDelay.h>

//Create delay object and set interval in milliseconds
MyDelay myDelay1(1000);
MyDelay myDelay2(500);

void setup() {
  //Start method must be called for delay to start executing
  myDelay1.start();
  myDelay2.start();

  //Stop method can be called to stop executing the delay
  //myDelay1.stop();
  //myDelay2.stop();

  //Resume metod resumes executing the delay and takes into account the remaining time. If .start() method is called instead of .resume() then remainig time is reset.
  //myDelay1.resume();
  //myDelay2.resume();

}

void loop() {

  //When the interval expires then execute my code
  if(myDelay1.isInterval())
  {
    //Here is my code to be executed
  }

  //Another delay
  if(myDelay2.isInterval())
  {
    //Here is my code to be executed
  }

  //Example how to change interval time on existing delay
  //myDelay1.setInterval(200);

}