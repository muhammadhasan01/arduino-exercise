const int k_numLEDs = 4;
const int kPinLeds[k_numLEDs] = {2, 3, 5, 7};

void setup() {
  for (int i = 0; i < k_numLEDs; i++) {
    pinMode(kPinLeds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < k_numLEDs; i += 2) {
    int id = (i % k_numLEDs);
    digitalWrite(kPinLeds[id], HIGH);
    delay(500);
    digitalWrite(kPinLeds[id], LOW);
    delay(500);
  }
}
