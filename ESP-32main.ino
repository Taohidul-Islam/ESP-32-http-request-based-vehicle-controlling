#include <WiFi.h>
#include <ESPAsyncWebServer.h>

// Replace with your Wi-Fi credentials
const char* ssid = "SSID";
const char* password = "PASSWORD";

// Create an instance of the server
AsyncWebServer server(80);

// Define the GPIO pins to control
const int pin1 = 4;  // D4
const int pin2 = 5;  // D5
const int pin3 = 18; // D18
const int pin4 = 19; // D19
const int pin5 = 21; // D21

void setup() {
  Serial.begin(115200);

  // Set pin modes
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);

  // Connecting to Wi-Fi
  WiFi.begin(ssid, password);
  Serial.println("Connecting to Wi-Fi...");
  
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 20) {
    delay(1000);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Connected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println("Failed to connect to Wi-Fi.");
  }

  // Define HTTP GET requests to control pins
  server.on("/1on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin1, HIGH); // Turn pin1 on
    request->send(200, "text/plain", "Pin 1 is ON");
  });

  server.on("/1off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin1, LOW); // Turn pin1 off
    request->send(200, "text/plain", "Pin 1 is OFF");
  });

  server.on("/2on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin2, HIGH); // Turn pin2 on
    request->send(200, "text/plain", "Pin 2 is ON");
  });

  server.on("/2off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin2, LOW); // Turn pin2 off
    request->send(200, "text/plain", "Pin 2 is OFF");
  });

  server.on("/3on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin3, HIGH); // Turn pin3 on
    request->send(200, "text/plain", "Pin 3 is ON");
  });

  server.on("/3off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin3, LOW); // Turn pin3 off
    request->send(200, "text/plain", "Pin 3 is OFF");
  });

  server.on("/4on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin4, HIGH); // Turn pin4 on
    request->send(200, "text/plain", "Pin 4 is ON");
  });

  server.on("/4off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin4, LOW); // Turn pin4 off
    request->send(200, "text/plain", "Pin 4 is OFF");
  });

  server.on("/5on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin5, HIGH); // Turn pin5 on
    request->send(200, "text/plain", "Pin 5 is ON");
  });

  server.on("/5off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(pin5, LOW); // Turn pin5 off
    request->send(200, "text/plain", "Pin 5 is OFF");
  });

  // Start the server
  server.begin();
}

void loop() {
  // Nothing needed here for now, the server runs in the background
}
