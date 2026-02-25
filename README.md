# Standalone IoT Weather Station 🌡️

## Overview
A modular IoT system built using the ESP32 microcontroller and a BME280 environmental sensor. The device functions as a standalone web server that monitors temperature, humidity, and atmospheric pressure in real-time, providing a responsive dashboard accessible via Wi-Fi.

## Key Technical Features
* **Standalone Networking:** Operates in Soft Access Point (AP) mode, creating its own local Wi-Fi network for user connection.
* **Responsive Dashboard:** A mobile-friendly web interface served directly from the ESP32, featuring real-time data updates.
* **Data Persistence Logic:** Implementation of a memory-efficient Circular Buffer (FIFO) algorithm to store and display the 10 most recent readings within the limited RAM.
* **Hardware Robustness:** Automatic I2C address detection (0x77/0x76) and sensor initialization fail-safes.
* **Weather Prediction:** A threshold-based algorithm that provides local weather status updates based on pressure and humidity trends.

## Tech Stack
* **Microcontroller:** ESP32
* **Sensor:** Bosch BME280 (I2C Protocol)
* **Backend/Logic:** C/C++ (Arduino framework)
* **Frontend:** HTML5, CSS3, JavaScript

## Hardware Setup
The system uses standard I2C wiring:
* **VCC** -> 3.3V
* **GND** -> GND
* **SCL** -> GPIO 22
* **SDA** -> GPIO 21
