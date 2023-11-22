#ifndef __TASK_BLINK_LED__
#define __TASK_BLINK_LED__

#include "Task.h"
#include "Light.h"

class BlinkLed: public Task {
  Light* led;
  enum { ON, OFF } state;

public:
  BlinkLed(Light* led);  
  void init(int period);  
  void tick();
};

#endif

