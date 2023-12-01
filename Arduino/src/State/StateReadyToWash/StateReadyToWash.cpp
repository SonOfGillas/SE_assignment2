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
    this->components->getGate()->setPosition(0);

    // switch on L2
    this->components->getL2()->switchOn();

    // print to the screen
    this->components->getUserLcd()->clear();
    this->components->getUserLcd()->setCursor(0, 0); 
    this->components->getUserLcd()->print("Ready to wash");
    
    Task* watchButton = new WatchButton(components->getStartButton(), this);
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
