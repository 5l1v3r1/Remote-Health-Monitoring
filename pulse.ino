#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to connect to firebase
#define FIREBASE_HOST "pulse-4ce69.firebaseio.com/"
#define FIREBASE_AUTH "CHjpewy5CMDfJWbGQsGzVuNAKsKLC4XFFZuEtTkY"


// Set these to connect to ESP8266
#define WIFI_SSID "AndroidAP3609"
#define WIFI_PASSWORD "rasagna123"
int PulseSensorPurplePin = 0;        // Pulse Sensor to ANALOG PIN 0
int LED =D2 ;                 //  The on-board Arduion LED

int i;
int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 100;        // Maximum safe pulse rate a person can bear


void setup() 
{
   Serial.begin(115200);
   pinMode(LED,OUTPUT);  
    

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
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.set("pulse",0);
}


void loop() {
  
   Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.
    Firebase.set("pulse",Signal);

   if(Signal > Threshold){                    // If the signal is above "100", then "turn-on" Arduino's on-Board LED.
     digitalWrite(LED,HIGH);
   }
   else 
   {
     digitalWrite(LED,LOW);                //  Else, the sigal must be below "100", so "turn-off" this LED.
   }
   delay(1000);
}
