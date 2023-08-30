/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: brbar
 */

//libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "delay.h"
//layers
#include "RCC_interface.h"
#include "SEVEN_SEG_interface.h"
#include "GPIO_interface.h"


void main() {
	RCC_voidEnableSysClocks();
	RCC_voidInitSysCLock();
	//enable RCC for GPIOA
	RCC_voidEnableClock(RCC_APB2, GPIOA_Clock);
	//enable RCC for GPIOB
	RCC_voidEnableClock(RCC_APB2, GPIOB_Clock);
	//enable RCC for GPIOC
	RCC_voidEnableClock(RCC_APB2, GPIOC_Clock);
	//setting PORTA as push/pull output
	MGPIO_voidSetPortDirection(GPIOA,OUTPUT_SPEED_10M_PP);
	while (1)
	{
		SEVEN_SEG_voidDisplay(GPIOA,0,ZERO,COMMON_ANO);
		delay(100);
		SEVEN_SEG_voidDisplay(GPIOA,0,ONE,COMMON_ANO);
		delay(100);

	};
}
