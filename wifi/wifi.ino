#include <ESP8266WiFi.h>
#include <string.h>
const char* ssid = "Wifi SSID";
const char* pass = "Password";
char Data;

WiFiServer server(65432);
WiFiClient clint;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  WiFi.begin(ssid,pass);
  Serial.println("connecting to wifi");
  while(WiFi.status()!= WL_CONNECTED){delay(500);}
  Serial.println("connected sucessfully");
  
  Serial.println(WiFi.localIP());
  Serial.println(WiFi.macAddress());
  
  server.begin();
}

void ReadData(){
    while(clint.available()){
      Data = clint.read();
      Serial.println(Data);
    }
    clint.println("recieved!");   
}

void loop() {
  
  clint = server.available();
  
  if(clint){
    if(clint.connected()){
      Serial.println("Clint is connected!");
      ReadData();
    }
    else{clint.stop();}
  }
 delay(500);
}
