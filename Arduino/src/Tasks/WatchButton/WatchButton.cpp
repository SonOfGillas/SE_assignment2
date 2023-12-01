#include "WatchButton.h"
#include <Button.h>
#include "ButtonListener.h"

WatchButton::WatchButton(Button* button, ButtonListener* listener) {
    this->listener = listener;
    this->button = button;
    this->isButtonPressed = false;
}

void WatchButton::init(int period) {
    Task::init(period);
}

void WatchButton::tick() {
    // call the listener only once
    if(this->button->isPressed() && !this->isButtonPressed) {
        this->isButtonPressed = true;
        this->listener->buttonPressed(true);
    }
}


