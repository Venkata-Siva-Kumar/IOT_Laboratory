import RPi.GPIO as GPIO
from time import sleep

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

GPIO.setup(18, GPIO.OUT, initial=GPIO.LOW)

while True:
    GPIO.output(18, GPIO.HIGH)
    print("LED is ON")
    sleep(1)

    GPIO.output(18, GPIO.LOW)
    print("LED is OFF")
    sleep(1)