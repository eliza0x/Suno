#include <Server.h>
// #include <Control.h>
// #include <Order.h>

SunoServer tuner;
// Control ctrl;

void setup(){
  tuner.wakeup("Buffalo-G-5040", "ww5xmrmwh7kxn");
  delay(3000);
  Serial.begin(9600);
//  ctrl.setMotorPin(12, 13);
//  ctrl.setServoPin(16);
} 

void loop(){
//  ctrl.moveFoward();
//  ctrl.rotateAngle(30);
//  delay(1000);
//  ctrl.moveBackward();
//  ctrl.rotateAngle(330);
//  delay(1000);
  Serial.println(tuner.fetchOrder());
  delay(500);
}
