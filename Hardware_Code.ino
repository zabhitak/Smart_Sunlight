#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Set these to run example.
#define FIREBASE_HOST "smart-sunlight.firebaseio.com"
#define FIREBASE_AUTH "pmsAEfTaaBuYy8dsUVZKEXnZ9q4kIYlZ9lHtGTBD"
#define WIFI_SSID "Tenda_7C0260"
#define WIFI_PASSWORD "zabhitak"

int ledPin = D2;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.setInt("Room",0);
}
int n = 0;
void room()
{
  n=Firebase.getInt("Rooms/Block A/A-201/LEDs/LED 1/Value");
  Serial.println(n);
  if(n==0)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
}

void loop() {
room();
}
