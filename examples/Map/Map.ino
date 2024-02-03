#include <MyFunctions.h>

int x = 1000;

//Create object myFunctions
MyFunctions myFunctions;

void setup() {
  Serial.begin(9600);
}

void loop() {

  //Call method map. I created this function, becouse embeded Arduino map() function returns negative values when mapping higher numbers. 
  //Example: Arduino map() returns some unacurate values in this case: map(x, 1000, 2000, -255, 255)
  int y = myFunctions.map(x, 1000, 2000, -255, 255);

  Serial.print("Map function: ");
  Serial.println(y);
  if(x >= 2000) {x = 1000;}
  x++;
  delay(10);

}
