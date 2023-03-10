#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN 4      // El pin digital donde se conecta el sensor
#define DHTTYPE    DHT11     // Tipo de sensor DHT utilizado

// Inicializar el objeto del sensor DHT
DHT_Unified dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  while (!Serial) delay(10);

  // Inicializar el sensor DHT
  dht.begin();
}

void loop() {
  // Obtener los valores de temperatura y humedad del sensor DHT
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  float temp = event.temperature;
  dht.humidity().getEvent(&event);
  float hum = event.relative_humidity;

  // Imprimir los valores de temperatura y humedad en el monitor serie
  Serial.print("Temperatura: ");
  Serial.print(temp);
  Serial.print(" °C");
  Serial.print("\tHumedad: ");
  Serial.print(hum);
  Serial.println(" %");

  delay(2000); // Esperar 2 segundos antes de tomar otra lectura
}
