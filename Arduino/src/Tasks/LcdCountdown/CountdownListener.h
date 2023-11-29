#ifndef __COUNTDOWN_LISTENER__
#define __COUNTDOWN_LISTENER__

class CountdownListener {
    public:
        virtual unsigned long getRemainingTime() = 0; // return remaining milliseconds
};

#endif
