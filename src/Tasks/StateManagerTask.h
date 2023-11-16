#ifndef __STATE_MANAGER_TASK__
#define __STATE_MANAGER_TASK__

#include <Task.h>

class StateManagerTask : public Task {
    public:
        StateManagerTask(int pin, int priority);
        void init(int period);
        void tick();
};


#endif