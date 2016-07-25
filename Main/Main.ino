/* サーボのヘッダファイルを準備 */
#include <Servo.h>
#include "Control.h"

Control ctrl;

void setup(){
  ctrl.setErrorPin(13);
  ctrl.setServoPin(9);
}

void loop(){
  ctrl.updateMotorState();
}
