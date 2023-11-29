#ifndef __TASK_IDLE__
#define __TASK_IDLE__

#include "Tasks/TaskExt.h"
#include "Tasks/States.h"

extern bool isWakeUp;

class TaskIdle: public TaskExt {
    private:
        static void wakeup() {
            isWakeUp = true;
        }

    public:
        TaskIdle();

        void tick();

        StateName name() {
            return StateName::Idle;
        }

        bool goNext();

        ~TaskIdle();
};

#endif
