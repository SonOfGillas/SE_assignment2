#ifndef __TASK_EXT__
#define __TASK_EXT__

#include <Task.h>
#include "States.h"

class TaskExt: public Task {
    public:
        virtual StateName name() = 0;
        virtual bool goNext() = 0;
}

#endif
