//���߿� �ڵ� 
#include <Servo.h>
Servo servo;
int servoVal = 0;
void setup() { // setup�ȿ� �ڵ�� ó�� �ѹ��� �����
	Serial.begin(9600);
	servo.attach(7);
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
	if (Serial.available()) { //�ø��� �����Ͱ� �Էµ�
		int in_data = Serial.read();
		if (in_data == 1) {
			servoVal += 90;
			servo.write(servoVal);
		}
	}
	Serial.print("h00");
	Serial.print(12);
	delay(500);
}