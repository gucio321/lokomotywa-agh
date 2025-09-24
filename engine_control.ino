#ifndef ENGINE_CONTROL // pragma once
#define ENGINE_CONTROL

#include "setup.ino"

enum engine {
  EngineA,
  EngineB
};

enum direction {
  Stop,
  Left,
  Right
}

int[3] getPinSet(enum engine e) {
  switch(e) {
    case EngineA:
      return [EngineAIn1, EngineAIn2, EngineASpeedPin];
    case EngineB:
      return [EngineBIn1, EngineBIn2, EngineBSpeedPin];
  }
}

void setRotation(enum engine e, enum direction d) {
  auto pins = getPinSet(e);
  switch(direction) {
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
  auto pins = getPinSet(e);
  analogWrite(pins[2],SpeedValue);
}

#endif
