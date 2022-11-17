#Lab 1 section 3.2

"""
ESE 5190 Lab1 Firefly section 3.2
Navit Gill
"""
import time
import neopixel
import board
import busio
import adafruit_apds9960.apds9960
i2c = busio.I2C(board.SCL1, board.SDA1)
sensor = adafruit_apds9960.apds9960.APDS9960(i2c)


sensor.enable_proximity = True
sensor.enable_gesture = True
sensor.enable_color = True
# Uncomment and set the rotation if depending on how your sensor is mounted.
# apds.rotation = 270 # 270 for CLUE
sensor.color_integration_time 
cit = sensor.color_integration_time = 10
print (cit)

pixels = neopixel.NeoPixel(board.NEOPIXEL, 1)

while sensor.enable_color == True:
    r, g, b, c = sensor.color_data
    print('Red: {0}, Green: {1}, Blue: {2}, Clear: {3}'.format(r, g, b, c))
    if c > 100:
        ledBrightness = 255
    else:
        ledBrightness = 5
    pixels.fill((ledBrightness, 0, 0))
