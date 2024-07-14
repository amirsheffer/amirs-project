# Project 5 - Reacting to input part I: Interrupts

1. Make led light on button press
2. Learn how to debug code by establish communication with the computer using the Serial library
3. Understand the difference between polling and interrupt and benefits of using interrupts over polling
4. Learn how to use interrupts in Arduino

## Light led on button press (arduino code)
 - button pin is 6, grove led pin is 4
 - read value from button pin. If button is pressed (how can you tell?) turn grove led on. If button is not pressed, turn it off
 - test that this works.

## Simulate additional long process
- Add a delay(1000) to your loop.
- add Serial statements before and after the delay
- test if lighting led still works. Why or why not?
answer here: __________

## Use interrupt to light led
- Add code to create an interrupt pin (why can't it be the button pin?). Use a variable for this.
- Short the interrupt pin with the button pin
- test. Does it work?

## Exercises
 - commit and upload your code in this project folder.

this is the code for the project 

const int buttonPin = 2;  // Pin for the button
const int ledPin = 4;     // Pin for the LED

volatile bool ledState = false; // State of the LED

void setup() {
  pinMode(buttonPin, INPUT_PULLUP); // Set button pin as input with internal pull-up resistor
  pinMode(ledPin, OUTPUT);           // Set LED pin as output
  Serial.begin(9600);
  // Attach interrupt to button pin, triggering on CHANGE
  attachInterrupt(digitalPinToInterrupt(buttonPin), toggleLED, CHANGE);
}

void loop() {
  // Main loop does nothing; LED state is handled in the interrupt
}

// Interrupt function to toggle LED state
void toggleLED() {
  ledState = !ledState; // Toggle the LED state
  Serial.println(ledState);
  digitalWrite(ledPin, ledState ? HIGH : LOW); // Write the new state to the LED
}
