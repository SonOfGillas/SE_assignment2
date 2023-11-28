#include <Arduino.h>
#include <Config.h>
#include "Diagnostic.h"
#include "MsgService.h"
#include "State/State.h"
#include "State/StateError/StateError.h"

Diagnostic::Diagnostic(State* state,TemperatureDetector* temperatureDetector):Task(){
    this->state = state;
    this->temperatureDetector = temperatureDetector;
}

void Diagnostic::init(int period){
    Task::init(period);
}

void Diagnostic::tick(){
    StateName curretState = this->state->name();

    Serial.println("Diagnostic");
    delete this->state;
    this->state= new StateError(0,StateName::Idle);

}