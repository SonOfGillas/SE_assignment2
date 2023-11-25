#include <Arduino.h>
#include <Config.h>
#include "Diagnostic.h"
#include "MsgService.h"
#include "State/State.h"
#include "State/StateError/StateError.h"

Diagnostic::Diagnostic(State* state,TemperatureDetector* temperatureDetector){
    MsgService.init();
    this->temperatureDetector = temperatureDetector;
    this->isMaxTempDetected = false;
    this->maxTempDetectedTime = 0;
}

void Diagnostic::init(int period){
    Task::init(period);
}

void Diagnostic::tick(){
    StateName curretState = state->name();
    if(curretState == StateName::Error){
       if (MsgService.isMsgAvailable()) {
            Msg* msg = MsgService.receiveMsg();
            if (msg->getContent() == "Maintenance done"){
                StateError* stateError = (StateError*) state;
                stateError->setMaintenanceDone();
            }
            delete msg;
        }
    } else {
        MsgService.sendMsg("app data"); //TODO: send current state name, temperature and number of cars washed
    }

    if(this->temperatureDetector->getTemperature() > MAXTEMP){
        if(this->isMaxTempDetected == false){
            this->isMaxTempDetected = true;
            this->maxTempDetectedTime = millis();
        } else {
            if(millis() - this->maxTempDetectedTime > N4*1000){
                MsgService.sendMsg("ERROR"); //TODO: send error message
                state->setError();
            }
        }
    } else {
        this->isMaxTempDetected = false;
    }
}