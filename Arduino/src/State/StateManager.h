#ifndef __STATE_MANAGER__
#define __STATE_MANAGER__

#include "Arduino.h"
#include "State.h"
#include "Scheduler.h"
#include "Components/Components.h"

class StateManager
{
private:
    Scheduler* scheduler;
    State* state;
    Components* components;
    State* stateFactory(StateName stateName);
public:
    StateManager(Components* components, Scheduler* scheduler);
    void switchState();
    void setError(bool error);
    StateName getCurrentState();
    int getCarWashed();
};

#endif