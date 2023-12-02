#ifndef __STATE_ENTER_WASHING_AREA__
#define __STATE_ENTER_WASHING_AREA__

#include <Scheduler.h>
#include "State/State.h"
#include "Components/Components.h"
#include "Tasks/DetectCarInWashingArea/CarInWashingAreaListener.h"
class StateEnteringWashingArea: public State, public CarInWashingAreaListener {
    private:
        Components* components;
        Scheduler* scheduler;
        bool isCarInWashingArea;
        long lastTimeCarDetectedOutside;
    public:
        StateEnteringWashingArea(int carWashed, Components* components, Scheduler* scheduler);
        ~StateEnteringWashingArea();
        StateName name();
        bool goNext();
        void carInWashingArea(bool isCarInWashingArea);
};

#endif
