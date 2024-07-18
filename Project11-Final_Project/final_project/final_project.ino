#include <Arduino.h>
#include <U8x8lib.h>
#include "LIS3DHTR.h"
#include <Wire.h>
#include <Servo.h>

// Servo variables
Servo myservo;  
int pos = 0;    
int fanPin = 7; 
int fanState = LOW;
int BuzzerState = LOW;
int BuzzerPin = 5;

// Accelerometer setup
LIS3DHTR<TwoWire> LIS; 
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
  myservo.attach(3); // Attach servo to pin 3
  pinMode(fanPin, OUTPUT);

// buzer setup
  pinMode(BuzzerPin, OUTPUT);

}
void loop() {
  // Makes fan rotate
  fanState = HIGH;
  digitalWrite(fanPin, fanState);

  // Read Z-axis acceleration
  float zAcceleration = LIS.getAccelerationZ();
  
  // Map Z-axis acceleration from [-1, 1] to [180, 0]
  float angle = 180 - ((zAcceleration + 1) / 2 * 180); 

  

  // Check angle for buzzer 
  if (angle > 100) {
    tone(BuzzerPin, 250); // Turn buzzer ON
  } else {
    noTone(BuzzerPin); // Turn buzzer OFF
  }

// Set servo position to the calculated angle
  myservo.write(angle); 

  // Display information
  u8x8.setFont(u8x8_font_chroma48medium8_r); // Use smaller font
  
  // if (!LIS) {
  //   u8x8.setCursor(0, 0);
  //   u8x8.print("LIS3DHTR didn't connect.");
  //   while (1);
  // }

  u8x8.setCursor(0, 0);
  u8x8.print("Elevation angle:");  
  u8x8.setCursor(0, 1);
  u8x8.print(angle);
  u8x8.print(" degrees");

  delay(100); // Smaller delay before the next update
}
