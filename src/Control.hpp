#include <Servo.h>

class ServoIO{
  Servo servo;
  public:
    void rotateAngle(const int angle){
      servo.write(angle);
    }
    void setServoPin(const int pin){
      servo.attach(pin);
      servo.write(90);
    }
};

class MotorIO{
  int motorPin;
  void setMotorState(const int fstState){
    digitalWrite(motorPin,  fstState);
  }
  public:
    void stop(){setMotorState(LOW);}
    void move(){setMotorState(HIGH);}
    void setMotorPin(const int pinNum){
      motorPin = pinNum;
      pinMode(motorPin, OUTPUT);
    }
};

class Control: public ServoIO, public MotorIO {};
