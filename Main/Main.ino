/* サーボのヘッダファイルを準備 */
#include "Control.h"

Control ctrl;

void setup(){
  ctrl.setErrorPin(13);
  ctrl.setServoPin(9);
  ctrl.setMotorPin(2,3);
}

void loop(){
}
