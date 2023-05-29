//���߿� �ڵ� 
#include <Servo.h>
#include "HX711.h"
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#define calibration_factor 527.5 //Ķ���극�̼� ��
#define DOUT  4 //������ ��
#define CLK  3 // Ŭ�� ��
const char* ssid = "Wi-Fi_SSID"; // Wi-Fi ��Ʈ��ũ �̸�
const char* password = "kgu@jump1"; // Wi-Fi ��й�ȣ
const char* serverIP = "127.0.0.1"; // ������ ��Ʈ ���� IP �ּ�
const int serverPort = 1234; // ���� ��Ʈ ��ȣ
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
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }
}

void loop() { // loop�ȿ� �ڵ尡 �Ƶ��̳밡 ���� �ݺ����� �����
    value = (int)scale.get_units();
    if (WiFi.status() == WL_CONNECTED) {
        WiFiClient client;

        if (client.connect(serverIP, serverPort)) {
            // ������ ������ ����
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
            // Ŭ���̾�Ʈ ���� ����

            if (input == 0) {
                while (client.available() > 0) {  // �ø��� ���ۿ� �����Ͱ� �ִ��� Ȯ��
                    String data = client.readStringUntil('\n'); // �Էµ� ���� ���� �о��
                    value2 = value;
                    input = data; //string int�� ��ȯ �ʿ�
                }
            }
            if (input > value - value2 && input != 0) {
                servo.write(180);  // ���� ���͸� ������ ������ ������
            }
            else if (input < value - value2 && input != 0) {
                servo.write(90);
                input = 0;
            }

            client.stop();
        }
    }
}