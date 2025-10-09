#ifndef SETUP
#define SETUP
#include "Arduino.h"

const int TrainDetectionThreshold = 70; // mm
const int SPEED_CHANGE_FACTOR = 10;
const int SPEED_CAP = 150; // [0-255]

const int NUM_STATIONS = 4; // Number of Distance sensors to be proceeded.
const int DISTANCE_SENSOR_ADDRESS[] = {0x30, 0x31, 0x32, 0x33, 0x34, 0x35};

// GPIO setup
const int EngineAIn1 = 13; //D13
const int EngineAIn2 = 12; //D12
const int EngineASpeedPin = 26; //D26

const int EngineBIn1 = 14; //D14
const int EngineBIn2 = 27; //D27 niespodzianka, są w tej samej lini
const int EngineBSpeedPin = 25; //D25
                                //
const int DistanceSensorSDA = 33; // D33
const int DistanceSensorSCL = 32; // D32
const int DistanceSensorShut[] = {15,2,4,16,5,17}; // TODO

enum direction {
  Stop,
  Left,
  Right
};

// state is set to control engine speed
enum state {
  Starting,
  Running,
  Stopping,
  Idle
};

enum state engineAState = Idle;
enum state engineBState = Idle;

void setup_serial() {
  // set up serial.
  Serial.begin(115200);
  Serial.print("Lokomotywa AGH - Setup\n");
}

void setup_pins() {
  pinMode(EngineAIn1,OUTPUT);
  pinMode(EngineAIn2,OUTPUT);

  pinMode(EngineBIn1,OUTPUT);
  pinMode(EngineBIn2,OUTPUT);

  digitalWrite(EngineAIn1,HIGH);
  digitalWrite(EngineAIn2,HIGH);

  digitalWrite(EngineBIn1,HIGH);
  digitalWrite(EngineBIn2,HIGH);
}

#endif //SETUP
