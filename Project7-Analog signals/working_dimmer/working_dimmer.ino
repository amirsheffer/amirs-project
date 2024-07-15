const int potPin = A0; // Pin connected to the potentiometer
const int flagpin = 4; // flag pin to measure


void setup() {
  pinMode(flagpin, OUTPUT);
}



void loop() { 
  digitalWrite(flagpin, LOW);  // Set pin 0 high
  analogRead(potPin); // Read potentiometer
  digitalWrite(flagpin, HIGH);  // Set pin 0 high 
}
