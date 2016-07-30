#include "Tuner.h"
#include "Control.h"
#include "Order.h"

Tuner tuner;
Control ctrl;

void setup(){
  tuner.wakeup("Buffalo-G-5040", "ww5xmrmwh7kxn");
  Serial.begin(9600);
  ctrl.setErrorPin(12);
  ctrl.setServoPin(13);
  ctrl.setMotorPin(4,5);
} 

void loop(){
  ctrl.move(tuner.fetchOrder());
  delay(300);
}
