#!/usr/bin/env python3
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(12, GPIO.OUT)

freq = 50
pwm = GPIO.PWM(12, freq)


msPerCycle = 1000/freq
posList = [1, 1.5, 2]

while True:
    for pos in posList:
        pwm.start((pos / msPerCycle)*100)
        time.sleep(0.5)

pwm.stop()
GPIO.cleanup()
