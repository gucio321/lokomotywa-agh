const int in1=13;
const int in2=12;
const int in3=11;
const int in4=10;
const int speedPinA=6;
const int speedPinB=5;

void setup()
{
  Serial.begin(9600);
  Serial.print("Lokomotywa AGH - Setup");

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
}

void loop()
{
  _mRight(in1,in2);
  _mRight(in3,in4);
  int n=analogRead(A0)/4;
  _mSetSpeed(speedPinA,n);
  _mSetSpeed(speedPinB,n);
}

void _mRight(int pin1,int pin2)
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,LOW);
}

void _mLeft(int pin1,int pin2)
{
  digitalWrite(pin1,LOW);
  digitalWrite(pin2,HIGH);
}

void _mStop(int pin1,int pin2)
{
  digitalWrite(pin1,HIGH);
  digitalWrite(pin2,HIGH);
}

void _mSetSpeed(int pinPWM,int SpeedValue)
{
  analogWrite(pinPWM,SpeedValue);
}
