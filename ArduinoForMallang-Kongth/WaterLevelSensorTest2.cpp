void setup() {
	Serial.begin(9600); //�ø��� ����͸� �����մϴ�.
}

void loop() {
	int level = analogRead(A0);  // ���м����� ��ȣ�� �����մϴ�.
	Serial.println(level);   //�ø��� ����Ϳ� ���� ����մϴ�.
}