/* サーボのヘッダファイルを準備 */
#include <Servo.h>
#include "Control.h"

Control ctrl;

void setup(){
  ctrl.errorPin(13);
  ctrl.servoPin(9);
}

void loop(){
  ctrl.updateMotorState();
}
