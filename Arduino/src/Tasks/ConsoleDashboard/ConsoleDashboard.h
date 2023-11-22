#ifndef __TASK_CONSOLE_DASHBOARD__
#define __TASK_CONSOLE_DASHBOARD__

#include <TemperatureDetector.h>
#include "Task.h"
#include "State/State.h"

class ConsoleDashboard: public Task {
    private:
        State* state;
        TemperatureDetector* temperatureDetector;
        bool isMaxTempDetected;
        long maxTempDetectedTime;
    public:
        ConsoleDashboard(State* state, TemperatureDetector* temperatureDetector);  
        void init(int period);  
        void tick();
};

#endif