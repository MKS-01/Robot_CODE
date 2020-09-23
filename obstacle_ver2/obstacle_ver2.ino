// Written by Hossam Hamed
// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!
//#include <IRremote.h>
#include <AFMotor.h>
#include <Servo.h>
#include <NewPing.h>
#define PING_PIN 14
// Arduino pin tied to both trigger and echo pins on the ultrasonic sensor.
#define MAX_DISTANCE 200
// Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(PING_PIN, PING_PIN, MAX_DISTANCE);
// NewPing setup of pin and maximum distance.

AF_DCMotor motor1(1), motor2(2),motor3(3), motor4(4);
Servo servo1;
unsigned int vDistance, vDistanceR, vDistanceR_h, vDistanceL, vDistanceL_h, maxDistance, goDirection;

void moveRight(int v_time, int v_speed=255);
void moveLeft(int v_time, int v_speed=255);
void stopMotors();
void moveForward(int v_time=0, int v_speed=255);
void moveBackward(int v_time=0, int v_speed=255);
void lookStrait();
void lookLeft( int v_angle=135);
void lookRight( int v_angle=45);

void setup() {
 Serial.begin(9600); // set up Serial library at 9600 bps
 //irrecv.enableIRIn(); // Start the receiver
 servo1.attach(10);
 lookStrait();
 delay(1000);
}
// Values for GoDirection
// 1 -> 45 Right
// 2 -> 0 Right
// 3 -> 135 left
// 4 -> 180 left

// Main program loop
void loop() {
   RobotFuntion();
 } //End Loop

// Functions declaration
void RobotFuntion() {
 vDistance = getDistance();
 Serial.print("\nDistance = ");
 Serial.print(vDistance);

 if ( vDistance <=20 ) {
 moveBackward(300,180);
 }

 if (vDistance < 30) {
 stopMotors();

 lookRight(45);
 delay(300);
 vDistanceR_h = getDistance();
 maxDistance = vDistanceR_h;
 goDirection = 1;

 lookRight(0);
 delay(300);
 vDistanceR = getDistance();

 if (vDistanceR > maxDistance) {
 maxDistance = vDistanceR;
 goDirection = 2;
 }

 lookLeft(135);
 delay(300);
 vDistanceL_h = getDistance();
if (vDistanceL_h > maxDistance) {
 maxDistance = vDistanceL_h;
 goDirection = 3;
 }
lookLeft(180);
 delay(300);
 vDistanceL = getDistance();
if (vDistanceL > maxDistance) {
 maxDistance = vDistanceL;
 goDirection = 4;
 }

 lookStrait(); // Look Strait again
 delay(300);

 if(goDirection == 1 ) {
 moveRight(200);
 moveForward(0,128);
 }
 else if (goDirection == 2) {
 moveRight(400);
 moveForward(0,128);
 }

 else if (goDirection == 3) {
 moveLeft(200);
 moveForward(0,128);
 }
else if (goDirection == 4) {
 moveLeft(400);
 moveForward(0,128);
 }
} // End If
 else {
 moveForward(0,128);
 }
 //delay(1000);

} // End RobotFunction

unsigned int getDistance() {
 unsigned int my_cm;
 unsigned int uS;
 uS = sonar.ping_median();
 my_cm = sonar.convert_cm(uS);
 if (my_cm == 0)
 my_cm = MAX_DISTANCE;
 return my_cm;
}

void stopMotors() {
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
}

void moveForward(int v_time, int v_speed) {
 motor1.setSpeed(v_speed);
 motor2.setSpeed(v_speed);
 motor3.setSpeed(v_speed);
 motor4.setSpeed(v_speed);

 motor1.run(FORWARD);
 motor2.run(FORWARD);
 motor3.run(FORWARD);
 motor4.run(FORWARD);
}
void moveBackward(int v_time, int v_speed) {
 motor1.setSpeed(v_speed);
 motor2.setSpeed(v_speed);
 motor3.setSpeed(v_speed);
 motor4.setSpeed(v_speed);
 motor1.run(BACKWARD);
 motor2.run(BACKWARD);
 motor3.run(BACKWARD);
 motor4.run(BACKWARD);
 delay(v_time);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
}
void moveLeft(int v_time, int v_speed) {
 motor1.setSpeed(v_speed);
 motor2.setSpeed(v_speed);
 motor3.setSpeed(v_speed);
 motor4.setSpeed(v_speed);
 motor2.run(FORWARD);
 motor1.run(BACKWARD);
 motor3.run(FORWARD);
 motor4.run(BACKWARD);

 delay(v_time);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
}
void moveRight(int v_time, int v_speed) {
 motor1.setSpeed(v_speed);
 motor2.setSpeed(v_speed);
 motor3.setSpeed(v_speed);
 motor4.setSpeed(v_speed);

 motor1.run(FORWARD);
 motor2.run(BACKWARD);
 motor3.run(BACKWARD);
 motor4.run(FORWARD);

 delay(v_time);
 motor1.run(RELEASE);
 motor2.run(RELEASE);
 motor3.run(RELEASE);
 motor4.run(RELEASE);
}

void lookStrait() {
  servo1.write(92);
}

void lookLeft( int v_angle) {
 servo1.write(v_angle);
}
void lookRight( int v_angle) {
 servo1.write(v_angle);
}
