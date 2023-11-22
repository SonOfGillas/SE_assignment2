#ifndef __STATE__
#define __STATE__

#include "States.h"

class State {        
    private:
        bool error = false;
    public:
        /*
        Return the StateName associated to the State
        */
        virtual StateName name() = 0;
        /*
        Check if the current state activities are finished,
        and the state can be changed
        */
        virtual bool goNext() = 0;

        virtual ~State() = default;

        bool hasError(){
            return this->error;
        }
        void setError(){
            this->error = true;
        }
};

#endif
