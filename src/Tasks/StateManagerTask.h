#ifndef __STATE_MANAGER_TASK__
#define __STATE_MANAGER_TASK__

#include <Task.h>

class StateManagerTask : public Task {
    protected:
        State* state;
    public:
        StateManagerTask(State* initalState);
        void init(int period);
        void tick();
};


#endif