#ifndef _COMPONENTS_
#define _COMPONENTS_

#include <ButtonImpl.h>
#include <Sonar.h>
#include <LcdScreen.h>
#include <Led.h>
#include <Pir.h>
#include <servo_motor_impl.h>
#include <AnalogTempSensor.h>

class Components {
    private:
        Led* l1;
        Led* l2;
        Led* l3; 
        ButtonImpl* startButton;
        Sonar* carDistanceDetector;
        ServoMotorImpl* gate;
        LcdScreen* userLcd;
        Pir* carPresenceDetector;
        AnalogTempSensor* tempSensor;
    public:
        Components();
        Led* getL1();
        Led* getL2();
        Led* getL3();
        ButtonImpl* getStartButton();
        Sonar* getCarDistanceDetector();
        ServoMotorImpl* getGate();
        LcdScreen* getUserLcd();
        Pir* getCarOresenceDetector();
        AnalogTempSensor* getTempSensor();
};

#endif