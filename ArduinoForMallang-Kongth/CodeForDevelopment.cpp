//���߿� �ڵ� 
void setup() { // setup�ȿ� �ڵ�� ó�� �ѹ��� �����
	Serial.begin(9600);
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
	Serial.print("w1234"); //�������� ��
	Serial.print("h1234"); //���Լ��� ��
	delay(500); //0.5�� ���� 
}