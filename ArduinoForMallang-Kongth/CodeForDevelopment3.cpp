//���߿� �ڵ� 
void setup() { // setup�ȿ� �ڵ�� ó�� �ѹ��� �����
	Serial.begin(9600);
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
	for (int i = 50; i > 20; i--) {
		Serial.print("g00");
		Serial.print(i);
		delay(500); //0.5�� ���� 
	}
}