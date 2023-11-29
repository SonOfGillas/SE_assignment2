#ifndef __STATE_WASHING__
#define __STATE_WASHING__

#include <Scheduler.h>
#include "State/State.h"
#include "State/States.h"
#include "Components/Components.h"
#include "Tasks/LcdCountdown/CountdownListener.h"

class StateWashing: public State, public CountdownListener {
    private:
        Scheduler* scheduler;
        Components* components;
        unsigned long enteredTime;
    public:
        StateWashing(int carWashed, Components* components, Scheduler* scheduler);
        ~StateWashing();
        StateName name();
        unsigned long getRemainingTime(); // return remaining milliseconds
        bool goNext();
};

#endif
