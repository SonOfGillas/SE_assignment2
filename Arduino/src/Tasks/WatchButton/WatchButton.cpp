#include "WatchButton.h"
#include <Components/Components.h>
#include <Button.h>
#include "ButtonListener.h"

WatchButton::WatchButton(Components* components, ButtonListener* listener) {
    this->listener = listener;
    this->button = components->startButton;
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


