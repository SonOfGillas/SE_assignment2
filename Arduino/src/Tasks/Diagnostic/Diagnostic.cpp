#include <Arduino.h>
#include <Config.h>
#include "Diagnostic.h"
#include "MsgService.h"
#include "State/State.h"
#include "State/StateManager.h"
#include "State/StateError/StateError.h"

Diagnostic::Diagnostic(StateManager* stateManager,TemperatureDetector* temperatureDetector):Task(){
    this->stateManager = stateManager;
    this->temperatureDetector = temperatureDetector;
    this->isMaxTempDetected = false;
    this->maxTempDetectedTime = 0;
}

void Diagnostic::init(int period){
    Task::init(period);
}

void Diagnostic::tick(){
    StateName curretState = this->stateManager->getCurrentState()->name();
    double temp = this->temperatureDetector->getTemperature();

    if(MsgService.isMsgAvailable()){
        Msg* msg = MsgService.receiveMsg();
        String msgContent = msg->getContent();
        if(msgContent == "RequestData"){
            String stateNameString = getStateNameString(curretState);

            String openingTag = "{";
            String carWashedTag = "\"CarWashed\":";
            String carWashedData = "\""+String(this->stateManager->getCurrentState()->getCarWashed())+"\",";
            String washingMachineStateTag = "\"WashingMachineState\":";
            String washingMachineStateData = "\""+stateNameString+"\",";
            String temperatureTag = "\"Temperature\":";
            String temperatureData = "\"" + String(temp, 1) + "C°\",";
            String closingTag = "}";

            //message exemple: "{\"CarWashed\":\"0\",\"WashingMachineState\":\"idle\",\"Temperature\":\"0\",}"
            String msg = openingTag + carWashedTag + carWashedData + washingMachineStateTag + washingMachineStateData + temperatureTag + temperatureData + closingTag;
            
            MsgService.sendMsg(msg);
        } else if(msgContent == "MantainenceDone"){
            if(curretState == StateName::Error){
                this->stateManager->setError(false);
            }
        }
        delete msg;
    }

    if(temp > MAXTEMP){
        if(this->isMaxTempDetected == false){
            this->isMaxTempDetected = true;
            this->maxTempDetectedTime = millis();
        } else {
            if(millis() - this->maxTempDetectedTime > N4*1000){
                this->stateManager->setError(true);
            }
        }
    } else {
        this->isMaxTempDetected = false;
    }
}