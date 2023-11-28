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
}

bool StateIdle::goNext() {
    return isWakeup;
}

StateIdle::~StateIdle() {
   
}