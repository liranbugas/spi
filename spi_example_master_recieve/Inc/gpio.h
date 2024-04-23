/*
 * gpio.h
 *
 *  Created on: Apr 11, 2024
 *      Author: liran
 */

#ifndef GPIO_H_
#define GPIO_H_

#define RCC 0x40023800
#define GPIO_B 0x40020400
#define RCC_AHB 0x30
#define RCC_APB2 0x44
#define GPIO_ALTFL 0x20
#define GPIO_PULLDOWN 0x0C
#define GPIO_OUTYPE 0x04
#define GPIO_OUT 0x14
#include <stdint.h>
void gpio_ini();
void gpio_out(int);
#endif /* GPIO_H_ */
