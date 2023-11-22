#include <Arduino.h>
#include <Config.h>
#include "ConsoleDashboard.h"
#include "MsgService.h"
#include "State/State.h"
#include "State/StateError/StateError.h"

ConsoleDashboard::ConsoleDashboard(State* state,TemperatureDetector* temperatureDetector){
    MsgService.init();
    this->temperatureDetector = temperatureDetector;
    this->isMaxTempDetected = false;
    this->maxTempDetectedTime = 0;
}

void ConsoleDashboard::init(int period){
    Task::init(period);
}

void ConsoleDashboard::tick(){
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