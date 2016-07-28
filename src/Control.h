// #include "VarSpeedServo.h"
#include "Servo.h"
#include "Error.h"

/* サーボモータの制御クラス */
class ServoIO{
  
  Servo servo; /* サーボのピン */
  protected:
    /* サーボを回転させる関数 */
    void rotateAngle(const int angle){
      // servo.write(angle, 30, false);
      servo.write(angle);
    }
  public:
    /* サーボモータのピンを設定する関数 */
    void setServoPin(const int pin){
      servo.attach(pin);
      servo.write(0);
    }
};

/* モータの制御クラス */
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

/* 制御 クラス */
class Control: public ServoIO, public MotorIO, public Error{};
