#ifndef ENGINE_CONTROL // pragma once
#define ENGINE_CONTROL

#include "setup.ino"

void setRotation(enum engine e, enum direction d) {
  auto pins = enginesPins[e];
  switch(d) {
    case Stop:
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], HIGH);
      break;
    case Left:
      digitalWrite(pins[0], LOW);
      digitalWrite(pins[1], HIGH);
      break;
    case Right:
      digitalWrite(pins[0], HIGH);
      digitalWrite(pins[1], LOW);
      break;
  }
}

void setSpeed(enum engine e,int SpeedValue)
{
  auto pins = enginesPins[e];
  analogWrite(pins[2],SpeedValue);
}

#endif
