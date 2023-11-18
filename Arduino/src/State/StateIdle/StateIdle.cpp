#include <EnableInterrupt.h>
#include <avr/sleep.h>
#include "model.h"
#include "StateIdle.h"

StateName StateIdle::name() {
    return StateName::Idle;
}

StateIdle::StateIdle() {
    enableInterrupt(PIN_PIR, this->wakeup, RISING);
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();
}

bool StateIdle::goNext() {
    return true;
}
