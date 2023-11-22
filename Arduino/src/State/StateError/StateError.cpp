#include "StateError.h"
#include "State/State.h"

StateName StateError::name() {
    return StateName::Error;
}

StateError::StateError(StateName previousStateName){
    this->previousStateName = previousStateName;
    this->maintenanceDone = false;
}

bool StateError::goNext(){
    return maintenanceDone;
}

void StateError::setMaintenanceDone(){
    this->maintenanceDone = true;
}