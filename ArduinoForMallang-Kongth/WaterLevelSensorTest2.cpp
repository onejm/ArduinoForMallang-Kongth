void setup() {
	Serial.begin(9600); //�ø��� ����͸� �����մϴ�.
}

void loop() {
	int level = analogRead(A0);  // ���м����� ��ȣ�� �����մϴ�.
	level = level - 25;
	if (level < 0) {
		Serial.println(0);
	}
	else {
		Serial.println(level);
	}
}