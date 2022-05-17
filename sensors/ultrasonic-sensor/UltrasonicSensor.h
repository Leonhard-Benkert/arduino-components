#ifndef ULTRASONICSENSOR_H
#define ULTRASONICSENSOR_H

/*
  accepts a single pin as input, this pin must be connected to "trig" and "echo" 
  on the ultrasonic sensor. the program switches between output and input to 
  create a ultrasonic pulse and read the result on one pin 
*/

class UltrasonicSensor {
  int _pin;
  const float SPEED_OF_SOUND = 0.340; // [meters / ms]

  public:    
    UltrasonicSensor(int pin) {
      _pin = pin;
    };

    int getDistanceInMm();

    float getDistanceInCm() {
      return ((float)getDistanceInMm()) / 10;
    }

    float getDistanceInInch() {
      return ((float)getDistanceInMm()) / 25.4;      
    }
};

#endif