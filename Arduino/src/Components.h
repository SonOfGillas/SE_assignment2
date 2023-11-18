#ifndef _COMPONENTS_
#define _COMPONENTS_

#include <Button.h>
#include <Sonar.h>
#include <LcdScreen.h>
#include <Led.h>
#include <Pir.h>
#include <Servo_motor_impl.h>

#include "model.h"


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