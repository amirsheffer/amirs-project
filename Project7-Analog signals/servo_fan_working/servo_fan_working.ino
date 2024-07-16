// this code turns PMW into rotational angle (0 to 180 deg) of a "servo fan"
// ot maps the potentpometer resulotion (2^10 bit) to deg (0 to 180) and then writes it to the pin

#include <Servo.h>

Servo fanServo;  // Create a servo object

const int potPin = A0; // Pin connected to the potentiometer
const int servoPin = 7;  // Pin connected to the LED. needed short pin 4 to pin 9 de to compitabilty


void setup() {
  fanServo.attach(7);
  Serial.begin(9600); // Start the Serial communication at 9600 bps
  // pinMode(ledPin, OUTPUT);  // Attach the signal pin to pin digital 7
}

void loop() {
   int sensorValue = analogRead(potPin); // Read the potentiometer
   int servoPos = map(sensorValue, 0, 1023, 0, 180); // Map the value to 0-160 deg
   fanServo.write(servoPos); // Set the LED brightness


  }

