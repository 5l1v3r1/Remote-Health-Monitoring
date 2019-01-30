#include "Arduino.h"
#include "dht.h"
#include <ESP8266WiFi.h>
#include "FirebaseArduino.h"  
dht DHT;

// Set these to connect to firebase
#include "UbidotsMicroESP8266.h"
#define TOKEN "A1E-YVt7A77us55Mv7YhOlAjWoTLdFUbpm"
#define FIREBASE_HOST "weather-hub-423f1.firebaseio.com"  //should not have http:// and the end /
#define FIREBASE_AUTH "CHPyddIQlnwM9WEXjVfihmB3Swgh82myLjrltB84"  // go to settings in firebase,select project settings and service account, secrets auth key

// Set these to connect to ESP8266
#define WIFI_SSID "AndroidAP3609"
#define WIFI_PASSWORD "rasagna123"

int pins[1] = {D5};
#define Apin A0
Ubidots client(TOKEN);

void setup() 
{
  Serial.begin(115200);
  pinMode(pins[0],INPUT);
  pinMode(Apin,INPUT);
  
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
 
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  client.wifiConnection(WIFI_SSID,WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  
  Firebase.set("Temperature",1);
  Firebase.set("Humidity",1);
  Firebase.set("GAS Intensity",1);
  
  delay(1000);
  
}
void firebasereconnect()
{
  Serial.println("Trying to reconnect");
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("Temperature",1);
  Firebase.set("Humidity",1);
  Firebase.set("GAS Intensity",1);
}


void loop() 
{
  // set value
  // handle error
  if (Firebase.failed())
  {
      Serial.print("setting number failed:");
      Serial.println(Firebase.error());  
      firebasereconnect();
      return;
  }
  int readdata = DHT.read11(pins[0]);
  float temperature = DHT.temperature;
  float humidity = DHT.humidity;
  float gas = analogRead(Apin);

  Firebase.set("Temperature",temperature);
  Firebase.set("Humidity",humidity);
  Firebase.set("GAS Intensity",gas);
  
  client.add("Temperature",temperature);
  client.add("Humidity",humidity);
  client.add("GAS Instensity",gas);
  
  client.sendAll(true);
  delay(1000);
  Serial.println(temperature);
  Serial.println(humidity);
  Serial.println(gas);
}
