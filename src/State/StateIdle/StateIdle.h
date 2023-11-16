#ifndef __STATE_IDLE__
#define __STATE_IDLE__

#include <MovementDetector.h>
#include "../State.h"

class StateIdle: public State {
    public:
        StateIdle();
        bool goNext();
};

#endif
