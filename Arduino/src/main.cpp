// AUTHORS:
// Riccardo Gardenghi 0000970796
// Lorenzo Debertolis 0001091222

#include <Arduino.h>
#include <Wire.h>
#include <Scheduler.h>
#include <Config.h>
#include "State/StateManager.h"
#include "Components/Components.h"
#include "Tasks/Diagnostic/Diagnostic.h"
#include "State/StateIdle/StateIdle.h"
#include "MsgService.h"
#include "Tasks/Sleep/Sleep.h"
#include "Tasks/StateManagerTask.h"
#include "State/StateError/StateError.h"

Scheduler* sched;
Components* components;
StateManager* stateManager;

void setup() {
    MsgService.init();
    components = new Components();
    sched = new Scheduler();
    sched->init(100); //GCD of all tasks

    stateManager = new StateManager(components,sched);

    Task* stateManagerTask = new StateManagerTask(stateManager);
    stateManagerTask->init(100);
    sched->addTask(stateManagerTask);

    Task* diagnosticTask = new Diagnostic(stateManager, components->getTempSensor());
    diagnosticTask->init(200);
    sched->addTask(diagnosticTask);
}

void loop() {
   sched->schedule();
}
