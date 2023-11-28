#ifndef __STATE_IDLE__
#define __STATE_IDLE__

#include <Scheduler.h>
#include "../State.h"

extern bool isWakeup;

class StateIdle: public State {
    private:
        static void wakeup() {
            isWakeup = true;
        };
        Scheduler* scheduler;
    public:
        StateIdle(int carWashed, Scheduler* scheduler);
        ~StateIdle();
        StateName name();
        bool goNext();
};

#endif
