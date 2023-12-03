#include <Arduino.h>
#include <Scheduler.h>
#include <Config.h>
#include "StateReadyToWash.h"
#include "Components/Components.h"
#include "EnableinterruptLib.h"

bool isButtonPressed;

StateName StateReadyToWash::name() {
    return StateName::ReadyToWash;
}

StateReadyToWash::StateReadyToWash(int carWashed, Components* components, Scheduler* scheduler): State(carWashed) {
    this->components = components;
    this->scheduler = scheduler;

    //this->isButtonPressed = false;
    isButtonPressed = false;
    enableInterruptLib(PIN_BUTTON, this->buttonPressed, FALLING);

    // close gate
    this->components->getGate()->setPosition(GATE_CLOSED);

    // switch on L2
    this->components->getL2()->switchOn();

    // print to the screen
    this->components->getUserLcd()->clear();
    this->components->getUserLcd()->setCursor(0, 0); 
    this->components->getUserLcd()->print("Ready to wash");
}

bool StateReadyToWash::goNext() {
    return isButtonPressed;
}

StateReadyToWash::~StateReadyToWash() {
    this->components->getUserLcd()->clear();
    disableInterruptLib(PIN_BUTTON);
}
