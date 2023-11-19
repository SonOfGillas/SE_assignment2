#ifndef _MODEL_
#define _MODEL_

#define PIN_PIR 2
#define PIN_L1 3
#define PIN_L2 4
#define PIN_L3 5
#define PIN_BUTTON 6
#define PIN_SONAR_TRIG 7
#define PIN_SONAR_ECHO 8
#define PIN_SERVO 9

#define N1 5 //seconds in the waiting area


enum StateName { Idle, Welcome, CarExited };

#endif