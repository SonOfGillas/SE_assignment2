#include <Arduino.h>
#include <Config.h>
#include "Diagnostic.h"
#include "MsgService.h"
#include "State/State.h"
#include "State/StateError/StateError.h"

Diagnostic::Diagnostic(State* state,TemperatureDetector* temperatureDetector):Task(){
    this->state = state;
    this->temperatureDetector = temperatureDetector;
    this->isMaxTempDetected = false;
    this->maxTempDetectedTime = 0;
}

void Diagnostic::init(int period){
    //Serial.begin(9600);
    Task::init(period);
}

void Diagnostic::tick(){
    StateName curretState = this->state->name();
    double temp = this->temperatureDetector->getTemperature();

    if (MsgService.isMsgAvailable()){
        Msg* msg = MsgService.receiveMsg();    
        if(msg->getContent()=="RequestData"){
            MsgService.sendMsg("{\"CarWashed\":\"0\",\"WashingMachineState\":\"Idle\",\"Temperature\":\"0\",}");
        }
        delete msg;
        }

   /*
    if(MsgService.isMsgAvailable()){
        Msg* msg = MsgService.receiveMsg();
        String msgContent = msg->getContent();
        if(msgContent == "RequestData"){
            String state = "idle"; //TODO: add here the name of the current state, maybe the name can be taken from a map using the state name

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
        } else if(msgContent == "MantainenceDone"){
            if(curretState == StateName::Error){
                StateError* stateError = (StateError*) state;
                stateError->setMaintenanceDone();
            }
        }
        delete msg;
    }
    */

    
    /*
        if(temp > MAXTEMP){
        if(this->isMaxTempDetected == false){
            this->isMaxTempDetected = true;
            this->maxTempDetectedTime = millis();
        } else {
            if(millis() - this->maxTempDetectedTime > N4*1000){
                state->setError();
            }
        }
    } else {
        this->isMaxTempDetected = false;
    }
    */

    
}