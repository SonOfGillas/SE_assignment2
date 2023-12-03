#include "StateManager.h"
#include "State/State.h"
#include "State/StateIdle/StateIdle.h"
#include "State/StateWelcome/StateWelcome.h"
#include "State/StateEnteringWashingArea/StateEnteringWashingArea.h"
#include "State/StateError/StateError.h"
#include "State/StateReadyToWash/StateReadyToWash.h"
#include "State/StateInitial/StateInitial.h"
#include "State/StateWashing/StateWashing.h"
#include "State/StateExitingWashingArea/StateExitingWashingArea.h"

StateManager::StateManager(Components* components, Scheduler* scheduler) {
    this->scheduler = scheduler;
    this->components = components;
    this->scheduler = scheduler;
    this->state = new StateInitial(0);
}

void StateManager::switchState(){
    if(this->state->name() != StateName::Error &&  this->state->hasError()) {
        State* newState = stateFactory(StateName::Error);
        delete this->state;
        this->state = newState; 
    }
    if(this->state->goNext()) {
        StateName currentState = this->state->name();
        State* newState;
        switch (currentState) {
            case StateName::Initial:
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
                this->state->addCarWashed();
                newState = stateFactory(StateName::ExitingWashingArea);
                break;
            case StateName::ExitingWashingArea:
                newState = stateFactory(StateName::Idle);
                break;
            case StateName::Error:
            default:
                StateError* stateError = (StateError*) state;
                newState = stateFactory(stateError->previousStateName);
                break;
        }
        delete this->state;
        this->state = newState;
    }
}

void StateManager::setError(bool error){
    if(error){
        this->state->setError();
    } else {
        if(this->state->name() == StateName::Error) {
            StateError* stateError = (StateError*) this->state;
            stateError->setMaintenanceDone();
        }
    }
}

StateName StateManager::getCurrentState(){
    return this->state->name();
}

int StateManager::getCarWashed(){
    return this->state->getCarWashed();
}

/* this function need the current state for generate the StateError*/
State* StateManager::stateFactory(StateName stateName) {
    int carWashed = this->state->getCarWashed();
    switch (stateName) {
        case StateName::Initial:
            return new StateInitial(carWashed);
        case StateName::Idle:
            return new StateIdle(carWashed,this->scheduler);
        case StateName::Welcome:
            return new StateWelcome(carWashed,this->components);
        case StateName::EnteringWashingArea:
            return new StateEnteringWashingArea(carWashed,this->components, this->scheduler);
        case StateName::ReadyToWash:
            return new StateReadyToWash(carWashed, this->components, this->scheduler);
        case StateName::Washing:
            return new StateWashing(carWashed, this->components, this->scheduler);
        case StateName::ExitingWashingArea:
            return new StateExitingWashingArea(carWashed, this->components, this->scheduler);
        case StateName::Error:
        default:
            return new StateError(carWashed,this->state->name());  
    }
}
