const int k_numLEDs = 7;
const int kPinLeds[k_numLEDs] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  for (int i = 0; i < k_numLEDs; i++) {
    pinMode(kPinLeds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < 2 * k_numLEDs; i++) {
    int id = (i < k_numLEDs ? i : 2 * k_numLEDs - i - 1);
    digitalWrite(kPinLeds[id], HIGH);
    delay(500);
    digitalWrite(kPinLeds[id], LOW);
    delay(500);
  }
}
