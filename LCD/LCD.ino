#include <UTFT.h>

// Configuración de pines de la pantalla
UTFT myGLCD(ST7735S_4L_80160, 11, 13, 10, 8, 9);
const int SENSOR_PIN = A0;

extern uint8_t SmallFont[3];
extern uint8_t BigFont[];

// Variables para el tamaño de la pantalla
int screenWidth = 80;
int screenHeight = 160;

void setup() {
  // Inicialización de la pantalla
  myGLCD.InitLCD();

  // Configuración de la fuente de texto
  myGLCD.setFont(SmallFont);

  // Limpia la pantalla
  myGLCD.clrScr();

  pinMode(SENSOR_PIN, INPUT);
}

void loop() {
  // Valores 
  int valor = analogRead(SENSOR_PIN);

  // Convierte el valor a string
  char val[10];
  dtostrf(valor, 5, 0, val);  // convierte entero a string

  // imprime los valores en la pantalla
  myGLCD.setColor(255, 255, 255);
  myGLCD.print("Juan Pablo", 10, 20);
  myGLCD.print("Valor: ", 10, 10);
  myGLCD.print(val, 70, 10);

  delay(500);
}