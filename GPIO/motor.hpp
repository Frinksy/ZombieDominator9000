#ifndef DEF_MOTOR
#define DEF_MOTOR
#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>

class Motor
{
    private:
        int pin1;
        int pin2;
        int speed;

    public:
        Motor(int p1, int p2);
        void Stop();
        int getSpeed();
        void setSpeed(int new_speed);
};

#endif
