#ifndef __SCHEDULER__
#define __SCHEDULER__

#include "Timer.h"
#include "Task.h"

#define MAX_TASKS 10

class Scheduler {
    private:
        int basePeriod;
        Task* taskList[MAX_TASKS];
        Timer timer;
    public:
        int nTasks;
        void init(int basePeriod);
        virtual bool addTask(Task* task);
        virtual void schedule();
        bool removeLastTask();
};

#endif
