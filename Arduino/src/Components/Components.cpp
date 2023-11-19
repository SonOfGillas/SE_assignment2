#include "Arduino.h"
#include "Components.h"

#include <Config.h>
#include <ButtonImpl.h>
#include <Sonar.h>
#include <LcdScreen.h>
#include <Led.h>
#include <Pir.h>
#include <servo_motor_impl.h>

Components::Components() {
    this->l1 = new Led(PIN_L1);
    this->l2 = new Led(PIN_L2);
    this->l3 = new Led(PIN_L3);
    this->startButton = new ButtonImpl(PIN_BUTTON);
    this->carDistanceDetector = new Sonar(PIN_SONAR_TRIG, PIN_SONAR_ECHO);
    this->gate = new ServoMotorImpl(PIN_SERVO);
    this->userLcd = new LcdScreen();
    this->carPresenceDetector = new Pir(PIN_PIR);   

    while (this->carPresenceDetector->isCalibrationFinished() == false){};
}