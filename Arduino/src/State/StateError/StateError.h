#ifndef __STATE_ERROR__
#define __STATE_ERROR__

#include "State/State.h"

class StateError: public State {
    private:
        bool maintenanceDone;
    public:
        StateError(StateName previousStateName);
        StateName name();
        bool goNext();
        void setMaintenanceDone();
        StateName previousStateName;
};

#endif