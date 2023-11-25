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
    double temp = this->temperatureDetector->getTemperature();
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
        String state = "idle";

        String openingTag = "{";
        String carWashedTag = "\"CarWashed\":";
        String carWashedData = "\""+String(this->state->getCarWashed())+"\",";
        String washingMachineStateTag = "\"WashingMachineState\":";
        String washingMachineStateData = "\""+state+"\",";
        String temperatureTag = "\"Temperature\":";
        String temperatureData = "\"" + String(temp, 4) + "C°\",";
        String closingTag = "}";

        //message exemple: "{\"CarWashed\":\"0\",\"WashingMachineState\":\"idle\",\"Temperature\":\"0\",}"
        String msg = openingTag + carWashedTag + carWashedData + washingMachineStateTag + washingMachineStateData + temperatureTag + temperatureData + closingTag;
        
        MsgService.sendMsg(msg);
    }

    if(temp > MAXTEMP){
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