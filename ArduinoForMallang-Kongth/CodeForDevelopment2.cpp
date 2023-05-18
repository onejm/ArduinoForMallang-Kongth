//개발용 코드 
void setup() { // setup안에 코드는 처음 한번만 실행됨
	Serial.begin(9600);
}

void loop() { // loop안에 코드가 아두이노가 무한 반복으로 실행됨
	for (int i = 50; i > 20; i--) {
		Serial.print("w00");
		Serial.print(i);
		delay(500); //0.5초 정지 
	}

	for (int i = 30; i > 10; i--) {
		Serial.print("w00");
		Serial.print(i);
		delay(500); //0.5초 정지 
	}
}