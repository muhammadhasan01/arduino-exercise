/* ------------------------------------------------------------------------------- */
// character LCD example code
// www.hacktronics.com

#include <LiquidCrystal.h>

// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int pushButton = 7;
int backLight = 13; // pin 13 will control the backlight

void setup() {
  pinMode(backLight, OUTPUT);
  pinMode(pushButton, INPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16, 2); // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear(); // start with a blank screen
  // inicializa la comunicación serial en 9600 bits por segundo
  Serial.begin(9600);
}

int numPush = 0;
int timePush = 0;

void loop() {

  if (numPush == 0) {
    lcd.setCursor(0, 0); // set cursor to column 0, row 0 (the first row)
    lcd.print("push button"); // change text to whatever you like. keep it clean!
    lcd.setCursor(0, 1); // set cursor to column 0, row 1
    lcd.print("to start :D");
  } else if (numPush > 0) {
    lcd.setCursor(0, 0);
    lcd.print("Time:");
    lcd.setCursor(0, 1);
    int value = millis() - timePush;
    lcd.print(value);
    lcd.print("s");
  }

  int buttonState = digitalRead(pushButton);
  Serial.println(buttonState);
  Serial.println(numPush);

  if (buttonState == LOW) {
    numPush++;
    if (numPush == 1) {
      lcd.clear();
      timePush = millis();
    }
  }

  delay(1);
}