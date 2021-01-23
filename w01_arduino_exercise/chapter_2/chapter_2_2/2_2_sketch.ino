const int kPinLed = 13;

void setup() {
  pinMode(kPinLed, OUTPUT);
}

void loop() {
  for (int i = 1; i <= 10; i++) {
    digitalWrite(kPinLed, HIGH);
    delay((i <= 5 ? 1000 : 500));
    digitalWrite(kPinLed, LOW);
    delay((i <= 5 ? 1000 : 500));
  }
}
