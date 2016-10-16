#include <ESP8266WiFi.h>

WiFiServer server(80);
WiFiClient client;

class Radio {
  int led;
  
  public:
    void wakeup(const char* ssid, const char* password, const int pin) {
      pinMode(led, OUTPUT);
      Serial.println();
      Serial.print("Connecting to ");
      Serial.print(ssid);
      WiFi.begin(ssid, password);
      digitalWrite(led, LOW);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      Serial.println("");
      server.begin();
      digitalWrite(led, HIGH);
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
