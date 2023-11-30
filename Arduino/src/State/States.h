#ifndef __STATES__
#define __STATES__

#include "Arduino.h"

enum StateName { Initial, Error, Idle, Welcome, EnteringWashingArea, ReadyToWash,
                 Washing, ExitingWashingArea };

String getStateNameString(StateName stateName);

#endif
