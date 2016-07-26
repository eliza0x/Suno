#include <Servo.h>

/* サーボモータの制御クラス */
class ServoIO{ //{{{

  Servo servo; /* サーボのピン */

  protected:
    /* サーボを回転させる関数 */
    /* 値は0~180の間で */
    void rotateAngle(const int angle){
      servo.write(angle);
    }

  public:
    /* サーボモータのピンを設定する関数 */
    void setServoPin(const int pin){
      servo.attach(pin);
    }
}; //}}}

/* モータの制御クラス */
class MotorIO{ //{{{

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
    }
};//}}}

/* 制御 クラス */
class Control: public ServoIO, public MotorIO{ //{{{
  int errorPin; /* エラーピンの番号を表す */

  void putError(void){
    digitalWrite(errorPin, HIGH); 
  }

  public:
    /* エラーLEDのピンを設定する関数 */
    void setErrorPin(const int pin){
      errorPin = pin;
      pinMode(pin,OUTPUT);
    }
};//}}}
