#include "LcdCountdown.h"
#include <LcdScreen.h>
#include "CountdownListener.h"

LcdCoutndown::LcdCoutndown(LcdScreen* lcd, CountdownListener* handler) {
    this->lcd = lcd;
    this->handler = handler;
}

void LcdCoutndown::tick() {
    this->lcd->setCursor(0, 1);
    char str[20]; // 20 columns of the LCD
    snprintf(str, 20, "Timeout: %lu", handler->getRemainingTime()/1000);
    this->lcd->print(str);
}