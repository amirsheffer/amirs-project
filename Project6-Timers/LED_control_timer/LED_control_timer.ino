const int buttonPin = 2;  // Pin for the button
const int ledPin = 4;     // Pin for the LED
#include <MsTimer2.h>

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);           // Set LED pin as output
  Serial.begin(9600);
  // Attach interrupt to button pin, triggering on RISING
  attachInterrupt(digitalPinToInterrupt(buttonPin), turnOn, RISING);
  MsTimer2::set(5000, turnOff); // 5000ms period
  
}


void turnOn()
{
  MsTimer2::start();
  Serial.println("LED turned on");
  digitalWrite(ledPin, true); // Write the new state to the LED

}

void turnOff()
{
  Serial.println("LED turned off");
  digitalWrite(ledPin, false); // Write the new state to the LED
  MsTimer2::stop();
}


void loop()
{ Serial.println("amir");
delay(1000);
}
