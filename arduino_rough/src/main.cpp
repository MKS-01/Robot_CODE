/**
 * Blink
 * Turns on an LED on for one second,
 * then off for one second, repeatedly.
 */
#include "Arduino.h"




void setup()
{
  // initialize LED digital pin as an output.
  pinMode(12, OUTPUT);
}

void loop()
{
  // turn the LED on (HIGH is the voltage level)
  digitalWrite(12, HIGH);
  // wait for a second
  delay(400);
  // turn the LED off by making the voltage LOW
  digitalWrite(12, LOW);
   // wait for a second
  delay(1000);
}
