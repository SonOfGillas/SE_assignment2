#include <Sonar.h>
#include <Config.h>
#include "DetectCarExitWashingArea.h"
#include "CarExitedWashingAreaListener.h"

DetectCarExitWashingArea::DetectCarExitWashingArea(Sonar* sonar, CarExitedWashingAreaListener* listener) {
    this->sonar = sonar;
    this->listener = listener;
}

void DetectCarExitWashingArea::init(int period) {
    Task::init(period);
}

void DetectCarExitWashingArea::tick() {
    this->listener->carExitedWashingArea(this->sonar->getDistance() > MAXDIST);
}
