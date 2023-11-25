#ifndef __TASK_DIAGNOSTIC__
#define __TASK_DIAGNOSTIC__

#include <TemperatureDetector.h>
#include "Task.h"
#include "State/State.h"

class Diagnostic: public Task {
    private:
        State* state;
        TemperatureDetector* temperatureDetector;
        bool isMaxTempDetected;
        long maxTempDetectedTime;
    public:
        Diagnostic(State* state, TemperatureDetector* temperatureDetector);  
        void init(int period);  
        void tick();
};

#endif