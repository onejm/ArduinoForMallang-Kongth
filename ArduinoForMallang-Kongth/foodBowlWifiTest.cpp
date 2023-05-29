//개발용 코드 
#include <Servo.h>
#include "HX711.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#define calibration_factor 527.5 //캘리브레이션 값
#define DOUT  4 //데이터 핀
#define CLK  3 // 클럭 핀
const char* ssid = "Wi-Fi_SSID"; // Wi-Fi 네트워크 이름
const char* password = "kgu@jump1"; // Wi-Fi 비밀번호
const char* serverIP = "127.0.0.1"; // 스프링 부트 서버 IP 주소
const int serverPort = 1234; // 서버 포트 번호
Servo servo;
HX711 scale(DOUT, CLK);
int value;
int value2;
int input = 0;
int angle = 90;
void setup() { // setup안에 코드는 처음 한번만 실행됨
    Serial.begin(9600);
    servo.attach(9);
    scale.set_scale(calibration_factor);
    scale.tare(); //영점잡기. 현재 측정값을 0으로 둔다.
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void loop() { // loop안에 코드가 아두이노가 무한 반복으로 실행됨
    value = (int)scale.get_units();
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;

        if (client.connect(serverIP, serverPort)) {
            // 서버로 데이터 전송
            if (value <= 2) {
                Client.print("h");
                Client.print("0000");
            }
            else if (value > 2 && value <= 9) {
                Client.print("h");
                Client.print("000");
                Client.print(value);
            }
            else if (value > 9 && value <= 99) {
                Client.print("h");
                Client.print("00");
                Client.print(value);
            }
            else if (value > 99 && value <= 999) {
                Client.print("h");
                Client.print("0");
                Client.print(value);
            }
            else {
                Client.print("h");
                Client.print(value);
            }
            // 클라이언트 연결 종료

            if (input == 0) {
                while (client.available() > 0) {  // 시리얼 버퍼에 데이터가 있는지 확인
                    String data = client.readStringUntil('\n'); // 입력된 정수 값을 읽어옴
                    value2 = value;
                    input = data; //string int로 변환 필요
                }
            }
            if (input > value - value2 && input != 0) {
                servo.write(180);  // 서보 모터를 지정한 각도로 움직임
            }
            else if (input < value - value2 && input != 0) {
                servo.write(90);
                input = 0;
            }

            client.stop();
        }
    }
}