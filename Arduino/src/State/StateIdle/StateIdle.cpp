#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include <Config.h>
#include <Scheduler.h>
#include "StateIdle.h"
#include "Tasks/Sleep/Sleep.h"

bool isWakeup;

StateName StateIdle::name() {
    return StateName::Idle;
}

StateIdle::StateIdle(int carWashed,Scheduler* scheduler):State(carWashed) {
    isWakeup = false;
    this->scheduler = scheduler;
    enableInterrupt(PIN_PIR, this->wakeup, RISING);

    //TODO: if the system turns off instantly the Diagnostic
    //      task will not be able to send the current state
    Task* sleepTask = new Sleep();
    sleepTask->init(500);
    scheduler->addTask(sleepTask);
}

bool StateIdle::goNext() {
    return isWakeup;
}

StateIdle::~StateIdle() {
    disableInterrupt(PIN_PIR);
    this->scheduler->removeLastTask();
}