//개발용 코드 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "Wi-Fi_SSID"; // Wi-Fi 네트워크 이름
const char* password = "kgu@jump1"; // Wi-Fi 비밀번호
const char* serverIP = "127.0.0.1"; // 스프링 부트 서버 IP 주소
const int serverPort = 1234; // 서버 포트 번호

void setup() { // setup안에 코드는 처음 한번만 실행됨
    Serial.begin(9600);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void loop() { // loop안에 코드가 아두이노가 무한 반복으로 실행됨
    for (int i = 50; i > 20; i--) {
        Serial.print("h00");
        Serial.print(i);
        if (WiFi.status() == WL_CONNECTED) {
            WiFiClient client;

            if (client.connect(serverIP, serverPort)) {
                // 서버로 데이터 전송
                Client.print("h00");
                Client.print(i);
                // 클라이언트 연결 종료
                client.stop();
            }
        }
        delay(500); //0.5초 정지 
    }
}