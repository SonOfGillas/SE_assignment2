#include "Scheduler.h"

class Scheduler {
    public:
        void init(int basePeriod) {
            this->basePeriod = basePeriod;
            timer.setupPeriod(basePeriod);
            nTasks = 0;
        }

        bool addTask(Task* task) {
            if (nTasks < MAX_TASKS-1) {
                taskList[nTasks] = task;
                nTasks++;
                return true;
            } else {
                return false;
            }
        }

        void schedule() {
            timer.waitForNextTick();
            for (int i = 0; i < nTasks; i++) {
                if (taskList[i]->updateAndCheckTime(basePeriod)){
                    taskList[i]->tick();
                }
            }
        }
}
