/*
  Gregor's library for "no stop" delay.
  September 2022.
*/

#include <MyDelay.h>

//Kreiram objekt in dolocim interval v ms
MyDelay Zakasnitev1(1000);

void setup() {
  //Setup koda...
}

void loop() {

  if(Zakasnitev1.execute())
  {
    //Tukaj se izvaja moja koda ob definiranem intervalu
  }

}