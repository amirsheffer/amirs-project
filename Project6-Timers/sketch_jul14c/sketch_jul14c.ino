const int buttonPin = 2;  // Pin for the button
const int ledPin = 4;     // Pin for the LED
#include <MsTimer2.h>
volatile bool ledState = false; // State of the LED


void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);           // Set LED pin as output
  Serial.begin(9600);
  // Attach interrupt to button pin, triggering on RISING
  attachInterrupt(digitalPinToInterrupt(buttonPin), turnOn, RISING);

  MsTimer2::set(5000, turnOn); // 5000ms period
  MsTimer2::start();
 // MsTimer2::stop();
}


void turnOn()
{
  static boolean output = HIGH;
  
  //digitalWrite(ledPin, output);
  Serial.println(ledState ? "LED turned on" : "LED turned off");
  digitalWrite(ledPin, ledState ? HIGH : LOW); // Write the new state to the LED
  ledState =! ledState ;
}


void loop()
{ Serial.println("amir");
delay(1000);
}
