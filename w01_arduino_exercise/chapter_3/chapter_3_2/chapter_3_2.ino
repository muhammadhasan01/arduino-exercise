const int kButtonFrom = 2;
const int kButtonTo = 3;
const int kPinLed_R = 9;
const int kPinLed_G = 8;
const int kPinLed_B = 7;

void setup() {
  pinMode(kButtonFrom, INPUT);
  pinMode(kButtonTo, INPUT);
    pinMode(kPinLed_R, OUTPUT);
    pinMode(kPinLed_G, OUTPUT);
    pinMode(kPinLed_B, OUTPUT);
}

int curValue = 0;

void loop() {
  curValue = (curValue + 1) % 255;
  analogWrite(kPinLed_R, curValue);
  analogWrite(kPinLed_G, curValue);
  analogWrite(kPinLed_B, curValue);
}
