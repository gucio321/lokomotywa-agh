// Inicjalizacja wyjść GPIO
const int in1=13; //D13
const int in2=12; //D12
const int in3=14; //D14
const int in4=27; //D27 niespodzianka, są w tej samej lini
const int speedPinA=26; //DS26
const int speedPinB=25; //DS27

// Przygotowanie do pracy
void setup()
{
  Serial.begin(9600);
  Serial.print("Lokomotywa AGH - Setup\n");

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
}

// Pętla główna
void loop()
{
  if (Serial.available()){
    Serial.print("Begin frame\n");
  }
  _mRight(in1,in2);
  _mRight(in3,in4);

  int n=1;
  _mSetSpeed(speedPinA,n);
  _mSetSpeed(speedPinB,n);
}

// Obraca silniczek w prawo poprzez zmienienie napięcia na 1. wejściu na HIGH i w 2. na LOW
void _mRight(int pin1,int pin2)
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
}

// Obraca silniczek w lewo poprzez zmienienie napięcia na 1. wejściu na LOW i w 2. na HIGH
void _mLeft(int pin1,int pin2)
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
}

// Zatrzymuje obrót silniczka poprzez ustawienie obu jego wejść na HIGH
void _mStop(int pin1,int pin2)
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
}

// Zakres prędkości [0,255]
void _mSetSpeed(int pinPWM,int SpeedValue)
{
  analogWrite(pinPWM,SpeedValue);
}
