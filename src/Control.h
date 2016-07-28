#include "Servo.h"
#include "Error.h"

class ServoIO{
  
  Servo servo;
  protected:
    void rotateAngle(const int angle){
      servo.write(angle);
    }
  public:
    void setServoPin(const int pin){
      servo.attach(pin);
      servo.write(0);
    }
};

class MotorIO{
  int firstPin;
  int secondPin;
  
  void setMotorState(const int fst, const int snd){
    digitalWrite(firstPin, fst);
    digitalWrite(secondPin, snd);
  }
  public:
    void brake(){setMotorState(HIGH,HIGH);}
    void stop(){setMotorState(LOW,LOW);}
    void moveFoward(){setMotorState(HIGH,LOW);}
    void moveBackward(){setMotorState(LOW,HIGH);}

    void setMotorPin(const int fst, const int snd){
      firstPin = fst;
      secondPin = snd;
      pinMode(firstPin, OUTPUT);
      pinMode(secondPin, OUTPUT);
      setMotorState(firstPin, secondPin);
    }
};

class Control: public ServoIO, public MotorIO, public Error{};
