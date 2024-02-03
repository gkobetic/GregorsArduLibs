/*
  HEADER FILE
  Gregor's library for "no stop" delay.
  September 2022.
*/

#ifndef MyDelay_h
#define MyDelay_h

#include "Arduino.h"

//Class definition
class MyDelay
{
 	public:
	//Constructor
	MyDelay(unsigned long milliseconds);
	//Public methods and variables
	bool isInterval();
	void start(bool resetTimer = true);
	void stop();
	void resume();
	void reset();
	void setInterval(unsigned long milliseconds);
	
	private:
	//Private methods and variables
	unsigned long preMills, curMills, delaytime;
	bool canExecute, _resetMillis;
};

#endif