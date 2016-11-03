#include "Radio.hpp"
#include "Control.hpp"

Radio serv;
Control ctrl;
String str;

void setup(){
  Serial.begin(9600);
  delay(100);
  ctrl.setMotorPin(14);
  ctrl.setServoPin(5);
  serv.wakeup("taiyoooo", "mofumofu",12);
  delay(2500);
} 

void loop(){
  str = serv.fetchOrder();
  move(str);
  delay(200);
}

void move(String req){
  if(str.indexOf("Left")   != -1) { ctrl.rotateAngle(75); }
  if(str.indexOf("Center") != -1) { ctrl.rotateAngle(90); }
  if(str.indexOf("Right")  != -1) { ctrl.rotateAngle(105);}
  if(str.indexOf("Move")   != -1) { ctrl.move();          }
  if(str.indexOf("Stop")   != -1) { ctrl.stop();          }
}
