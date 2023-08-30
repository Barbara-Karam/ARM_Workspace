/*
 * main.c
 *
 *  Created on: Aug 24, 2023
 *      Author: brbar
 */

//libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include"LED_interface.h"

//own driver
#include"SWITCH_interface.h"

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
	MGPIO_voidSetPortDirection(GPIOA, OUTPUT_SPEED_10M_PP);
	//setting PORTB as input pull up
	MGPIO_voidSetPortDirection(GPIOB, INPUT_PULL_U_D);
	MGPIO_voidSetPinDirection(GPIOB,0,GPIO_HIGH);

	while (1) {
		SWITCH_voidLED(GPIOB,0,GPIOA,0);

	};
}
