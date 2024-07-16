// this code get commands a LED to light when it gets a signal from a button for a specific amount of time, that the human can choose (COM 4)

const int buttonPin = 2;  // Pin for the button
const int ledPin = 4;     // Pin for the LED
#include <MsTimer2.h>

unsigned long timerDuration = 5000; // Default timer duration
bool ledState = false;  // Track LED state

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(buttonPin), turnOn, RISING); // inturpts the loop when you press the button
  MsTimer2::set(timerDuration, turnOff); // timer
}
// this func turn on the LED when you press the button
void turnOn() {
  ledState = true; // Set LED state
  MsTimer2::start();
  digitalWrite(ledPin, true);
  Serial.println("LED turned on");
}
// this func turns off the LED after the time passes
void turnOff() {
  ledState = false; // Set LED state
  digitalWrite(ledPin, false);
  MsTimer2::stop();
  Serial.println("LED turned off");
}
// this updates the timer based on the choises of the human
void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    timerDuration = input.toInt();
    MsTimer2::set(timerDuration + 1, turnOff);
    Serial.print("Timer duration set to: ");
    Serial.println(timerDuration);
  }

  // Check button state and send corresponding status back to the computer
  if (ledState) {
    if (digitalRead(buttonPin) == LOW) {
      Serial.println('1'); // Button pressed and LED on
    } else {
      Serial.println('2'); // Button not pressed and LED on
    }
  } else {
    Serial.println('0'); // LED is off
  }

  delay(1000); // Small delay for readability
}
