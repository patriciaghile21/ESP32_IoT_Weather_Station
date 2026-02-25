#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>

Adafruit_BME280 bme; 

void initSensor() {
  Serial.println("Initializing Hardware...");
  
  Wire.begin(21, 22);

  if (!bme.begin(0x77)) {
    Serial.println("Not found at 0x77, trying 0x76...");
    if (!bme.begin(0x76)) {
       Serial.println("FATAL ERROR: Sensor not responding!");
    } else {
       Serial.println("Sensor connected at 0x76.");
    }
  } else {
    Serial.println("Sensor connected at 0x77.");
  }
}

float readTemperature() {
  return bme.readTemperature();
}

float readHumidity() {
  return bme.readHumidity();
}

float readPressure() {
  return bme.readPressure() / 100.0F;
}

String predictWeather(float u, float p) {
  if (u > 80 && p < 1010) return "🌧️ WARNING: Rain expected!";
  if (u > 60) return "☁️ Cloudy.";
  if (u < 40) return "☀️ Clear sky.";
  return "⛅ Variable weather.";
}