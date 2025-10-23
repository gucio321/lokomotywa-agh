#ifndef INPUTINO
#define INPUTINO
#include "Arduino.h"
#include "utils.ino"
#include <Adafruit_VL53L0X.h>
#include <Wire.h>
#include <iostream>

Adafruit_VL53L0X DistanceSensor[NUM_STATIONS];
bool previous[NUM_STATIONS];

void SetupInput() {
    for (int i = 0; i < NUM_STATIONS; i++) {
        previous[i] = false;
    }

    DebugPrint("Initializing I2C distance sensors...");
    if (!Wire.begin(DistanceSensorSDA, DistanceSensorSCL)) {
        DebugPrint("Failed initialize I2C on specified ports (ESP will be trapped here)!");
        while (1);
    }

    Wire.setClock(400);

    DebugPrint("I2C initialized.");

    /*
    for (int i = 0; i < NUM_STATIONS; i++) {
        DistanceSensor[i] = Adafruit_VL53L0X();
    }
    */

    for (int i = 0; i < NUM_STATIONS; i++) {
        pinMode(DistanceSensorShut[i], OUTPUT);
        digitalWrite(DistanceSensorShut[i], LOW);
    }

    delay(50); // give them some time to go down
    
    DebugPrint("All the distance Sensors are disabled now.");

    for (int i = 0; i < NUM_STATIONS; i++) {
        char buffer[32];
        std::sprintf(buffer, "Booting sensor %d...", i);
        DebugPrint(buffer);

        digitalWrite(DistanceSensorShut[i], HIGH);
        delay(500);
        DebugPrint("The Sensor should be up now.");

        if (!DistanceSensor[i].begin(DISTANCE_SENSOR_ADDRESS[i])) {
            DebugPrint("Failed to boot VL53L0X");
            while (1);
        }

        //DebugPrint("Sensor is responsive. Updating its I2C address...");

        //DistanceSensor[i].setAddress(DISTANCE_SENSOR_ADDRESS[i]);
        //DebugPrint("Address updated.");
    }

    DebugPrint("Both VL53L0X Ready now.");
}

// IsTrainDetected returns true whenever a train is detected by our sensor.
// This also saves last result and returns true ONLY, when the state changed.
bool IsTrainDetected() {
    int distance[NUM_STATIONS];
    bool result = false;
    VL53L0X_RangingMeasurementData_t measure;
    for (int i = 0; i < NUM_STATIONS; i++) {
        char buffer[32];
        char state;
        state = DistanceSensor[i].rangingTest(&measure, true)
        if(!state){
          std::sprintf(buffer, "ERROR DETECTED: %d", state);
          DebugPrint(state);
          digitalWrite(DistanceSensorShut[i],LOW);
          delay(50);
          digitalWrite(DistanceSensorShut[i],HIGH);
        }
        //distance[i] = DistanceSensor[i].readRange();
        distance[i] = measure.RangeMilliMeter;

        std::sprintf(buffer, "Distance%d: %d mm", i, distance[i]);
        DebugPrint(buffer);
        bool detection = (distance[i] <= TrainDetectionThreshold) && distance[i];
        result |= detection && !previous[i];
        previous[i] = detection;
    }

    return result;
}

// ShouldResumeTrain returns true when a reobot finishes its job.
// It is designed to be able to occupy the main thread till true. If false returned this will be recalled till true.
bool ShouldResumeTrain() {
    delay(5000);
    return true;
}

#endif
