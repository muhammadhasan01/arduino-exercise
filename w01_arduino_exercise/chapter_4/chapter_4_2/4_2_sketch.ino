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

const int k_Pinbutton_1 = 2;
const int k_Pinbutton_2 = 3;

void setup() { 
  pinMode(k_Pinbutton_1, INPUT);
  pinMode(k_Pinbutton_2, INPUT);
  pinMode(pinSpeaker, OUTPUT);
}

void loop() {
  int value = 1000;
  if (digitalRead(k_Pinbutton_1) == LOW) {
    value -= 500;
  }
  if (digitalRead(k_Pinbutton_2) == LOW) {
    value -= 400;
  }
  for (int i = 0; i < 6; i++) {
    tone(HAPPY_BIRTHDAY[i][0] % value, value, HAPPY_BIRTHDAY[0][1]);
    delay(400);
  }
  delay(2000);
}