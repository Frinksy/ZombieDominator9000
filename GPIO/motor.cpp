#include <wiringPi.h>
#include <softPwm.h>
// to compile: c++ <name> -o <output> -lwiringPi -lpthread


void Speed(int speed = 100, int pin1 = 35, int pin2 = 38)
{
    if (speed > 100 || speed < -100) return;
    
    pinMode(pin1, PWM_OUTPUT);
    pinMode(pin2, PWM_OUTPUT);

    if (speed > 0)
    {
        softPwmCreate(pin1, speed, 100);
        softPwmStop(pin2);
    }
    else if (speed < 0)
    {
        pwmWrite(pin1, 0);
        pwmWrite(pin2, -1*speed);
    }
    else if (speed == 0)
    {
        pwmWrite(pin1, 0);
        pwmWrite(pin2, 0);
    }
}

void Stop(int pin1 = 35, int pin2 = 38)
{
    pwmWrite(pin1, 0);
    pwmWrite(pin2, 0);
}


int main()
{
    wiringPiSetupPhys();
    //motor One: 35, 38
    //motor Two: 40, 38
    
    Speed(100, 35, 38); 

    delay(100);

    return 0;
}
