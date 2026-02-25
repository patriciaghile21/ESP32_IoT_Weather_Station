#include <WiFi.h>
#include <WebServer.h>

#include "sensor.h" 
#include "design.h"

const char* ssid = "Weather Station";
const char* password = "";

WebServer server(80);

const int MAX_HISTORY = 10;
float tempHistory[MAX_HISTORY];
float humHistory[MAX_HISTORY];
float presHistory[MAX_HISTORY];
int historyCount = 0; 

void saveToHistory(float t, float u, float p) {
  for (int i = MAX_HISTORY - 1; i > 0; i--) {
    tempHistory[i] = tempHistory[i-1];
    humHistory[i] = humHistory[i-1];
    presHistory[i] = presHistory[i-1];
  }
  tempHistory[0] = t; 
  humHistory[0] = u; 
  presHistory[0] = p;
  
  if (historyCount < MAX_HISTORY) historyCount++;
}

void handle_Live() {
  float t = readTemperature();
  float u = readHumidity();
  float p = readPressure();

  if (isnan(t)) {
     server.send(200, "text/html", "<h1> Hardware Error! Check wiring.</h1>");
     return;
  }

  saveToHistory(t, u, p);
  
  String msg = predictWeather(u, p);

  server.send(200, "text/html", getHTML(t, u, p, msg)); 
}

void handle_History() {
  server.send(200, "text/html", getHistoryHTML(tempHistory, humHistory, presHistory, historyCount));
}

void setup() {
  Serial.begin(115200);

  initSensor();

  WiFi.softAP(ssid, password);
  Serial.print("Site IP: ");
  Serial.println(WiFi.softAPIP());

  server.on("/", handle_Live);
  server.on("/history", handle_History);
  
  server.begin();
}

void loop() {
  server.handleClient();
}