//���߿� �ڵ� 
#include <Servo.h>
Servo servo;
int angle = 90;
void setup() { // setup�ȿ� �ڵ�� ó�� �ѹ��� �����
    Serial.begin(9600);
    servo.attach(9);
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
    for (int i = 40; i > 20; i--) {
        Serial.print("h00");
        Serial.print(i);
        if (Serial.available() > 0) {  // �ø��� ���ۿ� �����Ͱ� �ִ��� Ȯ��
            int input = Serial.parseInt();  // �Էµ� ���� ���� �о��

            if (input == 1) {  // �Է� ���� 1�� ���
                angle = 180;  // ���� ���� ������ 90���� ����
                servo.write(angle);  // ���� ���͸� ������ ������ ������
                delay(500);  // 0.5�� ���
            }
            if (input == 2) {  // �Է� ���� 1�� ���
                angle = 0;  // ���� ���� ������ 90���� ����
                servo.write(angle);  // ���� ���͸� ������ ������ ������
                delay(500);  // 0.5�� ���
            }
        }
    }
    delay(500); //0.5�� ���� 
}