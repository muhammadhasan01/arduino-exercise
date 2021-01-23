const int GAS_BUTTON = 2;
const int BRAKE_BUTTON = 3;
const int LED = 9;

void setup() {
	pinMode(GAS_BUTTON, INPUT);
	pinMode(BRAKE_BUTTON, INPUT);
	pinMode(LED, OUTPUT);
	digitalWrite(GAS_BUTTON, HIGH);
	digitalWrite(BRAKE_BUTTON, HIGH);
	digitalWrite(LED, LOW);
}

int delayTime = 500;

void loop() {
	if (digitalRead(GAS_BUTTON) == LOW && delayTime > 100) {
		delayTime -= 100;
	} else if (digitalRead(BRAKE_BUTTON) == LOW && delayTime < 1000) {
		delayTime += 100;
	}
	digitalWrite(LED, HIGH);
	delay(delayTime);
	digitalWrite(LED, LOW);
	delay(delayTime);
}
