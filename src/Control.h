/* サーボのヘッダファイルを準備 */
#include <Servo.h>

/* サーボモータの制御クラス */
class ServoIO{ //{{{

  Servo servo; /* サーボのピン */

  /* サーボモータが可動範囲外に回転するのを防ぐ関数*/
  int angleCalc(const int currentAngle, const int difference){
    const int sum = currentAngle + difference;
    if(sum < 5){return 0;}      /* 5度以下なら0度を返す */
    if(sum > 175){return 180;}  /* 175度以上なら180度を返す */
    return currentAngle + difference; 
  }

  protected:
    /* サーボを回転させる関数 */
    /* 値は0~180の間で */
    void rotateServo(const int difference){
      const int currentAngle = servo.read();
      const int changedAngle = angleCalc(currentAngle, difference);
      if(currentAngle != changedAngle){
        servo.write(changedAngle);
      }
    }

  public:
    /* サーボモータのピンを設定する関数 */
    /* 無くても良いが、あると統一感が生まれる */
    void setServoPin(const int pin){
      servo.attach(pin);
    }
}; //}}}

/* モータの制御クラス */
class MotorIO{ //{{{

  /* 優先度は Brake > Stop > Otherewise */
  bool isMoveFoward; /* 前進するか */
  bool isStop;       /* 停止するか */
  bool isBrake;      /* ブレーキするか */

  void brake(){/* Brake code here... */}
  void stop(){/* Stop code here... */}
  void moveFoward(){/* Move Foward code here... */}
  void moveBackward(){/* Move backward code here... */}

  public:
    void setMoveFoward(){ /* 前進するよう状態を変更 */
      isMoveFoward = true;
      isStop = false;
      isBrake = false;
    }
    void setMoveBackward(){ /* 後退するよう状態を変更 */
      isMoveFoward = false;
      isStop = false;
      isBrake = false;
    }
    void setStop(){ /* 停止するよう状態を変更 */
      isStop = true;
    }
    void setBrake(){ /* ブレーキするよう状態を変更 */
      isBrake = true;
    }

    void updateMotorState(){ /* モータの状態を更新 */
       if(isBrake){
        brake();
        return;
      }
      if(isStop){
        stop();
        return;
      }
      if(isMoveFoward){
        moveFoward();
        return;
      } else {
        moveBackward();
        return;
      }     
    }
};//}}}

/* 制御 クラス */
class Control: public ServoIO, public MotorIO{ //{{{
  int errorPin; /* エラーピンの番号を表す */

  void putError(void){
    digitalWrite(errorPin, HIGH); 
  }

  /* moveFooBarの抽象化関数 */
  void setAngleAndDirection(const int angle, const bool isFoward){
    rotateServo(angle);
    if(isFoward){setMoveFoward();}else{setMoveBackward();}
  }
  
  public:
    /* 左前に移動するよう状態を変更 */
    void setMoveLeftFoward(){setAngleAndDirection(-30, true);}
    /* 右前に移動するよう状態を変更 */
    void setMoveRightFoward(){setAngleAndDirection(30, true);}
    /* 左後に移動するよう状態を変更 */
    void setMoveLeftBackward(){setAngleAndDirection(-30, false);}
    /* 右後に移動するよう状態を変更 */
    void setMoveRightBackward(){setAngleAndDirection(30, false);}
    
    /* エラーLEDのピンを設定する関数 */
    void setErrorPin(const int pin){
      errorPin = pin;
      pinMode(pin,OUTPUT);
    }
};//}}}
