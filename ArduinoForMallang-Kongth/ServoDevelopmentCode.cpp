//개발용 코드 
#include <Servo.h>
Servo servo;
int servoVal = 0;
void setup() { // setup안에 코드는 처음 한번만 실행됨
	Serial.begin(9600);
	servo.attach(7);
}

void loop() { // loop안에 코드가 아두이노가 무한 반복으로 실행됨
	for (int i = 50; i > 20; i--) {
		Serial.print("h00");
		Serial.print(i);
		if (Serial.available()) { //시리얼에 데이터가 입력됨
			int in_data = Serial.read();
			if (in_data == 1) {
				servoVal += 90;
				servo.write(servoVal);
			}
		}
		delay(500); //0.5초 정지 
	}
}