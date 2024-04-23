/*
 * gpio.c
 *
 *  Created on: Apr 11, 2024
 *      Author: liran
 */
#include "gpio.h"
static uint32_t* pRcc_Ahb_En = (uint32_t*)(RCC + RCC_AHB);
static uint32_t* pGpioB_Cr = (uint32_t*)(GPIO_B);
static uint32_t* pRcc_Apb2_En = (uint32_t*)(RCC +RCC_APB2);
static uint32_t* pGpio_B_Altf_L= (uint32_t*)(GPIO_B + GPIO_ALTFL);
static uint32_t* pGpio_B_Outype= (uint32_t*)(GPIO_B + GPIO_OUTYPE);
static uint32_t* pGpio_B_Pull_UpDown= (uint32_t*)(GPIO_B + GPIO_PULLDOWN);
static uint32_t* pGpio_B_Out =(uint32_t*)(GPIO_B + GPIO_OUT);
void gpio_ini()
//Initialize the pin b3 as clock, b4 as miso, b5 as mosi, b6 as output
//alf5
//slave select pin is low when choose him
{
	 *pRcc_Ahb_En |= (1<<1);
	 *pRcc_Apb2_En |=(1<<12);
	 //to alternate function and pin 6 as output
	 *pGpioB_Cr &=0x00000000;
	 *pGpioB_Cr |=(1<<7);
	 *pGpioB_Cr |=(1<<9);
	 *pGpioB_Cr |=(1<<11);
	 *pGpioB_Cr |=(1<<12);
	 //open drain
	 *pGpio_B_Outype|=(0x3<<3);
	 *pGpio_B_Outype|=(1<<5);
	 *pGpio_B_Outype|=(1<<6);
	 //pull up
	 *pGpio_B_Pull_UpDown&=0x00000000;
	 *pGpio_B_Pull_UpDown|=(1<<7);
	 *pGpio_B_Pull_UpDown|=(1<<9);
	 *pGpio_B_Pull_UpDown|=(1<<11);
	 *pGpio_B_Pull_UpDown|=(1<<13);
	 //alternate function state 5 for spi
	 *pGpio_B_Altf_L|=(5<<12);
	 *pGpio_B_Altf_L|=(5<<16);
	 *pGpio_B_Altf_L|=(5<<20);
	 //pin 6 as output and 0
	 //*pGpio_B_Out&=~(1<<6);
}

void gpio_out(int updown)
//choose high or low
{
	if(updown)
	{
		*pGpio_B_Out|=(1<<6);
	}
	else
	{
		*pGpio_B_Out&=~(1<<6);
	}
}

