#include <Arduino.h>
#include "model.h"
#include "State/State.h"
#include "State/StateIdle/StateIdle.h"
#include "StateManagerTask.h"

StateManagerTask::StateManagerTask(State* state) {
    //TODO check if is better to remove this property and use the global variable
    //or this reference is already connected to the global variable
    this->state = state; 
}

void StateManagerTask::init(int period) {
    Task::init(period);
}

void StateManagerTask::tick() {
   if(state->goNext()){
        // TODO: check if is possible to use typeof instead of StateName
        switch (state->name)
        {
        case StateName::CarExited:
            state = new StateIdle();
            break;
        default:
            break;
        }
   }
}


/*
Idele manda in sleep l'arduino nel costruttore ma prima attacca
un interrupt al pir che lo risveglia
*/