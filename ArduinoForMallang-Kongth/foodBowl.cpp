
#include <Servo.h>
#include "HX711.h"
#define calibration_factor 533.33//Ä¶¸®ºê·¹ÀÌ¼Ç °ª
#define DOUT  4 //µ¥ÀÌÅÍÇÉ
#define CLK  3 //Å¬·°ÇÉ
Servo servo;
HX711 scale(DOUT, CLK);
int value;
int value2;
int input = 0;
int angle = 90;
int speakerPin = 5;
int numTones = 8;
int tones[] = { 261, 293, 329, 349, 391, 440, 493, 523 };

void setup() {
    Serial.begin(9600);
    servo.attach(2);
    scale.set_scale(calibration_factor);
    scale.tare();
}

void loop() {
    value = (int)scale.get_units();
    if (value <= 2) {
        Serial.print("h");
        Serial.print("0000");
    }
    else if (value > 2 && value <= 9) {
        Serial.print("h");
        Serial.print("000");
        Serial.print(value);
    }
    else if (value > 9 && value <= 99) {
        Serial.print("h");
        Serial.print("00");
        Serial.print(value);
    }
    else if (value > 99 && value <= 999) {
        Serial.print("h");
        Serial.print("0");
        Serial.print(value);
    }
    else {
        Serial.print("h");
        Serial.print(value);
    }
    if (Serial.available() > 0 && input == 0) {
        input = Serial.parseInt();
        value2 = value;
    }
    if (input > value - value2 && input != 0) {
        servo.write(180);
    }
    else if (input < value - value2 && input != 0) {
        servo.write(90);
        input = 0;
        for (int i = 0; i < numTones; i++)
        {
            tone(speakerPin, tones[i]);
            delay(500);
        }
        noTone(speakerPin);
    }
}