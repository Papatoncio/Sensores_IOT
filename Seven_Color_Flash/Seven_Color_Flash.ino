int pin = 2;

void setup() {
  Serial.begin(9600);
  pinMode(pin, OUTPUT);
}
void loop() {
  digitalWrite(pin, HIGH);
  delay (10000);
  digitalWrite(pin, LOW);
  delay (2000);
}