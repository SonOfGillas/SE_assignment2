#include <Arduino.h>
#include <Config.h>
#include "Components/Components.h"
#include "StateWelcome.h"

StateName StateWelcome::name() {
    return StateName::Welcome;
}

StateWelcome::StateWelcome(int carWashed, Components* components):State(carWashed) {
    this->components = components;
    this->arrivalTime = millis();
    this->components->getUserLcd()->setCursor(0, 0); 
    this->components->getUserLcd()->print("Welcome");
    this->components->getL1()->switchOn();

}

bool StateWelcome::goNext() {
    long currentTime = millis();
    return currentTime-(this->arrivalTime) > (N1*1000);
}

StateWelcome::~StateWelcome() {
    this->components->getUserLcd()->clear();
    this->components->getL1()->switchOff();
}