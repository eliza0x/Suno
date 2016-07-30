#include <SunoServer.hpp>
#include <Control.hpp>

SunoServer tuner;
Control ctrl;
String str;

void setup(){
  ctrl.setMotorPin(12, 13);
  ctrl.setServoPin(16);
  tuner.wakeup("Buffalo-G-5040", "ww5xmrmwh7kxn");
  delay(3000);
  Serial.begin(9600);
} 

void loop(){
  str = tuner.fetchOrder();
  move(str);
  delay(100);
}

void move(String req){
  searchAngle(req);
  searchDirection(req);
}

void searchAngle(String str){
  if(str.indexOf("Left")   != -1){ctrl.rotateAngle(60);}
  if(str.indexOf("Center") != -1){ctrl.rotateAngle(90);}
  if(str.indexOf("Right")  != -1){ctrl.rotateAngle(120);}
}

void searchDirection(String str){
  if(str.indexOf("Foward")   != -1){ctrl.moveFoward();}
  if(str.indexOf("Neutral")  != -1){ctrl.stop();}
  if(str.indexOf("Backward") != -1){ctrl.moveBackward();}
  if(str.indexOf("Brake") != -1){ctrl.brake();}
}
