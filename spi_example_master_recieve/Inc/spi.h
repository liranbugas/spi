/*
 * spi.h
 *
 *  Created on: Apr 11, 2024
 *      Author: liran
 */

#ifndef SPI_H_
#define SPI_H_

#define SPI1 	 0x40013000
#define SPI1_CR1 0x00
#define SPI1_SR  0x08
#define SPI1_DR  0x0C
void Spi_ini();
void Spi_transmit();
void Spi_recieve();
void Spi_En();
#include <stdint.h>

#endif /* SPI_H_ */
