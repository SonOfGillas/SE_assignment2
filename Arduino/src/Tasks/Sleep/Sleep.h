#ifndef __TASK_SLEEP__
#define __TASK_SLEEP__

#include "Task.h"
#include "State/State.h"

class Sleep: public Task {
    public:
        Sleep();  
        void init(int period);  
        void tick();
};

#endif