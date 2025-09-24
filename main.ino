// ESP32 controls L298N (motor driver) in the following way:
// - there are 6 control pins (3 per stepper)
// - clockwise= pin1=HIGH, pin2=LOW; counterclockwise= pin1=LOW, pin2=HIGH; stop= pin1=HIGH, pin2=HIGH
// - pin3 (reffered as speed pin) is PWM pin, range [0,255]
#include "setup.ino"

// Przygotowanie do pracy
void setup() {
  setup_serial();
  setup_pins();
}

// main loop
void loop() {
  DebugPrint("Begin frame\n");

  int n=127;
  _mSetSpeed(speedPinA,n);
  _mSetSpeed(speedPinB,n);
}

// Zakres prędkości [0,255]
