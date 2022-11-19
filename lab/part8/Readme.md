# APDS_Protocol

## Function
Deployed an I2C protocol between QTPY2040 and APDS9960 using the I2C PIO from the pico-example, and also with reference from TomGoh's repo.<br>
Displayed the proximity and color data collected from APDS9960 on screen.<br>

## Code
### Main Code
https://github.com/ChiYuan9/ESE5190-Lab2B/blob/main/lab/part8/lab2_part8.c
### pio_i2c.c
```
int pio_i2c_write_blocking(PIO pio, uint sm, uint8_t addr, uint8_t *txbuf, uint len, bool nostop) {
    int err = 0;
    pio_i2c_start(pio, sm);
    pio_i2c_rx_enable(pio, sm, false);
    pio_i2c_put16(pio, sm, (addr << 2) | 1u);
    while (len && !pio_i2c_check_error(pio, sm)) {
        if (!pio_sm_is_tx_fifo_full(pio, sm)) {
            --len;
            pio_i2c_put_or_err(pio, sm, (*txbuf++ << PIO_I2C_DATA_LSB) | ((len == 0) << PIO_I2C_FINAL_LSB) | 1u);
        }
    }
    if (!nostop)
        pio_i2c_stop(pio, sm);
    pio_i2c_wait_idle(pio, sm);
    if (pio_i2c_check_error(pio, sm)) {
        err = -1;
        pio_i2c_resume_after_error(pio, sm);
        pio_i2c_stop(pio, sm);
    }
    return err;
}
```
Changed the 'pio_i2c_write_blocking' function

### APDS9960
https://github.com/ChiYuan9/ESE5190-Lab2B/blob/main/lab/part8/APDS9960.c
Add 'APDS9960_init', 'read_proximity' and 'read_rgbc' function to initialize sensor, read proximity data from sensor and read brightness data from sensor.

## Pictures
![image](https://github.com/ChiYuan9/ESE5190-Lab2B/blob/main/lab/part8/part8_far.png)
![image](https://github.com/ChiYuan9/ESE5190-Lab2B/blob/main/lab/part8/part8_close.png)<br>
Proximity = 1 means something is close to sensor.<br>
Proximity = 0 means nothing is close to sensor.<br>
