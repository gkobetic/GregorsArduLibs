/*
  SOURCE FILE
  Gregor's library for "no stop" delay.
  September 2022.
*/

#include "arduino.h"
#include "MyFunctions.h"

//Constructor
MyFunctions::MyFunctions() {

}

//Function for mapping values, becouse map() function returns negative values when mapping bigger numbers
double MyFunctions::map(double value, double fromLow, double fromHigh, double toLow, double toHigh)  {
	return toLow + ((value - fromLow) / (fromHigh - fromLow)) * (toHigh - toLow);
	
}

