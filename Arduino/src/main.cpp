#include <Arduino.h>
#include <Wire.h>
#include <Scheduler.h>
#include <Config.h>
#include "State/State.h"
#include "Components/Components.h"
#include "Tasks/StateManagerTask.h"
#include "Tasks/Diagnostic/Diagnostic.h"
#include "State/StateIdle/StateIdle.h"
#include "MsgService.h"

Scheduler* sched;
State* state;
Components* components;

void setup() {
    MsgService.init();
    components = new Components();
    sched = new Scheduler();
    sched->init(100); //GCD of all tasks
    state = new StateIdle(0,sched);
    
    Task* stateManagerTask = new StateManagerTask(state,components,sched);
    stateManagerTask->init(100);
    sched->addTask(stateManagerTask);

    Task* diagnosticTask = new Diagnostic(state,components->tempSensor);
    diagnosticTask->init(500);
    sched->addTask(diagnosticTask);
}

void loop() {
   sched->schedule();
}
