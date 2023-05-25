//개발용 코드 
#include <Servo.h>
Servo servo;
int angle = 90;
void setup() { // setup안에 코드는 처음 한번만 실행됨
    Serial.begin(9600);
    servo.attach(9);
}

void loop() { // loop안에 코드가 아두이노가 무한 반복으로 실행됨
    for (int i = 40; i > 20; i--) {
        Serial.print("h00");
        Serial.print(i);
        if (Serial.available() > 0) {  // 시리얼 버퍼에 데이터가 있는지 확인
            int input = Serial.parseInt();  // 입력된 정수 값을 읽어옴

            if (input == 1) {  // 입력 값이 1인 경우
                angle = 180;  // 서보 모터 각도를 90도로 설정
                servo.write(angle);  // 서보 모터를 지정한 각도로 움직임
                delay(500);  // 0.5초 대기
            }
            if (input == 2) {  // 입력 값이 1인 경우
                angle = 0;  // 서보 모터 각도를 90도로 설정
                servo.write(angle);  // 서보 모터를 지정한 각도로 움직임
                delay(500);  // 0.5초 대기
            }
        }
    }
    delay(500); //0.5초 정지 
}