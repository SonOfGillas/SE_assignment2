#include <Arduino.h>
#include <Scheduler.h>
#include "State/State.h"
#include "StateManagerTask.h"
#include "State/StateIdle/StateIdle.h"
#include "State/StateWelcome/StateWelcome.h"
#include "State/StateEnteringWashingArea/StateEnteringWashingArea.h"

StateManagerTask::StateManagerTask(State* state, Components* components, Scheduler* scheduler) {
    //TODO check if is better to remove this property and use the global variable
    //or this reference is already connected to the global variable
    this->state = state; 
    this->components = components;
    this->scheduler = scheduler;
}

void StateManagerTask::init(int period) {
    Task::init(period);
}

void StateManagerTask::tick() {
   if(state->goNext()) {
        StateName name = state->name();
        delete state;
        switch (name) {
            case StateName::CarExited:
                state = new StateIdle();
                break;
            case StateName::Idle:
                state = new StateWelcome(this->components);
                break;
            case StateName::Welcome:
                state = new StateEnteringWashingArea(this->components, this->scheduler);
                break;
            default:
                // TODO: evaluate if the undefined/unknown/default state
                //       should reset the CPU or switch to StateIdle
                state = new StateIdle();
                break;
        }
    }
}

/*
Idle manda in sleep l'arduino nel costruttore ma prima attacca
un interrupt al pir che lo risveglia
*/
