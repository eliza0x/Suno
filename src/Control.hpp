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
  int firstPin;
  int secondPin;
  
  void setMotorState(const int fstState, const int sndState){
    digitalWrite(firstPin,  fstState);
    digitalWrite(secondPin, sndState);
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

class Control: public ServoIO, public MotorIO {};
