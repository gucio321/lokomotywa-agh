#ifndef INPUTINO
#define INPUTINO
#include "Arduino.h"
#include "utils.ino"
#include "vendor/Adafruit_VL53L0X/src/Adafruit_VL53L0X.h"
#include <Wire.h>

auto DistanceSensor = Adafruit_VL53L0X();

void SetupInput() {
    Wire.begin(DistanceSensorSDA, DistanceSensorSCL);
    if (!DistanceSensor.begin()) {
    /*
        DebugPrint(F("Failed to boot VL53L0X"));
    */
        while (1);
    }
}

// IsTrainDetected returns true whenever a train is detected by our sensor.
bool IsTrainDetected() {
    // pseudo-random value generator xD
    return millis() % 2 == 0; // TODO
}

// ShouldResumeTrain returns true when a reobot finishes its job.
// It is designed to be able to occupy the main thread till true. If false returned this will be recalled till true.
bool ShouldResumeTrain() {
    delay(5000);
    return true;
}

#endif
