#include <Arduino.h>
#include <Sonar.h>
#include <Config.h>
#include "DetectCarInWashingArea.h"
#include "CarInWashingAreaListener.h"

DetectCarInWashingArea::DetectCarInWashingArea(Components* components, CarInWashingAreaListener* listener) {
    this->sonar = components->carDistanceDetector;
    this->listener = listener;
    this->isCarInWashingArea = false;
}

void DetectCarInWashingArea::init(int period) {
    Task::init(period);
}

void DetectCarInWashingArea::tick() {
    float distance = this->sonar->getDistance();
    bool isCarInWashingArea = distance < MINDIST;
    if(this->isCarInWashingArea != isCarInWashingArea){
        this->isCarInWashingArea = isCarInWashingArea;
        this->listener->carInWashingArea(isCarInWashingArea);
    }
}