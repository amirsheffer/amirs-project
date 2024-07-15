#include <MD_PWM.h>

const int ledPin = 4; // LED connected to pin 4
MD_PWM pwm(ledPin); // Initialize with the pin number

void setup() {
  pwm.begin();
  pwm.setFrequency(1000); // Set frequency to 1kHz for the PWM
}

void loop() {
  // Fade LED in
  for (int brightness = 0; brightness <= 255; brightness++) {
    pwm.write(brightness); // Set PWM value
    delay(10); // Adjust delay for speed of dimming
  }
  
  // Fade LED out
  for (int brightness = 255; brightness >= 0; brightness--) {
    pwm.write(brightness); // Set PWM value
    delay(10); // Adjust delay for speed of dimming
  }
}
