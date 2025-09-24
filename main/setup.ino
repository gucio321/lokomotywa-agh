#ifndef SETUP
#define SETUP

enum engine {
  EngineA,
  EngineB
};

// GPIO setup
const int EngineAIn1 = 13; //D13
const int EngineAIn2 = 12; //D12
const int EngineASpeedPin = 26; //D26

const int EngineBIn1 = 14; //D14
const int EngineBIn2 = 27; //D27 niespodzianka, są w tej samej lini
const int EngineBSpeedPin = 25; //D25

const int** enginesPins = new const int*[2]{
  new const int[3]{EngineAIn1, EngineAIn2, EngineASpeedPin}, // EngineA pins
  new const int[3]{EngineBIn1, EngineBIn2, EngineBSpeedPin}, // EngineB pins
};

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
  Serial.begin(9600);
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
