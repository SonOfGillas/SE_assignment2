#include <Arduino.h>
#include "model.h"
#include "State/State.h"
#include "StateManagerTask.h"
#include "State/StateIdle/StateIdle.h"
#include "State/StateWelcome/StateWelcome.h"

StateManagerTask::StateManagerTask(State* state,Components* components) {
    //TODO check if is better to remove this property and use the global variable
    //or this reference is already connected to the global variable
    this->state = state; 
    this->components = components;
}

void StateManagerTask::init(int period) {
    Task::init(period);
}

void StateManagerTask::tick() {
   if(state->goNext()){
        // TODO: check if is possible to use typeof instead of StateName
        switch (state->name()) {
            case StateName::CarExited:
                delete state;
                state = new StateIdle();
                break;
            case StateName::Idle:
                delete state;
                state = new StateWelcome(this->components);
                break;
            default:
                break;
        }
    }
}

/*
Idle manda in sleep l'arduino nel costruttore ma prima attacca
un interrupt al pir che lo risveglia
*/
