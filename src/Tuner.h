#include <ESP8266WiFi.h>

WiFiClient client;
WiFiServer server(80);

class Tuner {

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
    
    void responceRequest(){
      client = server.available();
      String req;
      
      while(client){
        if(client.available()){
          req = client.readStringUntil('\n');
          Serial.println(req);
          delay(1);
          client.stop();
        }
      }
    }
};
