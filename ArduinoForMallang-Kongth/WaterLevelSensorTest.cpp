#include <Wire.h>

void setup() {
    Wire.begin();
    Serial.begin(9600);
}

void loop()
{
    int water_level = 0;

    Wire.requestFrom(0x77, 1);  // Grove Water Level Sensor �ּ�: 0x77 or 78
    if (Wire.available())
    {
        water_level = Wire.read();  // ���� �о��
    }

    Serial.println(water_level);  // ���� �ø��� ����Ϳ� ���
    delay(500);
}