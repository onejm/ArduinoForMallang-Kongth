//���߿� �ڵ� 
#include <Servo.h>
#include "HX711.h"
#define calibration_factor 527.5 //Ķ���극�̼� ��
#define DOUT  4 //������ ��
#define CLK  3 // Ŭ�� ��
Servo servo;
HX711 scale(DOUT, CLK);
int value;
int value2;
int input = 0;
int angle = 90;
void setup() { // setup�ȿ� �ڵ�� ó�� �ѹ��� �����
    Serial.begin(9600);
    servo.attach(9);
    scale.set_scale(calibration_factor);
    scale.tare(); //�������. ���� �������� 0���� �д�.
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
    value = (int)scale.get_units();
    if (value <= 2) {
        Serial.print("h");
        Serial.print("0000");
    }
    else if (value > 2 && value <= 9) {
        Serial.print("h");
        Serial.print("000");
        Serial.print(value);
    }
    else if (value > 9 && value <= 99) {
        Serial.print("h");
        Serial.print("00");
        Serial.print(value);
    }
    else if (value > 99 && value <= 999) {
        Serial.print("h");
        Serial.print("0");
        Serial.print(value);
    }
    else {
        Serial.print("h");
        Serial.print(value);
    }
    if (Serial.available() > 0 && input == 0) {  // �ø��� ���ۿ� �����Ͱ� �ִ��� Ȯ��
        input = Serial.parseInt();  // �Էµ� ���� ���� �о��
        value2 = value;
    }
    if (input > value - value2 && input != 0) {
        servo.write(180);  // ���� ���͸� ������ ������ ������
    }
    else if (input < value - value2 && input != 0) {
        servo.write(90);
        input = 0;
    }
}