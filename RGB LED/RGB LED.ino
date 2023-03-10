// Definir los pines para cada color del LED RGB
#define RED_PIN   23
#define GREEN_PIN 22
#define BLUE_PIN  21

void setup() {
  // Configurar los pines del LED RGB como salida
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Inicializar los pines del LED RGB en un estado apagado
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
}

void loop() {
  // Encender el LED de color rojo durante 2 segundos
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);
  delay(2000);

  // Encender el LED de color verde durante 2 segundos
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  delay(2000);

  // Encender el LED de color azul durante 2 segundos
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, HIGH);
  delay(2000);

  // Encender el LED de color blanco durante 2 segundos
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, HIGH);
  delay(2000);
}
