# Arduino Sonar System

This is a simple radar system

A simple sonar/radar system using an HC-SR04 Ultrasonic sensor mounted on a sweeping SG90 Servo motor.

## Features
* **Distance Detection:** Measures range up to 350cm.
* **Visual Feedback:** RGB LED changes color based on proximity (Green > Yellow > Red).
* **Audible Alerts:** Piezo buzzer changes pitch when objects are in the "Critical" zone.
* **Auto-Sweep:** Servo sweeps 90 degrees to scan the area.

## Components
* Arduino Uno (or compatible)
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* RGB LED (Common Cathode)
* Piezo Buzzer
* 220 Ohm Resistors (for LED)

## Setup
1. Connect the pins as defined in the code (Trig: 13, Echo: 12, Servo: 7).
2. Open the Serial Monitor at **115200 Baud** to see live distance data.
