/*
  HEADER FILE
  Gregor's library. Here I have various function
  February 2024.
*/

#ifndef MyFunctions_h
#define MyFunctions_h

#include "Arduino.h"

//Class definition
class MyFunctions
{
 	public:
	//Constructor
	MyFunctions();
	//Public methods and variables
	double map(double value, double fromLow, double fromHigh, double toLow, double toHigh); 

	private:
	//Private methods and variables

};

#endif