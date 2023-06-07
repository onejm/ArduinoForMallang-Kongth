//개발용 코드 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>


const char* ssid = "U+Net4C9B";
const char* password = "0111035731";
const char* serverIP = "192.168.219.110"; // 스프링 부트 서버 IP 주소
const int serverPort = 8080; // 서버 포트 번호

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
                client.print("h00");
                client.print(i);
                // 클라이언트 연결 종료
                client.stop();
            }
        }
        delay(500); //0.5초 정지 
    }
}