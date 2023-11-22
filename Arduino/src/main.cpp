#include <Arduino.h>
#include <Wire.h>
#include <Scheduler.h>
#include <Config.h>
#include "State/State.h"
#include "Components/Components.h"
#include "Tasks/StateManagerTask.h"
#include "Tasks/ConsoleDashboard/ConsoleDashboard.h"
#include "State/StateIdle/StateIdle.h"

Scheduler* sched;
State* state;
Components* components;

void setup() {
    components = new Components();
    sched = new Scheduler();
    sched->init(100); //GCD of all tasks

    state = new StateIdle();
    Task* stateManagerTask = new StateManagerTask(state,components,sched);
    stateManagerTask->init(100);
    sched->addTask(stateManagerTask);

    Task* consoleDashboard = new ConsoleDashboard(state,components->tempSensor);
    consoleDashboard->init(500);
    sched->addTask(consoleDashboard);
}

void loop() {
    sched->schedule();
}
