#ifndef UTILS
#define UTILS

void DebugPrint(const char* message) {
#ifdef DEBUG
    Serial.println(message);
#endif
}


#endif //UTILS
