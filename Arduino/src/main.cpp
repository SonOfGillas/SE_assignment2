#include <Arduino.h>
#include <Wire.h>
#include <Scheduler.h>
#include <Config.h>
#include "State/State.h"
#include "Components/Components.h"
#include "Tasks/StateManagerTask.h"
#include "State/StateIdle/StateIdle.h"

Scheduler* sched;
State* state;
Components* components;

void setup() {
    components = new Components();
    sched = new Scheduler();
    sched->init(50);

    /*
    Task* t0 = new BlinkTask(2);
    t0->init(500);
    sched.addTask(t0);
    */

    state = new StateIdle();
    Task* stateManagerTask = new StateManagerTask(state,components);
    stateManagerTask->init(100);
    sched->addTask(stateManagerTask);
}

void loop() {
    sched->schedule();
}
