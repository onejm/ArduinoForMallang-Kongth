#include <Wire.h>

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

void loop()
{
    int water_level = 0;

    Wire.requestFrom(0x77, 1);  // Grove Water Level Sensor 주소: 0x77 or 78
    if (Wire.available())
    {
        water_level = Wire.read();  // 값을 읽어옴
    }

    Serial.println(water_level);  // 값을 시리얼 모니터에 출력
    delay(500);
}