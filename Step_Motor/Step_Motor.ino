//definicion de pins
const int motorPin1 = 2;   // 28BYJ48 In1
const int motorPin2 = 4;   // 28BYJ48 In2
const int motorPin3 = 5;   // 28BYJ48 In3
const int motorPin4 = 18;  // 28BYJ48 In4

const int sensorPin = 19;
const int ledPin = 13;

int bright = 255;

//definicion variables  
int motorSpeed = 1200;   //variable para fijar la velocidad
int stepCounter = 0;     // contador para los pasos
int stepsPerRev = 4076;  // pasos para una vuelta completa

//secuencia media fase
const int numSteps = 8;
const int stepsLookup[8] = { B1000, B1100, B0100, B0110, B0010, B0011, B0001, B1001 };

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
}

void loop() {
  if (digitalRead(sensorPin) != 1) {
    if(bright < 255) bright++;
    for (int i = 0; i < stepsPerRev * 2; i++) {
      clockwise();
      delayMicroseconds(motorSpeed);
    }
    digitalWrite(ledPin, bright);
  } else {
    if(bright > 0) bright--;
    for (int i = 0; i < stepsPerRev * 2; i++) {
      anticlockwise();
      delayMicroseconds(motorSpeed);
    }
    digitalWrite(ledPin, bright);
  }

  delay(100);
}

void clockwise() {
  stepCounter++;
  if (stepCounter >= numSteps) stepCounter = 0;
  setOutput(stepCounter);
}

void anticlockwise() {
  stepCounter--;
  if (stepCounter < 0) stepCounter = numSteps - 1;
  setOutput(stepCounter);
}

void setOutput(int step) {
  digitalWrite(motorPin1, bitRead(stepsLookup[step], 0));
  digitalWrite(motorPin2, bitRead(stepsLookup[step], 1));
  digitalWrite(motorPin3, bitRead(stepsLookup[step], 2));
  digitalWrite(motorPin4, bitRead(stepsLookup[step], 3));
}