// Incluimos la biblioteca del ESP32
#include <Arduino.h>

// Definimos el pin GPIO al que está conectado el módulo mini reed
#define REED_PIN 25

void setup() {
  // Inicializamos el puerto serie a una velocidad de 9600 baudios
  Serial.begin(9600);

  // Configuramos el pin GPIO como entrada
  pinMode(REED_PIN, INPUT_PULLUP);
}

void loop() {
  // Leemos el valor del pin GPIO
  int reedValue = digitalRead(REED_PIN);

  // Si el valor es 0, significa que el imán está cerca del sensor
  if (reedValue == 0) {
    Serial.println("¡Se detectó un campo magnético!");
  }

  // Esperamos un breve periodo de tiempo para evitar lecturas innecesarias
  delay(100);
}
