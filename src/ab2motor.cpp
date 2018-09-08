#include "ab2motor.h"

enum Pin {
  LeftMotorSpeed = 6,
  LeftMotorForward = A0,
  LeftMotorBackward = A1,
  RightMotorSpeed = 5,
  RightMotorForward = A2,
  RightMotorBackward = A3
};


AB2Motor::AB2Motor()
{}

void AB2Motor::begin()
{
  pinMode(LeftMotorSpeed, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);

  pinMode(RightMotorSpeed, OUTPUT);
  pinMode(RightMotorForward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);

  analogWrite(LeftMotorSpeed, 0);
  analogWrite(RightMotorSpeed, 0);

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(LeftMotorBackward, LOW);
  
  digitalWrite(RightMotorForward, HIGH); 
  digitalWrite(RightMotorBackward, LOW);
}

void AB2Motor::drive(int motor, int direction, int speed)
{
  if (motor == 0) { // Left
    if (direction == 0) { // Forward
      digitalWrite(LeftMotorBackward, LOW);
      digitalWrite(LeftMotorForward, HIGH);
    } else {
      digitalWrite(LeftMotorForward, LOW);
      digitalWrite(LeftMotorBackward, HIGH);
    }
    analogWrite(LeftMotorSpeed, speed);
  }
  else if (motor == 1) { // Right
    if (direction == 0) { // Forward
      digitalWrite(RightMotorBackward, LOW);
      digitalWrite(RightMotorForward, HIGH);
    } else {
      digitalWrite(RightMotorForward, LOW);
      digitalWrite(RightMotorBackward, HIGH);
    }
    analogWrite(RightMotorSpeed, speed);
  }
}
