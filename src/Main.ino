#include "SunoServer.hpp"
#include "Control.hpp"

SunoServer serv;
Control ctrl;
String str;

void setup(){
  // We can use 12,13,4,5,16 and TOUT
  // TOUT estas analoga pinglo
  Serial.begin(9600);
  delay(100);
  ctrl.setMotorPin(12, 13);
  ctrl.setServoPin(16);
  serv.wakeup("SunoServer", "ww5xmrmwh7kxn");
  delay(2500);
} 

void loop(){
  str = serv.fetchOrder();
  move(str);
  delay(200);
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
  if(str.indexOf("Forward")   != -1){ctrl.moveFoward();}
  if(str.indexOf("Backward") != -1){ctrl.moveBackward();}
  if(str.indexOf("Stop")  != -1){ctrl.stop();}
  if(str.indexOf("Brake") != -1){ctrl.brake();}
}
