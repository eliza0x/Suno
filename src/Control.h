#include "Servo.h"
#include "Error.h"
#include "Order.h"

class ServoIO{
  
  Servo servo;

  public:
    void rotateAngle(const int angle){
      servo.write(angle);
    }
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

class Control: public ServoIO, public MotorIO, public Error{
 
  public:
    void move(const Order order){
      switch(order.direction){
        case 0:
          moveFoward();
          switch(order.angle){
            case 0:
              rotateAngle(330);
            case 1:
              rotateAngle(0);
            case 2:
              rotateAngle(30);
          }
        case 1:
          brake();
        case 2:
          moveBackward();
          switch(order.angle){
            case 0:
              rotateAngle(30);
            case 1:
              rotateAngle(0);
            case 2:
              rotateAngle(330);
          }
      }
    }
};
