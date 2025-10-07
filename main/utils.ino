#ifndef UTILS
#define UTILS
#include "Arduino.h"
#define DEBUG

void DebugPrint(const char* message) {
#ifdef DEBUG
    Serial.println(message);
    Serial.print("\n");
#endif
}


#endif //UTILS
