#ifndef __STATE_IDLE__
#define __STATE_IDLE__

#include <Scheduler.h>
#include "../State.h"

class StateIdle: public State {
    private:
        static void wakeup() {};
        Scheduler* scheduler;
    public:
        StateIdle(int carWashed, Scheduler* scheduler);
        ~StateIdle();
        StateName name();
        bool goNext();
};

#endif
