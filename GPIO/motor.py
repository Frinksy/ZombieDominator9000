#!/usr/bin/env python3
import RPi.GPIO as GPIO
import time

GPIO.setmode(GPIO.BOARD)
GPIO.setup(35, GPIO.OUT)
GPIO.setup(38, GPIO.OUT)

fMot = GPIO.PWM(35, 100)
bMot = GPIO.PWM(38, 100)

fMot.start(100)
time.sleep(2)

fMot.stop()
bMot.start(100)
time.sleep(2)

fMot.stop()
bMot.stop()
GPIO.cleanup()
