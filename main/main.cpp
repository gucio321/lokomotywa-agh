// ESP32 controls L298N (motor driver) in the following way:
// - there are 6 control pins (3 per stepper)
// - clockwise= pin1=HIGH, pin2=LOW; counterclockwise= pin1=LOW, pin2=HIGH; stop= pin1=HIGH, pin2=HIGH
// - pin3 (reffered as speed pin) is PWM pin, range [0,255]
#include "setup.ino"
#include "utils.ino"
#include "engine_control.ino"
#include "input.ino"
#include <iostream>

#if defined(ESP_PLATFORM)
#include "Arduino.h"
#endif

state currentState;

// Przygotowanie do pracy
void setup() {
  setup_serial();

  DebugPrint("Hello from Lokomotywa AGH script!\n");
  DebugPrint("Preparing stuff...\n");
  setup_pins();

  DebugPrint("Preparation done. Proceed to loop...n");

  currentState = IsTrainDetected() ? Idle : Running;
  EngineA.Rotate(Left); // set up rotation
}

// The main loop.
// The flow should be as follows:
// - assume we start with a train on the sensor (IsTrainDetected == true); state is Idle.
// - We call ShouldResume Train (until it returns true)
// - We switch state to Starting
// - the engine starts up (see below). We do not run IsTrainDetected in this state (the train must leave our sensor :D )
// - when the startup is complete (some arbitrary value on the pwm) we switch to the Running state. Ideally in this state we will start checking ffor the train on sensor.
//   Alternatively we could also add some variable checking for train leaving the sensor (TODO)
// - When the IsTrainDetected returns true, we immediately proceed to Stopping phase.
// - when engine fully stopped, the cycle repeats.
void loop() {
  char buff[20];
  std::sprintf(buff, "state: %d", currentState);
  DebugPrint(buff);

  // 1: Run Resume if appliable
  if (currentState == Idle) {
          if (ShouldResumeTrain()) {
                  DebugPrint("Resuming train movement\n");
                  currentState = Starting;
          } else {
                DebugPrint("Not resuming. Exitting main loop");

                return; // there is no sense to continue here. We MUST get true to ontinue.
          }
  }

  // 1: Detect state changes
  if (IsTrainDetected() && currentState == Running) {
          DebugPrint("Train detected! Stopping train\n");
          currentState = Stopping;
  }

  // 2: Run state-specific commands
  int factor = 1;
  state destination = Running;
  int destinationVal = 255;
  switch (currentState) {
        case Stopping: // I want it to fallthrough (this is my briliant idea hehe.
                factor = -1;
                destinationVal = 0;
                destination = Idle;
        case Starting:
                DebugPrint("starting/stopping mode\n");
                EngineA.setSpeed(EngineA.getSpeed() + factor*SPEED_CHANGE_FACTOR);
                sprintf(buff, "speed: %d\n", EngineA.getSpeed());
                DebugPrint(buff);
                if (EngineA.getSpeed() == destinationVal) {
                        currentState = destination;
                }

                break;
        case Idle: // unreachable
        case Running: // the only thing we're looking for is TrainDetected
                DebugPrint("running mode\n");
                EngineA.setSpeed(255);
                break;
        }
}
