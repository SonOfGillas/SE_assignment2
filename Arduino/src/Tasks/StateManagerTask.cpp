#include <Arduino.h>
#include <Scheduler.h>
#include "State/State.h"
#include "StateManagerTask.h"
#include "State/StateIdle/StateIdle.h"
#include "State/StateWelcome/StateWelcome.h"
#include "State/StateEnteringWashingArea/StateEnteringWashingArea.h"
#include "State/StateError/StateError.h"

StateManagerTask::StateManagerTask(State* state, Components* components, Scheduler* scheduler) {
    this->state = state; 
    this->components = components;
    this->scheduler = scheduler;
}

void StateManagerTask::init(int period) {
    Task::init(period);
}

void StateManagerTask::tick() {
    StateName curretState = this->state->name();
    Serial.println(getStateNameString(curretState));
}