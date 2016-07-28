#include <ESP8266WiFi.h>
#include "Tuner.h"

Tuner tuner;

void setup(){
  tuner.wakeup("Buffalo-G-5040", "ww5xmrmwh7kxn");
} 


void loop(){
  tuner.responceRequest();
  delay(1);
}
