int sensorPin = 2;  
int L298N_pin_1 = 7;
int L298N_pin_2 = 8;

void setup() {
  Serial.begin(9600);  // Iniciamos la comunicación serial
  pinMode(sensorPin, INPUT);
  pinMode(L298N_pin_1, OUTPUT);
  pinMode(L298N_pin_2, OUTPUT);
}

void loop() {
  int sensorValue = digitalRead(sensorPin);

  if (sensorValue == LOW) {
    Serial.print("El sensor esta inclinado");
    Serial.println(sensorValue);
    digitalWrite(L298N_pin_1, HIGH);
    digitalWrite(L298N_pin_2, LOW);
  } else {
    Serial.println("El sensor esta en posicion horizontal");
    digitalWrite(L298N_pin_1, LOW);
  }
  delay(500);  
}