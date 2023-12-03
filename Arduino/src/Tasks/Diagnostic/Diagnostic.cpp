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
    StateName curretState = this->stateManager->getCurrentState();
    double temp = this->temperatureDetector->getTemperature();

    if(MsgService.isMsgAvailable()){
        Msg* msg = MsgService.receiveMsg();
        String msgContent = msg->getContent();
        if(msgContent == "RequestData"){
            String stateNameString = getStateNameString(curretState);
            Serial.print("{\"CarWashed\":\"");
            Serial.print(stateManager->getCarWashed());
            Serial.print("\",\"WashingMachineState\":\"");
            Serial.print(stateNameString);
            Serial.print("\",\"Temperature\":\"");
            Serial.print(temp);
            Serial.println("\",}");
            Serial.flush();
        } else if(msgContent == "MantainenceDone"){
            if(curretState == StateName::Error){
                maxTempDetectedTime=0;
                this->isMaxTempDetected = false;
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