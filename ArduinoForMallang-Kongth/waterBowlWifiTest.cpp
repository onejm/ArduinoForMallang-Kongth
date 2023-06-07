//���߿� �ڵ� 
#include <ESP8266WiFi.h>
#include <WiFiClient.h>


const char* ssid = "U+Net4C9B";
const char* password = "0111035731";
const char* serverIP = "192.168.219.110"; // ������ ��Ʈ ���� IP �ּ�
const int serverPort = 8080; // ���� ��Ʈ ��ȣ

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
                client.print("h00");
                client.print(i);
                // Ŭ���̾�Ʈ ���� ����
                client.stop();
            }
        }
        delay(500); //0.5�� ���� 
    }
}