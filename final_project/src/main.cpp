#include "arduino.h"
//#include <AFMotor.h>
#include <Servo.h>

const int sensorPin = A0; //input pin for ldr
const int LED = 13;
int ldrValue; //variable to store the value coming from the ldr
int servoPin = 10;


void ldr(int ldrValue);
void softServoWrite(int angle, long servoDela);

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(servoPin, OUTPUT);
  //Serial.begin(9600);


}

void loop(){
ldr(0);
//softServoWrite(30,0);
}


/* **********************************
    CODE LDR
   **********************************
*/

void ldr(int ldrValue){
  ldrValue = analogRead(sensorPin);
//  Serial.println(ldrValue);

  if(ldrValue < 100){
    Serial.println("LED light on");
    digitalWrite(LED, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(LED, LOW);
    delay(ldrValue);
  }

}









//code to rotate servo
/*
void softServoAttach(int pin)
{
   servoPin = pin;
   pinMode(pin, OUTPUT);
}
*/

// writes given angle to servo for given delay in milliseconds
/*void softServoWrite(int angle, long servoDelay)
{
  int pulsewidth = map(angle, 0, 180, 544, 2400); // width in microseconds
  do {
    digitalWrite(servoPin, HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servoPin, LOW);
    delay(20); // wait for 20 milliseconds
    servoDelay -= 20;
  } while(servoDelay >=0);

}
*/
