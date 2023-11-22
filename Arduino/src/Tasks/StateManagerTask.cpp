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
                StateError* stateError = (StateError*) state;
                newState = stateFactory(stateError->previousStateName);
                break;
            default:
                // TODO: evaluate if the undefined/unknown/default state
                //       should reset the CPU or switch to StateIdle
                newState = stateFactory(StateName::Idle);
                break;
        }
        delete state;
        state = newState;
    }
}

/* this function need the current state for generate the StateError*/
State* StateManagerTask::stateFactory(StateName stateName) {
    return new StateIdle();
        switch (stateName) {
        case StateName::Idle:
            return new StateIdle();
        case StateName::Welcome:
            return new StateWelcome(this->components);
        case StateName::EnteringWashingArea:
            return new StateEnteringWashingArea(this->components, this->scheduler);
        case StateName::Error:
            return new StateError(this->state->name());
        default:
            return new StateIdle();   
    }
    
}

