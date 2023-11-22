#ifndef __STATE_MANAGER_TASK__
#define __STATE_MANAGER_TASK__

#include <Scheduler.h>
#include <Task.h>
#include "Components/Components.h"
#include "State/State.h"

class StateManagerTask : public Task {
    protected:
        State* state;
        Components* components;
        Scheduler* scheduler;
    public:
        StateManagerTask(State* initalState,Components* components,Scheduler* scheduler);
        void init(int period);
        void tick();
};


#endif