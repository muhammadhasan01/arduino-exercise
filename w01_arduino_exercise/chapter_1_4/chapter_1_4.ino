const int kLowestLed = 2;
const int kHighestLed = 8;

void setup() {
  for (int i = kLowestLed; i <= kHighestLed; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // Turn ON and OFF for each LED in order
  for (int i = kLowestLed; i <= kHighestLed; i++) {
    digitalWrite(i, HIGH);
    delay(100);
    digitalWrite(i, LOW);
  }
}
