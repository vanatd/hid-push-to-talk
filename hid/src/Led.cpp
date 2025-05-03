#pragma once
#include <Arduino.h>

class Led 
{
    int LED_PIN;
public:
    Led(int pin){
        LED_PIN = pin;
    };

    void begin() {
        pinMode(LED_BUILTIN_TX, INPUT); // to control TX LED you need to switch its mode
        pinMode(LED_BUILTIN_RX, INPUT);

        pinMode(LED_PIN, OUTPUT);
    };

    void on(){
        digitalWrite(LED_PIN, HIGH);
    };

    void off(){
        digitalWrite(LED_PIN, LOW);
    };

};