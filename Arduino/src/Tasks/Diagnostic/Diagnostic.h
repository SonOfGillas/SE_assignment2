#ifndef __TASK_DIAGNOSTIC__
#define __TASK_DIAGNOSTIC__

#include <TemperatureDetector.h>
#include "Task.h"
#include "State/State.h"
#include "State/StateManager.h"

class Diagnostic: public Task {
    private:
        StateManager* stateManager;
        TemperatureDetector* temperatureDetector;
        bool isMaxTempDetected;
        long maxTempDetectedTime;
    public:
        Diagnostic(StateManager* stateManager, TemperatureDetector* temperatureDetector);  
        void init(int period);  
        void tick();
};

#endif