#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>

class MotorController {
  private:
    int motorAPin1;
    int motorAPin2;
    int motorBPin1;
    int motorBPin2;

  public:
    MotorController(int pin1, int pin2, int pin3, int pin4) {
      motorAPin1 = pin1;
      motorAPin2 = pin2;
      motorBPin1 = pin3;
      motorBPin2 = pin4;

      pinMode(motorAPin1, OUTPUT);
      pinMode(motorAPin2, OUTPUT);
      pinMode(motorBPin1, OUTPUT);
      pinMode(motorBPin2, OUTPUT);
    }

    void move(int speedA, int speedB) {
      if (speedA >= 0) {
        analogWrite(motorAPin1, speedA);
        digitalWrite(motorAPin2, LOW);
      } else {
        analogWrite(motorAPin1, -speedA);
        digitalWrite(motorAPin2, HIGH);
      }

      if (speedB >= 0) {
        analogWrite(motorBPin1, speedB);
        digitalWrite(motorBPin2, LOW);
      } else {
        analogWrite(motorBPin1, -speedB);
        digitalWrite(motorBPin2, HIGH);
      }
    }

    void stop() {
      digitalWrite(motorAPin1, LOW);
      digitalWrite(motorAPin2, LOW);
      digitalWrite(motorBPin1, LOW);
      digitalWrite(motorBPin2, LOW);
    }
};

#endif