#include <Arduino.h>
#include <U8x8lib.h>
#include "LIS3DHTR.h"
#include <Wire.h>
#include <Servo.h>

// Servo variables
Servo myservo;  // Create servo object to control a servo
int pos = 0;    // Variable to store the servo position
int fanPin = 7; // Set D7 as control switch 
int fanState = LOW;
const float g = 9.8; // Acceleration due to gravity in m/s^2
// Accelerometer setup
LIS3DHTR<TwoWire> LIS; // IIC
#define WIRE Wire

U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(U8X8_PIN_NONE);

void setup() {
  // Setup for the OLED and font
  u8x8.begin();
  u8x8.setFlipMode(1);
  Serial.begin(115200);
  while (!Serial) { }

  // Accelerometer setup
  LIS.begin(WIRE, LIS3DHTR_ADDRESS_UPDATED);
  delay(100);
  LIS.setOutputDataRate(LIS3DHTR_DATARATE_50HZ);
  
  // Servo setup
  myservo.attach(3);  // Attaches the servo on pin 3 to the servo object
  pinMode(fanPin, OUTPUT);
}

void loop() {
  // Makes fan rotate
  fanState = HIGH;
  digitalWrite(fanPin, fanState);

  // Move servo from 0 to 100 degrees
  for (pos = 0; pos <= 100; pos += 1) {
    myservo.write(pos);              // Tell servo to go to position in variable 'pos'
    delay(40);                       // Waits 40ms for the servo to reach the position
  }

  // Move servo from 100 to 0 degrees
  for (pos = 100; pos >= 0; pos -= 1) {
    myservo.write(pos);              // Tell servo to go to position in variable 'pos'
    delay(40);                       // Waits 40ms for the servo to reach the position
  }

   float zAcceleration = LIS.getAccelerationZ();

  
  // Calculate elevation angle
  float angle = 180 - ((zAcceleration + 1) / 2) * 180; 

  // float angle = atan(zAcceleration / g) * (180.0 / PI); // Convert to degrees

  // Display information
  u8x8.setFont(u8x8_font_chroma48medium8_r);
  
  if (!LIS) {
    u8x8.setCursor(0, 0);
    u8x8.print("LIS3DHTR didn't connect.");
    while (1);
  }

  u8x8.setCursor(0, 0);
  u8x8.print("Elevation angle:");  
  u8x8.setCursor(0, 2);
  u8x8.print(angle);
  u8x8.print(" degrees");

  delay(100); // Delay before the next update
}
