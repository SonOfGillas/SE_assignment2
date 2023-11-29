#include <Arduino.h>
#include <Scheduler.h>
#include <Config.h>
#include "StateWashing.h"
#include "Components/Components.h"

StateName StateWashing::name() {
    return StateName::ReadyToWash;
}

StateWashing::StateWashing(int carWashed, Components* components, Scheduler* scheduler): State(carWashed) {
    this->components = components;
    this->scheduler = scheduler;

    this->enteredTime = millis();

    // print to the screen
    this->components->userLcd->clear();
    this->components->userLcd->setCursor(0, 0); // col, line
    this->components->userLcd->print("Washing");
    
    // display countdown N3
}

bool StateWashing::goNext() {
    return millis() - this->enteredTime > N3 * 1000;
}

StateWashing::~StateWashing() {
    scheduler->removeLastTask(); // remove watch task
}
