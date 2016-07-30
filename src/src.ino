#include "Tuner.h"
// #include "Control.h"
// #include "Order.h"

Tuner tuner;
// Control ctrl;

void setup(){
  tuner.wakeup("Buffalo-G-5040", "ww5xmrmwh7kxn");
  delay(3000);
  Serial.begin(9600);
} 

void loop(){
  Serial.println(tuner.fetchOrder());
  delay(500);
}
