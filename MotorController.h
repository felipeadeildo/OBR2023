#ifndef MOTOR_CONTROLLER_H
#define MOTOR_CONTROLLER_H

#include <Arduino.h>


class MotorController {
private:
  int motorAPin1;
  int motorAPin2;
  int motorBPin3;
  int motorBPin4;

public:
  MotorController(int pin1, int pin2, int pin3, int pin4) {
    motorAPin1 = pin1;
    motorAPin2 = pin2;
    motorBPin3 = pin3;
    motorBPin4 = pin4;

    pinMode(motorAPin1, OUTPUT);
    pinMode(motorAPin2, OUTPUT);
    pinMode(motorBPin3, OUTPUT);
    pinMode(motorBPin4, OUTPUT);
  }

  void moveForward() {
    digitalWrite(motorAPin1, HIGH); // sentido pra frente
    digitalWrite(motorAPin2, LOW); // sentido pra traz
    digitalWrite(motorBPin3, HIGH); // idem
    digitalWrite(motorBPin4, LOW);
  }

  void moveBackward(){
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, HIGH);
    digitalWrite(motorBPin3, LOW);
    digitalWrite(motorBPin4, HIGH);
  }

  void moveLeft(){
    digitalWrite(motorAPin1, HIGH);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin3, LOW);
    digitalWrite(motorBPin4, HIGH);
  }

  void moveRight(){
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, HIGH);
    digitalWrite(motorBPin3, HIGH);
    digitalWrite(motorBPin4, LOW);
  }

  void stop(){
    digitalWrite(motorAPin1, LOW);
    digitalWrite(motorAPin2, LOW);
    digitalWrite(motorBPin3, LOW);
    digitalWrite(motorBPin4, LOW);

  }
};

#endif