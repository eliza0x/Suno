#include "VarSpeedServo.h"
#include "Error.h"

/* サーボモータの制御クラス */
class ServoIO{
  
  VarSpeedServo servo; /* サーボのピン */
  protected:
    /* サーボを回転させる関数 */
    void rotateAngle(const int angle){
      servo.write(angle, 30, false);
    }
  public:
    /* サーボモータのピンを設定する関数 */
    void setServoPin(const int pin){
      servo.attach(pin, 544, 2400);
      servo.write(0, 255, true);
    }
};

/* モータの制御クラス */
class MotorIO{
  struct Motor{
    int firstPin;
    int secondPin;
  };
  Motor motor = {LOW, LOW};
  
  void setMotorState(const int fst, const int snd){
    digitalWrite(motor.firstPin, fst);
    digitalWrite(motor.secondPin, snd);
  }
  public:
    void brake(){setMotorState(HIGH,HIGH);}
    void stop(){setMotorState(LOW,LOW);}
    void moveFoward(){setMotorState(HIGH,LOW);}
    void moveBackward(){setMotorState(LOW,HIGH);}
    void setMotorPin(const int fstPin, const int sndPin){
      motor = {fstPin, sndPin};
      pinMode(fstPin, OUTPUT);
      pinMode(sndPin, OUTPUT);
      setMotorState(fstPin, sndPin);
    }
};

/* 制御 クラス */
class Control: public ServoIO, public MotorIO, public Error{};
