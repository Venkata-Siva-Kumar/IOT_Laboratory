import RPi.GPIO as GPIO
import time

ir_sensor = 17
led = 23
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BOARD)
GPIO.setup(ir_sensor, GPIO.IN)   # IR sensor input
GPIO.setup(led, GPIO.OUT, initial = 0)  # LED output


while True:
    inp = GPIO.input(ir_sensor)

    if inp == 0:
        print("No Object Detected", inp)
        GPIO.output(23, GPIO.LOW)   # Turn OFF LED

    else:
        print("Object detected", inp)
        GPIO.output(23, GPIO.HIGH)  # Turn ON LED

    time.sleep(0.1)
