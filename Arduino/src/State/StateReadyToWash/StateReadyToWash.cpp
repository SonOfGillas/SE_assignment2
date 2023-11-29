#include <Arduino.h>
#include <Scheduler.h>
#include <Config.h>
#include "StateReadyToWash.h"
#include "Components/Components.h"
#include "Tasks/WatchButton/WatchButton.h"

StateName StateReadyToWash::name() {
    return StateName::ReadyToWash;
}

StateReadyToWash::StateReadyToWash(int carWashed, Components* components, Scheduler* scheduler): State(carWashed) {
    this->components = components;
    this->scheduler = scheduler;

    this->isButtonPressed = false;

    // close gate
    this->components->gate->setPosition(0);

    // switch on L2
    this->components->l2->switchOn();

    // print to the screen
    this->components->userLcd->clear();
    this->components->userLcd->setCursor(0, 0); 
    this->components->userLcd->print("Ready to wash");
    
    Task* watchButton = new WatchButton(components, this);
    watchButton->init(100);
    this->scheduler->addTask(watchButton);
}

bool StateReadyToWash::goNext() {
    return this->isButtonPressed;
}

void StateReadyToWash::buttonPressed(bool isButtonPressed) {
    if(isButtonPressed && !this->isButtonPressed)
        this->isButtonPressed = true;
}

StateReadyToWash::~StateReadyToWash() {
    scheduler->removeLastTask(); // remove watch task
}
