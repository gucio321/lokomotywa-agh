#ifndef INPUTINO
#define INPUTINO
#include "Arduino.h"

// IsTrainDetected returns true whenever a train is detected by our sensor.
bool IsTrainDetected() {
    // pseudo-random value generator xD
    return millis() % 2 == 0; // TODO
}

// ShouldResumeTrain returns true when a reobot finishes its job.
// It is designed to be able to occupy the main thread till true. If false returned this will be recalled till true.
bool ShouldResumeTrain() {
    delay(2);
    return true;
}

#endif