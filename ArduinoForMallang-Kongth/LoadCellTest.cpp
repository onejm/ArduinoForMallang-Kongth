#include "HX711.h"
#define calibration_factor 527.5 //Ķ���극�̼� ��
#define DOUT  3 //������ ��
#define CLK  2 // Ŭ�� ��
int value;
HX711 scale(DOUT, CLK);
void setup() {
    Serial.begin(9600);  // �� ����͸� ���ؼ�...
    scale.set_scale(calibration_factor);
    scale.tare(); //�������. ���� �������� 0���� �д�.
}
void loop() {
    value = (int)scale.get_units();
    if (value <= 2) {
        Serial.println("0000");
    }
    else if (value > 2 && value <= 9) {
        Serial.print("000");
        Serial.println(value);
    }
    else if (value > 9 && value <= 99) {
        Serial.print("00");
        Serial.println(value);
    }
    else if (value > 99 && value <= 999) {
        Serial.print("0");
        Serial.println(value);
    }
    else {
        Serial.println(value);
    }
}