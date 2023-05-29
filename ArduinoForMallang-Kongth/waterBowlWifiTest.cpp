//���߿� �ڵ� 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

const char* ssid = "Wi-Fi_SSID"; // Wi-Fi ��Ʈ��ũ �̸�
const char* password = "kgu@jump1"; // Wi-Fi ��й�ȣ
const char* serverIP = "127.0.0.1"; // ������ ��Ʈ ���� IP �ּ�
const int serverPort = 1234; // ���� ��Ʈ ��ȣ

void setup() { // setup�ȿ� �ڵ�� ó�� �ѹ��� �����
    Serial.begin(9600);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
    for (int i = 50; i > 20; i--) {
        Serial.print("h00");
        Serial.print(i);
        if (WiFi.status() == WL_CONNECTED) {
            WiFiClient client;

            if (client.connect(serverIP, serverPort)) {
                // ������ ������ ����
                Client.print("h00");
                Client.print(i);
                // Ŭ���̾�Ʈ ���� ����
                client.stop();
            }
        }
        delay(500); //0.5�� ���� 
    }
}