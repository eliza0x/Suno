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
          client.println("<html><head><style>body{margin:50px;font-size:20px;font-weight:lighter;}a{color:#444;text-decoration:none;}ul{display:flex;justify-content:center;}li{border:solid 1px #222;border-radius:10px;margin:5px;padding:20px;list-style:none;width:70px;text-align:center;}</style></head><body><ul><li><a href=\"/Move/Right\">LeftF</a></li><li><a href=\"/Move/Right\">Forward</a></li><li><a href=\"/Move/Right\">RightF</a></li></ul><ul><li><a href=\"/Left\">Left</a></li><li><a href=\"/Stop\">Stop</a></li><li><a href=\"/Right\">Right</a></li></ul></body></html>");
          client.stop();
        }
      }
      return req;
    }
};
