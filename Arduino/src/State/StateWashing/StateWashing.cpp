#include <Arduino.h>
#include <Scheduler.h>
#include <Config.h>
#include "StateWashing.h"
#include "Components/Components.h"
#include "StateWashing.h"
#include "Tasks/LcdCountdown/LcdCountdown.h"

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
    Task* lcdCountdown = new LcdCountdown(components->userLcd, this);
    lcdCountdown->init(500);
    this->scheduler->addTask(lcdCountdown);
}

bool StateWashing::goNext() {
    return getRemainingTime() == 0;
}

unsigned long StateWashing::getRemainingTime() {
    unsigned long elapsed_time = millis() - this->enteredTime;
    if(elapsed_time > N3 * 1000) {
        return 0;
    } else {
        return N3 * 1000 - elapsed_time;
    }
}

StateWashing::~StateWashing() {
    scheduler->removeLastTask(); // remove lcd countdown
}
