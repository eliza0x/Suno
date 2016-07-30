#include <ESP8266WiFi.h>
#include "Order.h"

WiFiServer server(80);
WiFiClient client;

class Tuner {
  
  Order reqToOrder(const String req){
    int dir;
    int ang;
    Order order;
    
    if(req.indexOf("Foward") != -1 ){
      dir = 0;
    } else if(req.indexOf("Backward") != -1 ){
      dir = 2;
    }

    if(req.indexOf("Right") != -1 ){
      ang = 0;
    } else if(req.indexOf("Left") != -1 ){
      ang = 2;
    }
    order.angle = ang;
    order.direction = dir;
    return order;
  }

  public:

    void wakeup(const char* ssid, const char* password) {
      Serial.begin(9600);
     
      delay(500);
      Serial.println();
      Serial.print("Connecting to ");
      Serial.print(ssid);
      
      WiFi.begin(ssid, password);
      
      while (WiFi.status() != WL_CONNECTED) {
        delay(300);
        Serial.print(".");
      }
      Serial.println("");
      Serial.println("WiFi connected");
      
      server.begin();
      Serial.println("Server started");
    
      Serial.println(WiFi.localIP());
    }
    
    Order fetchOrder(){
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
      return reqToOrder(req);
    }
};
