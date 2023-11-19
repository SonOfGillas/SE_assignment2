#ifndef _COMPONENTS_
#define _COMPONENTS_

#include <ButtonImpl.h>
#include <Sonar.h>
#include <LcdScreen.h>
#include <Led.h>
#include <Pir.h>
#include <servo_motor_impl.h>

class Components {
    public:
        Components();
        Led* l1;
        Led* l2;
        Led* l3; 
        ButtonImpl* startButton;
        Sonar* carDistanceDetector;
        ServoMotorImpl* gate;
        LcdScreen* userLcd;
        Pir* carPresenceDetector;
};

#endif