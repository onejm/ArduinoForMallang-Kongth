void setup() {
	Serial.begin(9600); //시리얼 모니터를 시작합니다.
}

void loop() {
	int level = analogRead(A0);  // 수분센서의 신호를 측정합니다.
	level = level - 25;
	if (level < 0) {
		Serial.println(0);
	}
	else {
		Serial.println(level);
	}
}