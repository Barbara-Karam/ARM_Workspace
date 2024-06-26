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
#include "GPIO_interface.h"
#include "NVIC_interface.h"

void main()
{
	RCC_voidEnableSysClocks();
	RCC_voidInitSysCLock();
	//enable RCC for GPIOA
	RCC_voidEnableClock(RCC_APB2, GPIOA_Clock);

	//pin modes
	MGPIO_voidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2M_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2M_PP);
	MGPIO_voidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2M_PP);

	//initialize NVIC
	MNVIC_voidInit();

	//enable EXTI0 & EXTI1
	MNVIC_voidEnableInterrupt(6);
	MNVIC_voidEnableInterrupt(7);

	//setting priority
	MNVIC_voidSetPriority(6,1,0,GROUP5);
	MNVIC_voidSetPriority(7,0,3,GROUP5);

	MNVIC_voidClearPendingFlag(6);
	while (1)
	{


	};
}
