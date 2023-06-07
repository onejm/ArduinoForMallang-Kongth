#include "HX711.h"
#define calibration_factor 574.3 //캘리브레이션 값
#define DOUT  3 //데이터 핀
#define CLK  2 // 클럭 핀


const char* ssid = "U+Net4C9B";
const char* password = "0111035731";
const char* serverIP = "localhost";
const int serverPort = 8080;

int value;
HX711 scale(DOUT, CLK);
void setup() {
    Serial.begin(9600);  // 값 모니터링 위해서...
    scale.set_scale(calibration_factor);
    scale.tare(); //영점잡기. 현재 측정값을 0으로 둔다.
}
void loop() {
    value = (int)scale.get_units();
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