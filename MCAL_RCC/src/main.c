/*
 * main.c
 *
 *  Created on: Aug 18, 2023
 *      Author: brbar
 */

//LIBS
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//MCAL
#include "RCC_interface.h"

//own driver
#define PORTA_CRL *((volatile u32*)0x40010800)
#define PORTA_ODR *((volatile u32*)0x4001080C)


void main(void)
{	//initialize clock system
	RCC_voidEnableSysClocks();
	RCC_voidInitSysCLock();

	//enable GPIOA(peripheral 2) on APB2 bus
	RCC_voidEnableClock(RCC_APB2,2);

	//configure A0 as output push pull
	PORTA_CRL = 0x00000002;

	//Set A0 output high
	PORTA_ODR = 0x00000001;

	while(1)
	{

	}

}
