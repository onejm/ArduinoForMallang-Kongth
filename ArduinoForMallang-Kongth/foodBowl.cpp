//개발용 코드 
#include <Servo.h>
#include "HX711.h"
#define calibration_factor 533.33//캘리브레이션 값
#define DOUT  4 //데이터 핀
#define CLK  3 // 클럭 핀
Servo servo;
HX711 scale(DOUT, CLK);
int value;
int value2;
int input = 0;
int angle = 90;
int speakerPin = 5;
int numTones = 8;
int tones[] = { 261, 293, 329, 349, 391, 440, 493, 523 };

void setup() { // setup안에 코드는 처음 한번만 실행됨
    Serial.begin(9600);
    servo.attach(2);
    scale.set_scale(calibration_factor);
    scale.tare(); //영점잡기. 현재 측정값을 0으로 둔다.
}

void loop() { // loop안에 코드가 아두이노가 무한 반복으로 실행됨
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
    if (Serial.available() > 0 && input == 0) {  // 시리얼 버퍼에 데이터가 있는지 확인
        input = Serial.parseInt();  // 입력된 정수 값을 읽어옴
        value2 = value;
    }
    if (input > value - value2 && input != 0) {
        servo.write(180);  // 서보 모터를 지정한 각도로 움직임
    }
    else if (input < value - value2 && input != 0) {
        servo.write(90);
        input = 0;
        for (int i = 0; i < numTones; i++)
        {
            tone(speakerPin, tones[i]);
            delay(500);
        }

    }
}