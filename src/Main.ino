#include <SunoServer.hpp>
#include <Control.hpp>

SunoServer serv;
Control ctrl;
String str;

void setup(){
  ctrl.setMotorPin(12, 13);
  ctrl.setServoPin(16);
  serv.wakeup("SunoController", "password");
  delay(2500);
  Serial.begin(9600);
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
