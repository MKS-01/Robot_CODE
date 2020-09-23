#include "arduino.h"
#include <Servo.h>

Servo  myservo; //create servo objet to control a servo

int pos = 0; //variable to store the servo position

void setup(){
  myservo.attach(10);   //servo pin no
}

void loop(){
myservo.write(90);
/*  for (pos = 0; pos <= 180; pos += 1){ //goes from 0 degree to 180 degree
    myservo.write(pos); //tell servo to go to position in variable 'pos'
    delay(10);
  }

for (pos=180; pos >= 0; pos -=1) { //goes from 180 degree to 0 degree
  myservo.write(pos);
  delay(10);



}
*/

//for(pos = 144; pos >= 36; pos-=18)     // loop to sweep the servo (& sensor) from 144-degrees left to 36-degrees right at 18-degree intervals.
//{
//  myservo.write(pos);  // tell servo to go to position in variable 'pos'
  //delay(190); // wait 90ms for servo to get to position
//  checkForward(); // check the robot is still moving forward
//  curDist = readPing(); // get the current distance to any object in front of sensor
  //if (curDist < COLL_DIST) { // if the current distance to object is less than the collision distance
    //checkCourse(); // run the checkCourse function
  //  break; // jump out of this loop
  //}


}
