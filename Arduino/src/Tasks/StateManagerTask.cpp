#include <Arduino.h>
#include <Scheduler.h>
#include "State/State.h"
#include "StateManagerTask.h"
#include "State/StateIdle/StateIdle.h"
#include "State/StateWelcome/StateWelcome.h"
#include "State/StateEnteringWashingArea/StateEnteringWashingArea.h"
#include "State/StateError/StateError.h"
#include "State/StateReadyToWash/StateReadyToWash.h"

StateManagerTask::StateManagerTask(State* state, Components* components, Scheduler* scheduler) {
    this->state = state; 
    this->components = components;
    this->scheduler = scheduler;
}

void StateManagerTask::init(int period) {
    Task::init(period);
}

void StateManagerTask::tick() {
    if(this->state->name() != StateName::Error &&  this->state->hasError()) {
        State* newState = stateFactory(StateName::Error);;
        delete this->state;
        this->state = newState; 
    }
    if(this->state->goNext()) {
        StateName currentState = this->state->name();
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
            case StateName::EnteringWashingArea:
                newState = stateFactory(StateName::ReadyToWash);
                break;
            case StateName::ReadyToWash:
                newState = stateFactory(StateName::Washing);
                break;
            case StateName::Washing:
                newState = stateFactory(StateName::ExitingWashingArea);
                break;
            case StateName::ExitingWashingArea:
                newState = stateFactory(StateName::CarExited);
                break;
            case StateName::Error:
            default:
                // TODO: evaluate if the undefined/unknown/default state
                //       should reset the CPU or switch to StateIdle
                StateError* stateError = (StateError*) state;
                newState = stateFactory(stateError->previousStateName);
                break;
        }
        delete this->state;
        this->state = newState;
    }
}

/* this function need the current state for generate the StateError*/
State* StateManagerTask::stateFactory(StateName stateName) {
    int carWashed = this->state->getCarWashed();
    switch (stateName) {
        case StateName::Idle:
            return new StateIdle(carWashed,this->scheduler);
        case StateName::Welcome:
            return new StateWelcome(carWashed,this->components);
        case StateName::EnteringWashingArea:
            return new StateEnteringWashingArea(carWashed,this->components, this->scheduler);
        case StateName::ReadyToWash:
            return new StateReadyToWash(carWashed, this->components, this->scheduler);
        // case StateName::Washing:
        //     return new StateWashing();
        // case StateName::ExitingWashingArea:
        //     return new StateExitingWashingArea();
        // case StateName::CarExited:
        //     return new StateCarExited();
        case StateName::Error:
        default:
            return new StateError(carWashed,this->state->name());  
    }
}
