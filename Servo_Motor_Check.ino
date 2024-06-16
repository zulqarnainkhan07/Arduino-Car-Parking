#include <Servo.h> // Include the Servo library

Servo servo; // Create a Servo object named 'servo'

void setup() {
  servo.attach(9); // Attach the servo to pin 9
  servo.write(0); // Set initial position to 0 degrees
  delay(2000); // Delay for 2 seconds for the servo to reach its initial position
}

void loop() {
  servo.write(180); // Move servo to 180 degrees
  delay(1000); // Wait for 1 second
  servo.write(0); // Move servo back to 0 degrees
  delay(1000); // Wait for 1 second
}
