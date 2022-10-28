/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "ws2812.h"
int str_eq(const char *s1, const char *s2){
      while(true){
              /*
               * At end of string return 0.
               */
              if (*s1 == 0 && *s2 == 0){
                return (1);
              }
              else if(*s1 == 0||*s2 == 0)
                      return(0);
              if (*s1==*s2)
                {s1++; s2++;}
              else{
                return (0);
              }

      }
      
      /* Difference detected! */
      return(0);
}
int main() {
    rp_init();
    turn_on_pixelpower();
    
    const uint LED_PIN = 22;
    const uint LED_PIN2 = 23;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    gpio_init(LED_PIN2);
    gpio_set_dir(LED_PIN2, GPIO_OUT);
    int start=0;
    char c = getchar();

    if (c==0x0D){
        start=1;
    }
    while(start==1){

    char line[11];
    uint idx = 0;
    printf("\n");
    printf("input: ");
    while (true) {
        char c = getchar();
        if (c == 0x0D) {
            line[idx] = 0;
            printf("\n");
            break;
        }
        if ((c >= 0x20) && (c <= 0x7E)) {
            printf("%c", c);
            if (idx < 10) {
                line[idx++] = c;
            }
        }
    }
    
    char pass[11]="ese519";
    if (str_eq(line,pass)==1)
    {
        printf("pass :) \n");
        gpio_put(LED_PIN, 1);
        gpio_put(LED_PIN2, 0);
        sleep_ms(2500);

    }
    else{
        printf("get out!!\n");
        gpio_put(LED_PIN2, 1);
        gpio_put(LED_PIN, 0);
        sleep_ms(2500);
    }
    

    }
    
    // while (true) {
    //     printf("White Light Open\n");
    //     set_neopixel_color(0x00ffffff);
    //     sleep_ms(1000);
    //     printf("Red Light Open\n");
    //     set_neopixel_color(0x00ff0000);
    //     sleep_ms(1000);
    //     printf("Green Light Open\n");
    //     set_neopixel_color(0x0000ff00);
    //     sleep_ms(1000);
    //     printf("Blue Light Open\n");
    //     set_neopixel_color(0x000000ff);
    //     sleep_ms(1000);
    // }
    return 0;
}
