#ifndef __STATE_WASHING__
#define __STATE_WASHING__

class StateWashing: public State {
    private:
        int enteredTime;
    public:
        StateWashing();
        ~StateWashing();
        StateName name();
        bool goNext();
}

#endif
