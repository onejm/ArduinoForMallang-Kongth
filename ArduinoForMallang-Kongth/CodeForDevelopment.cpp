//개발용 코드 
void setup() { // setup안에 코드는 처음 한번만 실행됨
	Serial.begin(9600);
}

void loop() { // loop안에 코드가 아두이노가 무한 반복으로 실행됨
	Serial.print("w1234"); //수위센서 값
	Serial.print("h1234"); //무게센서 값
	delay(500); //0.5초 정지 
}