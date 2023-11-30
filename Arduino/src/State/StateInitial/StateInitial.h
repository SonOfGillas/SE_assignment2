#ifndef __STATE_INITIAL__
#define __STATE_INITIAL__

#include <Scheduler.h>
#include "../State.h"

class StateInitial: public State {
    public:
        StateInitial(int carWashed);
        ~StateInitial();
        StateName name();
        bool goNext();
};

#endif
