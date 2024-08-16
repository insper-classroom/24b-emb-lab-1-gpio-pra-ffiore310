/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int LED_PRIN = 27;
const int LED_MOTOR1 = 28;
const int LED_MOTOR2 = 19;
const int LED_MOTOR3 = 21;
const int LED_MOTOR4 = 16;
const int BTN = 3;


int main() {
    stdio_init_all();

    int c = 0;

    gpio_init(LED_PRIN);
    gpio_init(LED_MOTOR1);
    gpio_init(LED_MOTOR2);
    gpio_init(LED_MOTOR3);
    gpio_init(LED_MOTOR4);
    gpio_init(BTN);

    gpio_set_dir(LED_PRIN, GPIO_OUT);
    gpio_set_dir(LED_MOTOR1, GPIO_OUT);
    gpio_set_dir(LED_MOTOR2, GPIO_OUT);
    gpio_set_dir(LED_MOTOR3, GPIO_OUT);
    gpio_set_dir(LED_MOTOR4, GPIO_OUT);
    gpio_set_dir(BTN, GPIO_IN);
    gpio_pull_up(BTN);

    while (true) {
        if(!gpio_get(BTN)){
            gpio_put(LED_PRIN, 1);
            while(c<515){
                gpio_put(LED_MOTOR1, 1);
                sleep_ms(10);
                gpio_put(LED_MOTOR1, 0);
                sleep_ms(10);
                gpio_put(LED_MOTOR2, 1);
                sleep_ms(10);
                gpio_put(LED_MOTOR2, 0);
                sleep_ms(10);
                gpio_put(LED_MOTOR3, 1);
                sleep_ms(10);
                gpio_put(LED_MOTOR3, 0);
                sleep_ms(10);
                gpio_put(LED_MOTOR4, 1);
                sleep_ms(10);
                gpio_put(LED_MOTOR4, 0);
                sleep_ms(10);
                c++;
                while (!gpio_get(BTN)) {
                };
            }
        }
            sleep_ms(100);
    }
}   
