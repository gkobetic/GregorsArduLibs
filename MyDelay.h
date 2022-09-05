/*
  HEADER FILE
  Gregor's library for "no stop" delay.
  Created by Gregor, september 2022.
*/

#ifndef MyDelay_h
#define MyDelay_h

#include "Arduino.h"

//Definicija class-a
class MyDelay
{
 	public:
	//Konstruktor
	MyDelay(unsigned long milliseconds);
	//Public variable in metode
	bool execute();
	//....

	private:
	//Private variable in metode
	unsigned long preMills, curMills, delaytime;
};

#endif