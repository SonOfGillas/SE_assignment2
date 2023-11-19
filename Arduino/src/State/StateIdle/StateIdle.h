#ifndef __STATE_IDLE__
#define __STATE_IDLE__

#include "../State.h"

class StateIdle: public State {
    private:
        static void wakeup() {};
    public:
        StateIdle();
        ~StateIdle();
        StateName name();
        bool goNext();
};

#endif
