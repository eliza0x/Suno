/* サーボのヘッダファイルを準備 */
#include <Servo.h>

/* サーボモータの制御クラス */
class ServoIO{
  int angleCalc(const int currentAngle, const int difference){
    const int sum = currentAngle + difference;
    if(sum < 5){return 0;}
    if(sum > 175){return 180;}
    return currentAngle + difference; 
  }
  protected:
    void rotateServo(const int difference){
      const int currentAngle = servoPin.read();
      const int changedAngle = angleCalc(currentAngle, difference);
      servoPin.write(changedAngle);
    }
  public:
    Servo servoPin;
};

/* モータの制御クラス */
class MotorIO{
  struct MotorState{
    bool isMoveFoward;
    bool isStop;
  };
  MotorState motorState = {true, false};
  void motor(){
    if(! motorState.isStop){
      if(motorState.isMoveFoward){
        // Move Foward code here...
      } else {
       // Move backward code here...
      }
    } else {
      // Stop code here...
    }
  }
  protected:
    void moveFoward(){
      motorState = {true,false};
    }
    void moveBackward(){
      motorState = {false,false};
    }
    void moveStop(){
      motorState = {true,true};
    }
  public:
    void updateMotorState(){
      motor();
    }
};

/* 制御のクラス */
class Control: public ServoIO, public MotorIO{
  void error(void){
    digitalWrite(errorPin,HIGH); 
  }
  void angleMove(int angle, bool isFoward){
    rotateServo(angle);
    if(isFoward){moveFoward();}else{moveBackward();}
  }
  
  public:
    void leftFoward(){angleMove(-30, true);}
    void rightFoward(){angleMove(30, true);}
    void leftBackward(){angleMove(-30, false);}
    void rightBackward(){angleMove(30, false);}
    int errorPin;
    void setup(){
      pinMode(errorPin,OUTPUT);
    }
};

Control ctrl;

void setup(){
  ctrl.errorPin=13;
  ctrl.servoPin.attach(9);
}

void loop(){
//  rotateServo(90); 
//  rotateServo(-90); 
}



