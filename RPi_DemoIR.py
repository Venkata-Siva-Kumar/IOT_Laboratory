import RPi.GPIO as GPIO
import time

led = 5
sensor = 10

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)

GPIO.setup(sensor, GPIO.IN)
GPIO.setup(led, GPIO.OUT)

while True:

    if GPIO.input(sensor):
        GPIO.output(led, False)
        print("Object Not Detected")
        print("LED is OFF")

    else:
        GPIO.output(led, True)
        print("Object Detected")
        print("LED is ON")

    time.sleep(1)