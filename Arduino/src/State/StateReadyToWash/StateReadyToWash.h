#ifndef __STATE_READY_TO_WASH__
#define __STATE_READY_TO_WASH__

#include <Scheduler.h>
#include "State/State.h"
#include "Components/Components.h"
#include "Tasks/WatchButton/WatchButton.h"
#include "Tasks/WatchButton/ButtonListener.h"

class StateReadyToWash: public State, public ButtonListener {
    private:
        Components* components;
        Scheduler* scheduler;
        bool isButtonPressed;
    public:
        StateReadyToWash(int carWashed, Components* components, Scheduler* scheduler);
        ~StateReadyToWash();
        StateName name();
        void buttonPressed(bool isButtonPressed);
        bool goNext();
};

#endif
