#include <wiringPi.h>
#include <softPwm.h>
#include <iostream>
// to compile: c++ <name> -o <output> -lwiringPi -lpthread


void Stop(int pin1 = 35, int pin2 = 38)
{
    softPwmStop(pin1);
    softPwmStop(pin2);
}


void Speed(int speed = 100, int pin1 = 24, int pin2 = 28)
{
    if (speed > 100 || speed < -100) return;
    
    //pinMode(pin1, PWM_OUTPUT);
    //pinMode(pin2, PWM_OUTPUT);
    softPwmCreate(pin1, speed, 100);
    softPwmCreate(pin2, speed, 100);

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
        Stop(pin1, pin2);
    }
}

int main()
{
    wiringPiSetup();
    //motor One phys: 35, 38    wiringPi: 24, 28
    //motor Two: 40, 37         wiringPi: 29, 25
    std::cout << "Starting motor\n";
    Speed(100, 24, 28); 
    
    delay(1000);
    std::cout << "Finishing\n";
    Stop(24, 28);
    return 0;
}
