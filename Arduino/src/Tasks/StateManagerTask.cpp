#include <Arduino.h>
#include <Scheduler.h>
#include "State/State.h"
#include "StateManagerTask.h"
#include "State/StateIdle/StateIdle.h"
#include "State/StateWelcome/StateWelcome.h"
#include "State/StateEnteringWashingArea/StateEnteringWashingArea.h"
#include "State/StateError/StateError.h"
#include "State/StateReadyToWash/StateReadyToWash.h"
#include "State/StateManager.h"

StateManagerTask::StateManagerTask(StateManager* stateManager) {
    this->stateManager = stateManager; 
}

void StateManagerTask::init(int period) {
    Task::init(period);
}

void StateManagerTask::tick() {
    this->stateManager->switchState();
}
