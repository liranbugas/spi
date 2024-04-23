/*
 * spi.c
 *
 *  Created on: Apr 11, 2024
 *      Author: liran
 */

#include "spi.h"
static uint32_t* Spi_Cr_1 = (uint32_t*)(SPI1 + SPI1_CR1);
static uint32_t* Spi_Sr = (uint32_t*)(SPI1 + SPI1_SR);
static uint32_t* Spi_Dr = (uint32_t*)(SPI1 + SPI1_DR);
void Spi_ini()
//initialize the spi
{
	//cpol= 1 cpha= 1
	*Spi_Cr_1 |=(1<<1);
	*Spi_Cr_1 |=(1<<0);
	//master mode
	*Spi_Cr_1 |=(1<<2);
	//1 MHZ clock
	*Spi_Cr_1 |=(3<<3);
	//msb first
	*Spi_Cr_1 &=~(1<<7);
	//SSM=1, SSi=1 -> Software Slave Management
	*Spi_Cr_1 |=(3<<8);
	//full duplex
	*Spi_Cr_1 &=~(1<<10);
	//8 bit data
	*Spi_Cr_1 &=~(1<<11);
	//

}
void Spi_transmit()
//send data to slave
{
	//wait that txe bit is set and send 1 bit each bit
		while(!((*Spi_Sr)&(1<<1))){}
		*Spi_Dr =1;
	// wait for TXE bit to set
	while (!((*Spi_Sr)&(1<<1))) {};
	// wait for BSY bit to Reset that indicates spi is free
	while (((*Spi_Sr)&(1<<7))) {};

	//  Clear the Overrun flag by reading DR and SR
	uint8_t temp = *Spi_Dr;
	temp = *Spi_Sr;


}
void Spi_recieve()
//gets from slave data and recieve after sending 1 dummy byte
{
	uint8_t temp =0 ;
		//wait for busy key to reset
		while(((*Spi_Sr)&(1<<7))){};
		//send dummy data
		*Spi_Dr =1;
		//rxne is set and recieve sends data
		while(!((*Spi_Sr)&(1<<0))){};
		temp=*Spi_Dr ;


}
void Spi_En()
//enable spi
{
	*Spi_Cr_1|=(1<<6);
}
