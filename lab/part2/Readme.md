# REPL
## Code
```
#include "pico/stdlib.h"
#include <stdio.h>
#include "neopixel.h"
#include "hardware/gpio.h"

#define QTPY_BOOT_PIN 21

typedef struct {
    uint32_t last_serial_byte;
    uint32_t button_is_pressed;
    uint32_t light_color;
} Flashlight; 
typedef          uint32_t   VALUE;
typedef volatile uint32_t * ADDRESS;

VALUE register_read(ADDRESS address) {
    return *address;
}

void register_write(ADDRESS address, VALUE value) {
    *address = value;
}
void render_to_console(Flashlight status) {
    // adjust console window height to match 'frame size'
    for (uint8_t i=0; i<10; i++) { 
        printf("\n");
    }
    printf("button_is_pressed:  0x%08x\n",   status.button_is_pressed);
    printf("light_color:        0x%08x\n",   status.light_color);
}  

int main() {
    
    stdio_init_all();
    gpio_init(QTPY_BOOT_PIN);
    gpio_set_dir(QTPY_BOOT_PIN, GPIO_IN);
    neopixel_init();

    Flashlight status;
    status.last_serial_byte =  0x00000000;
    status.button_is_pressed = 0x00000000;
    status.light_color =       0x000000ff;
    while (!stdio_usb_connected());
    uint32_t line;
    volatile uint32_t *boot_pin_address = (ADDRESS) 0xd0000004;  
    while (true) {
       uint32_t line;
       printf("input: ");
       scanf("%x", &line);
       printf("the line %x\n", line);
        boot_pin_address=(volatile uint32_t *)line;
        printf("%x\n",register_read(boot_pin_address));
       register_write(boot_pin_address,register_read(boot_pin_address) + 0x00000008);
       printf("%x\n",register_read(boot_pin_address));

        
    }
    return 0;
}      
```
## Function
1. Select any 32-bit address to read/write (even if not a valid RP2020 address).<br>
2. Read/write any 32-bit value to this address.<br>

## Pictures
![image](https://github.com/ChiYuan9/ESE5190-Lab2B/blob/main/lab/part2/Read_Write.png)
Read and write the register