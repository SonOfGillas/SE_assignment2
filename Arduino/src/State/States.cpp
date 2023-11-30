#include "States.h"

String getStateNameString(StateName stateName){
    switch(stateName){
        case StateName::Initial:
            return "Initial";
        case StateName::Idle:
            return "Idle";
        case StateName::Welcome:
            return "Welcome";
        case StateName::EnteringWashingArea:
            return "Entering Washing Area";
        case StateName::CarExited:
            return "Car Exited";
        case StateName::Error:
        default:
            return "Error";
    }
}