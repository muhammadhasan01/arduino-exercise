const int NOTE_C4 = 262;
const int NOTE_D4 = 294;
const int NOTE_E4 = 330;
const int NOTE_F4 = 349;
const int NOTE_G4 = 392;
const int NOTE_A4 = 440;
const int NOTE_B4 = 494;
const int NOTE_C5 = 523;
const int pinSpeaker = 10;

const int HAPPY_BIRTHDAY[6][2] = {
  {NOTE_C4, 1000},
  {NOTE_C4, 1000},
  {NOTE_D4, 2000},
  {NOTE_C4, 2000},
  {NOTE_F4, 2000},
  {NOTE_E4, 4000},
};

void setup() { 
  pinMode(pinSpeaker, OUTPUT);
}

void loop() {
  for (int i = 0; i < 6; i++) {
    ourTone(HAPPY_BIRTHDAY[i][0], HAPPY_BIRTHDAY[i][1]);
    delay(400);
  }
  delay(2000);
}

void ourTone(int freq, int duration) {
    digitalWrite(pinSpeaker, freq);
    delay(duration);
}