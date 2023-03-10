#include <ESP32Servo.h>
#include <analogWrite.h>
#include <ESP32Tone.h>
#include <ESP32PWM.h>

int sensorPin = 14;
Servo servo;
int sensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  servo.attach(5);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  if(sensorValue < 2500){
    Serial.println("Luz Alta");
    servo.write(360);
  }else{
    Serial.println("Luz Baja");
    servo.write(0);
  }
  delay(500);
}
