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
    void servoPin(int pin){
      servo.attach(pin);
    }
}; //}}}

/* モータの制御クラス */
class MotorIO{ //{{{

  /* モータの状態を表す型 */
  struct MotorState{
    bool isMoveFoward; /* 前進するか */
    bool isStop;       /* 停止するか */
    bool isBrake;      /* ブレーキするか */
  };
  
  /* モータの現在の状態
     もう少し良い方法があれば書き直す */
  MotorState motorState = {true, false, false};

  /* モータの変更後の状態
     現在と違う状態がセットされていればmotor関数が状態を変更する */
  MotorState changedMotorState = {true, false, false};

  void motor(){
    if(motorState.isMoveFoward != changedMotorState.isMoveFoward ||
       motorState.isStop       != changedMotorState.isStop       ||
       motorState.isBrake      != changedMotorState.isBrake      ){
      motorState = changedMotorState;
      if(motorState.isBrake){
        brake();
        return;
      }
      if(motorState.isStop){
        stop();
        return;
      }
      if(motorState.isMoveFoward){
        moveFoward();
        return;
      } else {
        moveBackward();
        return;
      }     
    }
  }

  void brake(){
    // Brake code here...
  }
  void stop(){
    // Stop code here...
  }
  void moveFoward(){
    // Move Foward code here...
  }
  void moveBackward(){
    // Move backward code here...
  }

  public:
    /* 前進するよう状態を変更 */
    void toMoveFoward(){
      changedMotorState = {true,false, false};
    }
    /* 後退するよう状態を変更 */
    void toMoveBackward(){
      changedMotorState = {false,false, false};
    }
    /* 停止するよう状態を変更 */
    void toMoveStop(){
      changedMotorState = {true,true, false};
    }
    /* モータの状態を更新 */
    void updateMotorState(){
      motor();
    }
};//}}}

/* 制御のクラス */
class Control: public ServoIO, public MotorIO{ //{{{
  int errorPinNum; /* エラーピンの番号を表す */
  void error(void){
    digitalWrite(errorPinNum,HIGH); 
  }

  /* moveFooBarの抽象化関数 */
  void angleMove(const int angle, const bool isFoward){
    rotateServo(angle);
    if(isFoward){toMoveFoward();}else{toMoveBackward();}
  }
  
  public:
    /* 左前に移動するよう状態を変更 */
    void toMoveLeftFoward(){angleMove(-30, true);}
    /* 右前に移動するよう状態を変更 */
    void toMoveRightFoward(){angleMove(30, true);}
    /* 左後に移動するよう状態を変更 */
    void toMoveLeftBackward(){angleMove(-30, false);}
    /* 右後に移動するよう状態を変更 */
    void toMoveRightBackward(){angleMove(30, false);}
    /* エラーLEDのピンを設定する関数 */
    void errorPin(const int pin){
      errorPinNum = pin;
      pinMode(pin,OUTPUT);
    }
};//}}}

Control ctrl;

void setup(){
  ctrl.errorPin(13);
  ctrl.servoPin(9);
}

void loop(){
  ctrl.updateMotorState();
}
