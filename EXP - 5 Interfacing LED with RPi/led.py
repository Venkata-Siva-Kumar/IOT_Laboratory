import RPi.GPIO as GPIO
import time

led = 23

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(led, GPIO.OUT)

while True:
    GPIO.output(led, GPIO.HIGH)  # LED ON
    time.sleep(1)

    GPIO.output(led, GPIO.LOW)   # LED OFF
    time.sleep(1)

GPIO.cleanup()