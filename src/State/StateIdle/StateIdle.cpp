#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include "model.h"
#include "StateIdle.h"

StateIdle::StateIdle() {
    this->name = StateName::Idle;
    enableInterrupt(PIN_PIR, wakeup, FALLING);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();
}

bool StateIdle::goNext(){
    return true;
}

static void wakeup(){}