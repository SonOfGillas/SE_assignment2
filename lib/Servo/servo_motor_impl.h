#ifndef __SERVO_MOTOR_IMPL__
#define __SERVO_MOTOR_IMPL__

#include "servo_motor.h"
#include <Servo.h>

class ServoMotorImpl: public ServoMotor {
    private:
        int pin; 
        Servo motor;

    public:
        ServoMotorImpl(int pin);
        void on();
        void setPosition(int angle);
        void off();
};

#endif
