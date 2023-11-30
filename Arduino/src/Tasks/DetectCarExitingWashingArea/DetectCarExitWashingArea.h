#ifndef __TASK_DETECT_CAR_EXIT_WASHING_AREA__
#define __TASK_DETECT_CAR_EXIT_WASHING_AREA__

#include <Task.h>
#include <Sonar.h>
#include "CarExitedWashingAreaListener.h"

class DetectCarExitWashingArea : public Task {
    private:
        Sonar* sonar;
        CarExitedWashingAreaListener* listener;
    public:
        DetectCarExitWashingArea(Sonar* sonar, CarExitedWashingAreaListener* listener);
        void init(int period);
        void tick();
};

#endif
