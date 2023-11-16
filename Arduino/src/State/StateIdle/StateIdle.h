#ifndef __STATE_IDLE__
#define __STATE_IDLE__

#include <MovementDetector.h>
#include "../State.h"

class StateIdle: public State {
    private:
        static void wakeup(){};
    public:
        StateIdle();
        bool goNext();
};

#endif
