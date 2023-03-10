#include <TM1651.h>

int sensorPin = 4;
int sensorValue = 0;

#define CLK 14
#define DIO 5

TM1651 batteryDisplay(CLK, DIO);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  batteryDisplay.init();
  batteryDisplay.set(1);
  batteryDisplay.frame(FRAME_ON);
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = digitalRead(sensorPin);

  if(sensorValue == LOW){
    Serial.println("Inclinado");
    charging();
  }else{
    Serial.println("No Inclinado");
    batteryDisplay.displayLevel(0);
  }

  delay(500);
}

void charging() {
  for (uint8_t level = 0; level < 6; level++) {
    batteryDisplay.displayLevel(level);
    delay(500);
  }
}
