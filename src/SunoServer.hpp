#include <ESP8266WiFi.h>
#include "Error.hpp"

WiFiServer server(80);
WiFiClient client;

class SunoServer: public Error {
 
  public:
    void wakeup(const char* ssid, const char* password) {
      putWarning();
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
      clearWarning();
    }
    
    String fetchOrder(){
      client = server.available();
      String req = "Nop";
      while(client){
        if(client.available()){
          req = client.readStringUntil('\n');
          Serial.println(req);
          delay(1);
          client.println(req);
          client.stop();
        }
      }
      return req;
    }
};
