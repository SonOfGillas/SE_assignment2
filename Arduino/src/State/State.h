#ifndef __STATE__
#define __STATE__

#include "../model.h"

class State {
    public:
        StateName name;
        /*
        Check if the current state activities are finished,
        and the state can be changed
        */
        virtual bool goNext(); 
};

#endif