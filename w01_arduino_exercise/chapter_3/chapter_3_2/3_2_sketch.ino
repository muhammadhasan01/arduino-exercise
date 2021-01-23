const int kPinPot = A0;
const int kButton = 2;
const int kPinLed = 9;

void setup() {
  pinMode(kPinPot, INPUT);
  pinMode(kButton, INPUT);
  pinMode(kPinLed, OUTPUT);
}

int delayTime = 500;
bool pressed = false;

void loop() {
    if (analogRead(kButton) == LOW) {
        pressed = true;
    }
    if (pressed) {
        delayTime = map(analogRead(kPinPot), 0, 1023, 0, 3000);
    }
    analogWrite(kPinLed, HIGH);
    delay(delayTime);
    analogWrite(kPinLed, LOW);
    delay(delayTime);
}
