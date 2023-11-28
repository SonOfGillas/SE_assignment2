#include "StateError.h"
#include "State/State.h"

StateName StateError::name() {
    return StateName::Error;
}

StateError::StateError(int carWashed,StateName previousStateName):State(carWashed){
    this->previousStateName = previousStateName;
    this->maintenanceDone = false;
}

bool StateError::goNext(){
    return this->maintenanceDone;
}

void StateError::setMaintenanceDone(){
    this->maintenanceDone = true;
}