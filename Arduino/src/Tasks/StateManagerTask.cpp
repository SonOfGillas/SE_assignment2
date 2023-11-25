#include <Arduino.h>
#include <Scheduler.h>
#include "State/State.h"
#include "StateManagerTask.h"
#include "State/StateIdle/StateIdle.h"
#include "State/StateWelcome/StateWelcome.h"
#include "State/StateEnteringWashingArea/StateEnteringWashingArea.h"
#include "State/StateError/StateError.h"

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
   if(state->hasError()) {
        State* newState = stateFactory(StateName::Error);
        delete state;
        state = newState; 
   }
   if(state->goNext()) {
        StateName currentState = state->name();
        State* newState;
        switch (currentState) {
            case StateName::CarExited:
                newState = stateFactory(StateName::Idle);
                break;
            case StateName::Idle:
                newState = stateFactory(StateName::Welcome);
                break;
            case StateName::Welcome:
                newState = stateFactory(StateName::EnteringWashingArea);
                break;
            case StateName::Error:
            default:
                StateError* stateError = (StateError*) state;
                newState = stateFactory(stateError->previousStateName);
                break;
                // TODO: evaluate if the undefined/unknown/default state
                //       should reset the CPU or switch to StateIdle
        }
        delete state;
        state = newState;
    }
}

/* this function need the current state for generate the StateError*/
State* StateManagerTask::stateFactory(StateName stateName) {
    int carWashed = state->getCarWashed();
    switch (stateName) {
        case StateName::Idle:
            return new StateIdle(carWashed,this->scheduler);
        case StateName::Welcome:
            return new StateWelcome(carWashed,this->components);
        case StateName::EnteringWashingArea:
            return new StateEnteringWashingArea(carWashed,this->components, this->scheduler);
        case StateName::Error:
        default:
            return new StateError(carWashed,this->state->name());  
    }
    
}

