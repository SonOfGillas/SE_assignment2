#ifndef __STATE_READY_TO_WASH__
#define __STATE_READY_TO_WASH__

#include <Scheduler.h>
#include "State/State.h"
#include "Components/Components.h"
#include "EnableInterruptLib.h"

extern bool isButtonPressed;

class StateReadyToWash: public State {
    private:
        Components* components;
        Scheduler* scheduler;
        static void buttonPressed(){
            isButtonPressed = true;
        };
    public:
        StateReadyToWash(int carWashed, Components* components, Scheduler* scheduler);
        ~StateReadyToWash();
        StateName name();
        bool goNext();
};

#endif
