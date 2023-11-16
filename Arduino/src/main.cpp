#include <Arduino.h>
#include <Wire.h>
#include <Scheduler.h>
#include "State/State.h"

Scheduler sched;
State state;

void setup() {
  sched.init(50);

  /*
  Task* t0 = new BlinkTask(2);
  t0->init(500);
  sched.addTask(t0);
  */
}

void loop() {
 sched.schedule();
}

