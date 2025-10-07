#ifndef INPUTINO
#define INPUTINO
#include "Arduino.h"
#include "utils.ino"
#include <Adafruit_VL53L0X.h>
#include <Wire.h>
#include <iostream>

auto DistanceSensorA = Adafruit_VL53L0X();
auto DistanceSensorB = Adafruit_VL53L0X();

void SetupInput() {
    DebugPrint("Initializin I2C distance sensors...");
    if (!Wire.begin(DistanceSensorSDA, DistanceSensorSCL)) {
        DebugPrint("Failed initialize I2C on specified ports (ESP will be trapped here)!");
        while (1);
    }

    DebugPrint("I2C initialized.");

    pinMode(DistanceSensorAShut, OUTPUT);
    digitalWrite(DistanceSensorAShut, LOW);
    pinMode(DistanceSensorBShut, OUTPUT);
    digitalWrite(DistanceSensorBShut, LOW);
    delay(10); // give them some time to go down
    DebugPrint("Both distance Sensors are disabled now...");

    DebugPrint("Booting sensor A...");
    digitalWrite(DistanceSensorAShut, HIGH);
    delay(10);
    DebugPrint("Sensor A should be up now.");
    if (!DistanceSensorA.begin()) {
        DebugPrint("Failed to boot VL53L0X (Sensor A)");
        while (1);
    }

    DebugPrint("Sensor A is responsive. Updating its I2C address...");

    DistanceSensorA.setAddress(DISTANCE_SENSOR_A_ADDRESS);
    DebugPrint("Address updated.");

    // Sensor B
    DebugPrint("Booting sensor B...");
    digitalWrite(DistanceSensorBShut, HIGH);
    delay(10);
    DebugPrint("Sensor B should be up now.");
    if (!DistanceSensorB.begin()) {
        DebugPrint("Failed to boot VL53L0X (Sensor B)");
        while (1);
    }

    DebugPrint("Sensor B is responsive. Updating its I2C address...");

    DistanceSensorB.setAddress(DISTANCE_SENSOR_B_ADDRESS);
    DebugPrint("Address updated.");

    DebugPrint("Both VL53L0X Ready now.");
}

// IsTrainDetected returns true whenever a train is detected by our sensor.
bool IsTrainDetected() {
    auto distanceA = DistanceSensorA.readRange();
    auto distanceB = DistanceSensorB.readRange();

    char buffer[32];
    std::sprintf(buffer, "DistanceA: %d mm", distanceA);
    DebugPrint(buffer);

    std::sprintf(buffer, "DistanceB: %d mm", distanceB);
    DebugPrint(buffer);

    return distanceA <= TrainDetectionThreshold || distanceB <= TrainDetectionThreshold;
}

// ShouldResumeTrain returns true when a reobot finishes its job.
// It is designed to be able to occupy the main thread till true. If false returned this will be recalled till true.
bool ShouldResumeTrain() {
    delay(5000);
    return true;
}

#endif
