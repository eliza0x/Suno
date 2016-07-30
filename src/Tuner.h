#include <ESP8266WiFi.h>
#include "Order.h"

WiFiServer server(80);
WiFiClient client;

class Tuner {
 
  public:
    void wakeup(const char* ssid, const char* password) {
      Serial.begin(9600);
      delay(1500);
      Serial.println();
      Serial.print("Connecting to ");
      Serial.print(ssid);
      WiFi.begin(ssid, password);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("");
      server.begin();
      Serial.println("Server started");
      Serial.println(WiFi.localIP());
    }
    
    String fetchOrder(){
      client = server.available();
      String req = "Nop";
      while(client){
        if(client.available()){
          req = client.readStringUntil('\n');
          Serial.println(req);
          delay(1);
          client.stop();
        }
      }
      return req;
    }
};
