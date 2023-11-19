#ifndef __STATE_WELCOME__
#define __STATE_WELCOME__

#include "Components.h"
#include "../State.h"

class StateWelcome: public State {
    private:
        Components* components;
        long arrivalTime;
    public:
        StateWelcome(Components* components);
        ~StateWelcome();
        StateName name();
        bool goNext();
};

#endif
