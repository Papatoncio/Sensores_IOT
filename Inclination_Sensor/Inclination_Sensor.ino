int sensorPin = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = digitalRead(sensorPin);  // Lee el valor del sensor
  if (sensorValue == LOW) {              // Verifica si el sensor está inclinado
    Serial.println("El sensor está inclinado");   // Imprime un mensaje indicando que el sensor está inclinado
  } else {
    Serial.println("El sensor está en posición horizontal");  // Imprime un mensaje indicando que el sensor está en posición horizontal
  }
  delay(500);
}