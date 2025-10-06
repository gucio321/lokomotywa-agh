#ifndef INPUTINO
#define INPUTINO
#include "Arduino.h"
#include "utils.ino"
#include <Adafruit_VL53L0X.h>
#include <Wire.h>
#include <iostream>

auto DistanceSensor = Adafruit_VL53L0X();

void SetupInput() {
    if (!Wire.begin(DistanceSensorSDA, DistanceSensorSCL)) {
        DebugPrint("Failed initialize I2C on specified ports!");
        while (1);
    }

    DebugPrint("I2C initialized.");

    if (!DistanceSensor.begin()) {
        DebugPrint("Failed to boot VL53L0X");
        while (1);
    }

    DebugPrint("VL53L0X Ready.");
}

// IsTrainDetected returns true whenever a train is detected by our sensor.
bool IsTrainDetected() {
  /*
    if (!DistanceSensor.isRangeComplete()) {
        DebugPrint("Sensor not ready!");
        return false;
    }
    */

    auto distance = DistanceSensor.readRange();

    char buffer[32];
    std::sprintf(buffer, "Distance: %d mm", distance);

    DebugPrint(buffer);

    return distance <= TrainDetectionThreshold;
}

// ShouldResumeTrain returns true when a reobot finishes its job.
// It is designed to be able to occupy the main thread till true. If false returned this will be recalled till true.
bool ShouldResumeTrain() {
    delay(5000);
    return true;
}

#endif
