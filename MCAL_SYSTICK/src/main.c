/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: brbar
 */

//libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//layers
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STK_interface.h"


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

	MSTK_voidClockSource(AHB_DIV_8);
	MSTK_voidLoad(200000,INT_MODE_SINGLE);
	u8 pairs[4][2] = {{3, 4}, {2, 5}, {1, 6}, {0, 7}};
	u8 counter,i,pin;
	while (1)
	{

		for(i=0;i<=3;i++)
		{
		for(counter = 0; counter < 16; counter++)
		{
		    pin = (counter <= 7) ? counter : 15 - counter;
		    MGPIO_voidSetPinValue(GPIOA, pin, GPIO_HIGH);
		    MSTK_voidLoad(200000, INT_MODE_SINGLE);
		    MGPIO_voidSetPinValue(GPIOA, pin, GPIO_LOW);
		}
		}
		for(i = 0; i < 4; i++)
		{
		    MGPIO_voidSetPinValue(GPIOA, pairs[i][0], GPIO_HIGH);
		    MGPIO_voidSetPinValue(GPIOA, pairs[i][1], GPIO_HIGH);
		    MSTK_voidLoad(200000, INT_MODE_SINGLE); // Wait for 200 ms
		}

		// Now turn off the LEDs in reverse order
		for(i = 4; i > 0; i--)
		{
		    MGPIO_voidSetPinValue(GPIOA, pairs[i-1][0], GPIO_LOW);
		    MGPIO_voidSetPinValue(GPIOA, pairs[i-1][1], GPIO_LOW);
		    MSTK_voidLoad(200000, INT_MODE_SINGLE); // Wait for 200 ms
		}



	};
}
