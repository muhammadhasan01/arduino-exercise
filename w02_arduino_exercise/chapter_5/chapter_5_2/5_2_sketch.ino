#include <LiquidCrystal.h>

// Connections:
// rs (LCD pin 4) to Arduino pin 12
// rw (LCD pin 5) to Arduino pin 11
// enable (LCD pin 6) to Arduino pin 10
// LCD pin 15 to Arduino pin 13
// LCD pins d4, d5, d6, d7 to Arduino pins 5, 4, 3, 2
LiquidCrystal lcd(12, 11, 10, 5, 4, 3, 2);

int backLight = 13; // pin 13 will control the backlight
char degree = 176; // ASCI value of Degree

void setup() {
  pinMode(backLight, OUTPUT);
  pinMode(A0, INPUT);
  digitalWrite(backLight, HIGH); // turn backlight on. Replace 'HIGH' with 'LOW' to turn it off.
  lcd.begin(16, 2); // columns, rows.  use 16,2 for a 16x2 LCD, etc.
  lcd.clear(); // start with a blank screen
  Serial.begin(9600);
}

const float INF = 1e5;
float maks = -INF;
float mini = INF;

void loop() {
  delay(250);
  // Turn off the display:
  lcd.noDisplay();
  delay(250);
  // Turn on the display:
  lcd.display();
  float valor_sensor = analogRead(A0);
  lcd.setCursor(0, 0);
  float cel = value_to_celcius(valor_sensor);
  float far = celcius_to_farenheit(cel);
  if (far > maks) maks = far;
  if (far < mini) mini = far;
  lcd.print("Temp:");
  lcd.print(far);
  lcd.print("F");
  lcd.setCursor(0, 1);
  // prints the minimum and maximum
  lcd.print(mini); lcd.print("-");
  lcd.print(maks);
  delay(10000);
}

float value_to_celcius(float val) {
  float voltage = (val * 5.0) / 1024;
  float mili_volt = (voltage) * 1000;
  float celcius = (mili_volt - 500) / 10;
  return celcius;
}

float celcius_to_farenheit(float cel) {
  return (cel * 1.8) + 32;
}