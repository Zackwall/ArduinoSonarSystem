//
// Sonar System - Zack Wall
// Version: 1.0.0
// March 8, 2026
//

#include <Servo.h>

// Hardware Pins
const int PIN_LED_RED   = 5 ; // needs to be connected to a PWM pin (make sure its not on the same timer as the servo which is is 9 and 10)
const int PIN_LED_GREEN = 6 ; // needs to be connected to a PWM pin (make sure its not on the same timer as the servo which is is 9 and 10)
const int PIN_LED_BLUE  = 11; // needs to be connected to a PWM pin (make sure its not on the same timer as the servo which is is 9 and 10)
const int PIN_BUZZER    = 8 ;
const int PIN_SERVO     = 7 ;
const int PIN_TRIG      = 13;
const int PIN_ECHO      = 12;

// Configuration
const int DIST_CRITICAL   = 10; // Anything less than the number defined is critical                     (distance is in cm)
const int DIST_WARNING    = 20; // Anything greater than critical and less the number defined is warning (distance is in cm)
const int SERVO_MAX_ANGLE = 90; // The servo's max angle in degrees
const int SERVO_MIN_ANGLE = 0 ; // The servo's min angle in degrees

Servo SONARSERVO;
int distance;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_LED_RED   , OUTPUT);
  pinMode(PIN_LED_GREEN , OUTPUT);
  pinMode(PIN_LED_BLUE  , OUTPUT);
  pinMode(PIN_BUZZER    , OUTPUT);
  pinMode(PIN_TRIG      , OUTPUT);
  pinMode(PIN_ECHO      , INPUT );

  SONARSERVO.attach(PIN_SERVO);
}

void loop() {
  calculateDistance();
  servoMovement();
  handleAlerts();

  delay(20); // 20 milliseconds
}

// Using the ultrasonic sensor, this will find the distance of the objects infront of it
void calculateDistance() {
  // Will shoot sound waves (too high to even be heard)
  digitalWrite(PIN_TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(PIN_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_TRIG, LOW);

  // Will listen for how long the sound came back for (in microseconds) if the sound doesnt come back it will return 0
  unsigned long duration = pulseIn(PIN_ECHO, HIGH, 20000);

  // Multiplying the duration with the speed of sound in centimeters per microsecond and dividing it by 2 will give the
  // distance of the sensor and the object. If the duration is 0 it will return 350cm which is around the range the
  // ultrasonic sensor can detect
  distance = duration * 0.034 / 2;
  if (distance == 0) 
    distance = 350;
  
  Serial.println("Distance: " + String(distance) + "cm");
}

// This will make the servo motor (SG90) move from its min degrees to its max degrees and back again on repeat
void servoMovement() {
  static int angle = SERVO_MIN_ANGLE;
  static bool increasing = true;

  if (increasing == true) {
    angle++;
    if (angle >= SERVO_MAX_ANGLE) increasing = false;

  } else if (increasing == false) {
    angle--;
    if (angle <= SERVO_MIN_ANGLE) increasing = true; }

  SONARSERVO.write(angle);
}

// This will check its critical, warning, or safe distance
void handleAlerts() {
  // Critical distance
  if (distance < DIST_CRITICAL) {
    tone(PIN_BUZZER, 500, 20);
    setColor(255, 0, 0); // Red

  // Warning distance
  } else if (distance <= DIST_WARNING) {
    tone(PIN_BUZZER, 1000, 20);
    setColor(255, 125, 0); // Yellow
    
  // Safe distance
  } else {
    setColor(0, 255, 0); // Green
}}

// This will set the RGB color of the LED
void setColor(int R, int G, int B) {
  analogWrite(PIN_LED_RED,   R);
  analogWrite(PIN_LED_GREEN, G);
  analogWrite(PIN_LED_BLUE,  B);
}