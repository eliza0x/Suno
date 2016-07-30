#include <ESP8266WiFi.h>

WiFiServer server(80);
WiFiClient client;

class SunoServer {
 
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
          client.println(req);
          client.stop();
        }
      }
      return req;
    }
};
