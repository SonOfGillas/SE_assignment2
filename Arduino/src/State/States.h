#ifndef __STATES__
#define __STATES__

#include "Arduino.h"

enum StateName { Error, Idle, Welcome, EnteringWashingArea, CarExited };

String getStateNameString(StateName stateName);

#endif
