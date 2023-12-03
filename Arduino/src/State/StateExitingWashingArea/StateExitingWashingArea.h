#ifndef __STATE_EXITING_WASHING_AREA__
#define __STATE_EXITING_WASHING_AREA__

#include <Scheduler.h>
#include "State/State.h"
#include "State/States.h"
#include "Components/Components.h"
#include "Tasks/DetectCarExitingWashingArea/CarExitedWashingAreaListener.h"

class StateExitingWashingArea: public State, public CarExitedWashingAreaListener {
    private:
        Scheduler* scheduler;
        Components* components;
        long lastTimeCarDetectedInside;
        bool isCarExited;
    public:
        StateExitingWashingArea(int carWashed, Components* components, Scheduler* scheduler);
        ~StateExitingWashingArea();
        StateName name() const volatile;
        void carExitedWashingArea(bool isCarOutside); // setter of isCarExited
        bool goNext() volatile;
};

#endif
