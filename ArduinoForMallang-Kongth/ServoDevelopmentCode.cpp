//���߿� �ڵ� 
#include <Servo.h>
Servo servo;
int servoVal = 0;
void setup() { // setup�ȿ� �ڵ�� ó�� �ѹ��� �����
	Serial.begin(9600);
	servo.attach(7);
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
	for (int i = 50; i > 20; i--) {
		Serial.print("h00");
		Serial.print(i);
		if (Serial.available()) { //�ø��� �����Ͱ� �Էµ�
			int in_data = Serial.read();
			if (in_data == 1) {
				servoVal += 90;
				servo.write(servoVal);
			}
		}
		delay(500); //0.5�� ���� 
	}
}