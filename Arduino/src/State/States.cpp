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
        case StateName::ReadyToWash:
            return "Ready To Wash";
        case StateName::Washing:
            return "Washing";
        case StateName::ExitingWashingArea:
            return "Exiting Washing Area";
        case StateName::Error:
        default:
            return "Error";
    }
}