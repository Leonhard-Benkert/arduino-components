#include "UltrasonicSensor.h"
#include <Arduino.h>

int UltrasonicSensor::getDistanceInMm() {
  float pingTime;

  // create pulse for ultrasonic sensor
  pinMode(_pin, OUTPUT);
  digitalWrite(_pin, LOW);
  delayMicroseconds(1);
  digitalWrite(_pin, HIGH);
  delayMicroseconds(1);
  digitalWrite(_pin, LOW);
  
  // measuring travel-time of ping
  pinMode(_pin, INPUT);
  pingTime = pulseIn(_pin,HIGH); //ping time in microseconds

  return round(((SPEED_OF_SOUND * pingTime))/2.); //calculating distance, *100 for cm, divide by 2 to get the one way distance
}
