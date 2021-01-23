const int kPinLed = 2;

void setup() {
  pinMode(kPinLed, OUTPUT);
}

void loop() {
  digitalWrite(kPinLed, HIGH);
  delay(1000);
  digitalWrite(kPinLed, LOW);
  delay(1000);
}
