// ESP32 controls L298N (motor driver) in the following way:
// - there are 6 control pins (3 per stepper)
// - clockwise= pin1=HIGH, pin2=LOW; counterclockwise= pin1=LOW, pin2=HIGH; stop= pin1=HIGH, pin2=HIGH
// - pin3 (reffered as speed pin) is PWM pin, range [0,255]
#include "setup.ino"
#include "utils.ino"
#include "Arduino.h"
// Przygotowanie do pracy
void setup() {
  setup_serial();

  DebugPrint("Hello from Lokomotywa AGH script!\n");
  DebugPrint("Preparing stuff...\n");
  setup_pins();

  DebugPrint("Preparation done. Proceed to loop...n");
}

// The main loop idea is as follows:
void loop() {
}
