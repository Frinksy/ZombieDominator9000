#include "motor.hpp"
#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
// to compile: c++ <name> -o <output> -lwiringPi -lpthread

Motor::Motor(int p1, int p2)
{
    wiringPiSetup();
    softPwmCreate(p1, 0, 100);
    softPwmCreate(p2, 0, 100);
    pin1 = p1;
    pin2 = p2;
    speed = 0;
}

void Motor::Stop()
{
    softPwmStop(pin1);
    softPwmStop(pin2);
}

void Motor::setSpeed(int new_speed = 100)
{
    if (speed > 100 || speed < -100) return;
    
    if (speed > 0)
    {
        softPwmWrite(pin1, speed);
        softPwmStop(pin2);
    }
    else if (speed < 0)
    {
        softPwmStop(pin1);
        softPwmWrite(pin2, -1*speed);
    }
    else if (speed == 0)
    {
        Motor::Stop();
    }
    speed = new_speed;
}

int Motor::getSpeed()
{
    return speed;
}
