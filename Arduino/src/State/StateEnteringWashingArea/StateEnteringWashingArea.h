#ifndef __STATE_ENTER_WASHING_AREA__
#define __STATE_ENTER_WASHING_AREA__

#include <Scheduler.h>
#include "State/State.h"
#include "Components/Components.h"

class StateEnteringWashingArea: public State {
    private:
        Components* components;
        Scheduler* scheduler;
        bool isCarInWashingArea;
        long enteredTime;
    public:
        StateEnteringWashingArea(Components* components, Scheduler* scheduler);
        ~StateEnteringWashingArea();
        StateName name();
        bool goNext();
        void setCarInWashingArea(bool isCarInWashingArea);
};

#endif
