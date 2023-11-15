#include "LedExt.h"
#include "Arduino.h"

class LedExt {
    LedExt(int pin) : Led(pin) {
        currentIntensity = 128;
        isOn = false;
    }

    LedExt(int pin, int intensity) : Led(pin) {
        isOn = false;
        currentIntensity = intensity;
    }

    void switchOn() {
        analogWrite(pin,currentIntensity);
        isOn = true;
    }

    void setIntensity(int value) {
        currentIntensity = value;
        if (isOn) {
            analogWrite(pin,currentIntensity);
        }
    }

    void switchOff() {
        analogWrite(pin,0);
        isOn = false;
    }
}
