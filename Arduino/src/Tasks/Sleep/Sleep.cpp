#include <Arduino.h>
#include <Config.h>
#include <avr/sleep.h>
#include "Sleep.h"

Sleep::Sleep(){}

void Sleep::init(int period){
    Task::init(period);
}

void Sleep::tick(){
    set_sleep_mode(SLEEP_MODE_PWR_DOWN);
    sleep_mode();
}