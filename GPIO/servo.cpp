#include <wiringPi.h>

int main()
{
    wiringPiSetup();
    pinMode(12, PWM_OUTPUT);
    
    for (;;)
    {
        pwmWrite(9, 100);
        delay(200);
        pwmWrite(9, 150);
        delay(200);
        pwmWrite(9, 200);
        delay(200);
    }
    return 0;
}
