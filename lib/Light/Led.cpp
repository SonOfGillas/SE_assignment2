#include "Led.h"
#include "Arduino.h"

class Led {
    Led(int pin) {
        this->pin = pin;
        pinMode(pin,OUTPUT);
    }

    void switchOn() {
        digitalWrite(pin,HIGH);
    }

    void switchOff() {
        digitalWrite(pin,LOW);
    };
}
