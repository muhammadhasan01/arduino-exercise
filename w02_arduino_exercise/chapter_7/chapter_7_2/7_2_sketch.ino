int tilt = 2; // the number of the input pin
int speaker = 13; // the number of the output pin

void setup() {
  pinMode(tilt, INPUT);
  pinMode(speaker, OUTPUT);
}

void loop() {
  int reading;
  reading = digitalRead(tilt);

  if (reading)
    playTone(0, 0);
  else
    playTone(300, 300);
}

// duration in mSecs, frequency in hertz
void playTone(long duration, int freq) {
  duration *= 1000;
  int period = (1.0 / freq) * 100000;
  long elapsed_time = 0;
  while (elapsed_time < duration) {
    digitalWrite(13, HIGH);
    digitalWrite(speaker, HIGH);
    delayMicroseconds(period / 2);
    digitalWrite(13, LOW);
    digitalWrite(speaker, LOW);
    delayMicroseconds(period / 2);
    elapsed_time += (period);
  }
}