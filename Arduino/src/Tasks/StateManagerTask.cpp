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
   if(state->goNext()) {
        StateName name = state->name();
        delete state;
        switch (name) {
            case StateName::CarExited:
                state = stateFactory(StateName::Idle);
                break;
            case StateName::Idle:
                state = stateFactory(StateName::Welcome);
                break;
            case StateName::Welcome:
                state = stateFactory(StateName::EnteringWashingArea);
                break;
            case StateName::Error:
                StateError* stateError = (StateError*) state;
                state = stateFactory(stateError->previousStateName);
                break;
            default:
                // TODO: evaluate if the undefined/unknown/default state
                //       should reset the CPU or switch to StateIdle
                state = stateFactory(StateName::Idle);
                break;
        }
    }
}


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

