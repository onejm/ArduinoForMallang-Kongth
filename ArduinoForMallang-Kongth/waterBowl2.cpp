#include "HX711.h"
#define calibration_factor 574.3 //Ķ���극�̼� ��
#define DOUT  3 //������ ��
#define CLK  2 // Ŭ�� ��
#define PUMP 4 // ���� ��


const char* ssid = "U+Net4C9B";
const char* password = "0111035731";
const char* serverIP = "localhost";
const int serverPort = 8080;

int value;
int temp;
HX711 scale(DOUT, CLK);
void setup() {
    Serial.begin(9600);  // �� ����͸� ���ؼ�...
    scale.set_scale(calibration_factor);
    scale.tare(); //�������. ���� �������� 0���� �д�.
    pinMode(PUMP, OUTPUT);
    digitalWrite(PUMP, LOW);
}
void loop() {
    temp = (int)scale.get_units();
    if (temp < 200) {
        value = temp;
    }
    value = (int)scale.get_units();
    if (value < 130) {
        digitalWrite(PUMP, HIGH);
    }
    if (value > 150) {
        digitalWrite(PUMP, LOW);
    }

    if (value <= 2) {
        Serial.print("w");
        Serial.print("0000");
    }
    else if (value > 2 && value <= 9) {
        Serial.print("w");
        Serial.print("000");
        Serial.print(value);
    }
    else if (value > 9 && value <= 99) {
        Serial.print("w");
        Serial.print("00");
        Serial.print(value);
    }
    else if (value > 99 && value <= 999) {
        Serial.print("w");
        Serial.print("0");
        Serial.print(value);
    }
    else {
        Serial.print("w");
        Serial.print(value);
    }
}