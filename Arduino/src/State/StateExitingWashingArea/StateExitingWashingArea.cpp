#include <Arduino.h>
#include <Scheduler.h>
#include <Config.h>
#include "StateExitingWashingArea.h"
#include "Components/Components.h"
#include "Tasks/DetectCarExitingWashingArea/DetectCarExitWashingArea.h"

StateName StateExitingWashingArea::name(){
    return StateName::ExitingWashingArea;
}

StateExitingWashingArea::StateExitingWashingArea(int carWashed, Components* components, Scheduler* scheduler): State(carWashed) {
    this->components = components;
    this->scheduler = scheduler;
    this->isCarExited = false;
    this->lastTimeCarDetectedInside = millis();

    // print to the screen
    this->components->getUserLcd()->clear();
    this->components->getUserLcd()->setCursor(0, 0);
    this->components->getUserLcd()->print("Washing complete");
    this->components->getUserLcd()->setCursor(0, 1);
    this->components->getUserLcd()->print("you can leave");
    
    // switch on L3
    this->components->getL3()->switchOn();

    // open gate
    this->components->getGate()->setPosition(GATE_OPEN);

    
    Task* carExited = new DetectCarExitWashingArea(components->getCarDistanceDetector(), this);
    carExited->init(500);
    this->scheduler->addTask(carExited);
  
}

bool StateExitingWashingArea::goNext() {
    // distance > MAXDIST for N4 secs
    return this->isCarExited;
}

void StateExitingWashingArea::carExitedWashingArea(bool isCarOutside) {
    if(isCarOutside){
        unsigned long currentTime = millis();
        if((currentTime - this->lastTimeCarDetectedInside) > (N4 * 1000)) {
            this->isCarExited = true;
        }
    } else {
        this->lastTimeCarDetectedInside = millis();
    }
}

StateExitingWashingArea::~StateExitingWashingArea() {
    this->scheduler->removeLastTask(); // remove distance detector
    this->components->getL3()->switchOff();
    this->components->getGate()->setPosition(GATE_CLOSED);
}
