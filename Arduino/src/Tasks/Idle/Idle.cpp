#include "Idle.h"
#include <Config.h>
#include <avr/sleep.h>
#include <EnableInterrupt.h>

TaskIdle::TaskIdle() {
    isWakeUp = false;
    enableInterrupt(PIN_PIR, this->wakeup, RISING);
}

void TaskIdle::tick() {
    if(!isWakeUp) {
        set_sleep_mode(SLEEP_MODE_PWR_DOWN);
        sleep_mode();
    }
}

bool TaskIdle::goNext() {
    return isWakeUp;
}

TaskIdle::~TaskIdle() {
    disableInterrupt(PIN_PIR);
}
