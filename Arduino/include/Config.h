#ifndef __CONFIG__
#define __CONFIG__

#define PIN_PIR 2
#define PIN_L1 8
#define PIN_L2 9
#define PIN_L3 13
#define PIN_BUTTON 6
#define PIN_SONAR_TRIG 4
#define PIN_SONAR_ECHO 3
#define PIN_SERVO 5
#define PIN_TEMP_SENSOR A0

#define N1 5    //seconds in the check-in area
#define N2 5    //seconds in the washing area
#define N3 10   //washing time in seconds
#define N4 5    //seconds before the gate closes after the car has left the washing area
#define N5 5    //seconds in the check-out area

#define MINDIST 0.10  //minimum distance(Meter) to detect a car in the washing area
#define MAXDIST 4  //maximum distance (meter) to detect a car
#define MAXTEMP 30 //maximum temperature(Celsius) of the washing area

#define GATE_OPEN 180
#define GATE_CLOSED 0

#endif
