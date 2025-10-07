#ifndef ENGINE_CONTROL // pragma once
#define ENGINE_CONTROL

#include "setup.ino"

class Engine {
public:
  Engine(int input1, int input2, int speedPin):
  Engine(new int[3]{input1, input2, speedPin}) {}

  Engine(int* p) {
    pinout = new int[3];
    pinout[0] = p[0];
    pinout[1] = p[1];
    pinout[2] = p[2];
    setSpeed(0);
  }

  void Rotate(direction d) {
    switch(d) {
      case Stop:
        digitalWrite(pinout[0], HIGH);
        digitalWrite(pinout[1], HIGH);
        break;
      case Left:
        digitalWrite(pinout[0], LOW);
        digitalWrite(pinout[1], HIGH);
        break;
      case Right:
        digitalWrite(pinout[0], HIGH);
        digitalWrite(pinout[1], LOW);
        break;
    }
  }

  void setSpeed(int s)
  {
    if (s < 0) {
      s = 0;
    } else if (s > SPEED_CAP) {
        s = SPEED_CAP;
    }

    analogWrite(pinout[2],s);
    speed = s;
  }
  int getSpeed() {
    return speed;
  }
private:
  int speed;
  int* pinout;
};

Engine EngineA = Engine(EngineAIn1, EngineAIn2, EngineASpeedPin);
Engine EngineB = Engine(EngineBIn1, EngineBIn2, EngineBSpeedPin);

#endif
