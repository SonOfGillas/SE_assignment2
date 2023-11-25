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

    this->components->userLcd->clear();
    this->components->userLcd->setCursor(0, 0); 
    this->components->userLcd->print("Procede to the Washing Area");
    
    this->enteredTime = 0;

    Task* detectCarInWashingArea = new DetectCarInWashingArea(this->components, this);
    detectCarInWashingArea->init(300);
    this->scheduler->addTask(detectCarInWashingArea);

    Task* blinkTask = new BlinkLed(this->components->l2);
    blinkTask->init(100);
    this->scheduler->addTask(blinkTask);
}

bool StateEnteringWashingArea::goNext(){
    long currentTime = millis();
    return this->isCarInWashingArea? 
        currentTime-(this->enteredTime) > (N2*1000) 
        : false;
}

void StateEnteringWashingArea::carInWashingArea(bool isCarInWashingArea){
    if(this->isCarInWashingArea == false && isCarInWashingArea == true){
        this->enteredTime = millis();
    }
    this->isCarInWashingArea = isCarInWashingArea;
}

StateEnteringWashingArea::~StateEnteringWashingArea(){
    scheduler->removeLastTask(); // remove blink task
    scheduler->removeLastTask(); // remove detect car task
}