const int potPin = A0; // Pin connected to the potentiometer
const int ledPin = 9;  // Pin connected to the LED

void setup() {
  Serial.begin(9600); // Start the Serial communication at 9600 bps
  pinMode(ledPin, OUTPUT); // Set the LED pin as output
}

void loop() {
  int sensorValue = analogRead(potPin); // Read the potentiometer
  int ledBrightness = map(sensorValue, 0, 1023, 0, 255); // Map the value to 0-255
  analogWrite(ledPin, ledBrightness); // Set the LED brightness

  Serial.print("Potentiometer Value: ");
  Serial.print(sensorValue); // Print the potentiometer value
  Serial.print(" | LED Brightness: ");
  Serial.println(ledBrightness); // Print the LED brightness

  delay(100); // Wait for a short period before the next read
}
