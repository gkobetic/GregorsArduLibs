/*
  Gregor's library for "no stop" delay.
  September 2022.
*/

#include <MyDelay.h>

//Kreiram objekt in dolocim interval v ms
MyDelay Zakasnitev1(1000);

void setup() {
  Zakasnitev1.start();
  
}

void loop() {

  if(Zakasnitev1.isInterval())
  {
    //Tukaj se izvaja moja koda ob definiranem intervalu
  }

}