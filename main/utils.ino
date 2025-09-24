#ifndef UTILS
#define UTILS
#include "Arduino.h"

void DebugPrint(const char* message) {
#ifdef DEBUG
    Serial.println(message);
#endif
}


#endif //UTILS
