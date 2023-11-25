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
    this->components->userLcd->setCursor(0, 0); 
    this->components->userLcd->print("Welcome");
    this->components->l1->switchOn();

}

bool StateWelcome::goNext() {
    long currentTime = millis();
    return currentTime-(this->arrivalTime) > (N1*1000);
}

StateWelcome::~StateWelcome() {
    this->components->userLcd->clear();
    this->components->l1->switchOff();
}