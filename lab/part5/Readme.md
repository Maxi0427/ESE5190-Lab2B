# i2c_traffic
We connect the circuit back to lab1, and the logic now is the LED would blink according to the sensor's sensing light. 
So according to the I2C data sheet, the data is at the end of the protocal. 

<img width="957" alt="image" src="https://user-images.githubusercontent.com/58932929/200008448-50b91f96-16cd-4794-b553-9999c0ae02cc.png">

## Screenshot & GIF of oscilloscope result
When we change the light brightness, we got the following screenshot:

The dark one
![image](https://github.com/ChiYuan9/ESE5190-Lab2B/blob/main/lab/part5/Dark.jpeg)

the more bright one

![image](https://github.com/ChiYuan9/ESE5190-Lab2B/blob/main/lab/part5/Bright.jpeg)

So we can see the last several bits are very obvious on showing is the data showing or not. 

## Code
    
    import board
    import busio
    import time
    import neopixel
    import adafruit_apds9960.apds9960
    i2c = busio.I2C(board.SCL1, board.SDA1)
    #i2c = board.STEMMA_I2C()
    sensor = adafruit_apds9960.apds9960.APDS9960(i2c)
    sensor.color_integration_time = 50
    sensor.enable_proximity = True
    sensor.enable_color = True
    sensor.enable_gesture = True
    pixels = neopixel.NeoPixel(board.NEOPIXEL, 1)
    cLast = 0
    while True:
        r, g, b, c = sensor.color_data
        if(c >= cLast + 100):
            pixels.fill((255, 255, 255))
        else:
            pixels.fill((0, 0, 0))
        cLast = c
        time.sleep(0.05)


