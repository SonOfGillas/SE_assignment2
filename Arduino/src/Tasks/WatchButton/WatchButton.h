#ifndef __TASK_WATCH_BUTTON__
#define __TASK_WATCH_BUTTON__

#include "Task.h"
#include "State/State.h"
#include <Components/Components.h>
#include <Button.h>
#include "ButtonListener.h"


class WatchButton: public Task {
    private:
        Button* button;
        ButtonListener* listener;
        bool isButtonPressed; // store if the button was/is pressed
    public:
        WatchButton(Components* components, ButtonListener* listener);  
        void init(int period);  
        void tick();
};

#endif
