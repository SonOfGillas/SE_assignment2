#ifndef __TASK_LCD_COUNTDOWN__
#define __TASK_LCD_COUNTDOWN__

#include "Task.h"
#include <LcdScreen.h>
#include "CountdownListener.h"

class LcdCountdown: public Task {
    private:
        LcdScreen* lcd;
        CountdownListener* handler;
    public:
        LcdCountdown(LcdScreen* lcd, CountdownListener* handler);
        void tick();
};

#endif

