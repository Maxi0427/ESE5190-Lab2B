We connect the circuit back to lab1, and the logic now is the LED would blink according to the sensor's sensing light. 
So according to the I2C data sheet, the data is at the end of the protocal. 

<img width="957" alt="image" src="https://user-images.githubusercontent.com/58932929/200008448-50b91f96-16cd-4794-b553-9999c0ae02cc.png">

So when we change the light brightness, we got the following screenshot:

The dark one
![image](https://user-images.githubusercontent.com/58932929/200009237-5c28613a-5884-461e-acc0-b605a3142833.png)

the more bright one

![image](https://user-images.githubusercontent.com/58932929/200009548-63c6d205-f43e-439f-ac5c-c171d181b02f.png)

So we can see the last several bits are very obvious on showing is the data showing or not. 
