#include <Arduino.h>
#include <Scheduler.h>
#include <Config.h>
#include "StateEnteringWashingArea.h"
#include "Components/Components.h"
#include "Tasks/DetectCarInWashingArea/DetectCarInWashingArea.h"
#include "Tasks/BlinkLed/BlinkLed.h"

StateName StateEnteringWashingArea::name() {
    return StateName::EnteringWashingArea;
}

StateEnteringWashingArea::StateEnteringWashingArea(int carWashed,Components* components, Scheduler* scheduler):State(carWashed){
    this->components = components;
    this->scheduler = scheduler;

    this->components->getUserLcd()->clear();
    this->components->getUserLcd()->setCursor(0, 0); 
    this->components->getUserLcd()->print("Procede to the Washing Area");

    this->components->getGate()->setPosition(GATE_OPEN);

    this->lastTimeCarDetectedOutside = millis();

    Task* detectCarInWashingArea = new DetectCarInWashingArea(this->components->getCarDistanceDetector(), this);
    detectCarInWashingArea->init(300);
    this->scheduler->addTask(detectCarInWashingArea);

    Task* blinkTask = new BlinkLed(this->components->getL2());
    blinkTask->init(100);
    this->scheduler->addTask(blinkTask);
}

bool StateEnteringWashingArea::goNext(){
    long currentTime = millis();
    return this->isCarInWashingArea? currentTime-(this->lastTimeCarDetectedOutside) > (N2*1000) : false;
}

void StateEnteringWashingArea::carInWashingArea(bool isCarInWashingArea){
    if(isCarInWashingArea == false){
        lastTimeCarDetectedOutside = millis(); 
    }
    this->isCarInWashingArea = isCarInWashingArea;
}

StateEnteringWashingArea::~StateEnteringWashingArea(){
    this->components->getGate()->off();
    scheduler->removeLastTask(); // remove blink task
    scheduler->removeLastTask(); // remove detect car task
}