# Arduino Sonar System

This is a simple sonar system that uses a HC-SR04 Ultrasonic sensor thats mounted on a SG90 Servo motor

## What does it do?
* **Distance Detection:** Measures objects up to 350cm
* **Visual Feedback:** The RGB LED changes its color based on the proximity of the object (Green -> Yellow -> Red)
* **Audible Alerts:** The Piezo buzzer changes its pitch when objects are in the Crticial (Red) and or Warning (Yellow) zone
* **Auto Sweep:** The Servo motor moves from 0 to 90 degrees (default) to scan the area. But can be changed in the configuration

## Components used
* Arduino Uno (or compatible)
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor
* RGB LED (Common Cathode)
* Piezo Buzzer
* 3x 330 Ohm Resistors (for LED)

## Setup
1. Connect the pins as defined in the code or follow the circuit diagram
2. Optional but you can also open the Serial Monitor at **115200 Baud** to see the live distance of the objects infront of the sonar scanner
#### Note: The HC-SR04 has a maximum reliable range of about 400cm. This project is configured to cap the output at 350cm if an object is out of range or no echo is received

## Configuration
You can change the distance on how far the critical and warning are and also change the sweep range of the servo motor (capped at 180)
* `DIST_CRITICAL`: Distance for the Red LED / High Pitch alert.
* `DIST_WARNING`: Distance for the Yellow LED / Low Pitch alert.
* `SERVO_MIN_ANGLE`: The minimum sweep limit (default 0°).
* `SERVO_MAX_ANGLE`: The maximum sweep limit (default 90°, maximum 180).
