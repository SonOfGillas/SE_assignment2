#include "ButtonImpl.h"
#include "Arduino.h"

class ButtonImpl {
    public:
        ButtonImpl(int pin) {
            this->pin = pin;
            pinMode(pin, INPUT);
        }
        
        bool isPressed() {
            return digitalRead(pin) == HIGH;
        }
}
