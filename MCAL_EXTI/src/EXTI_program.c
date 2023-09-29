/*
 * EXTI_program.c
 *
 *  Created on: Sep 28, 2023
 *      Author: brbar
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"


#include"EXTI_interface.h"
#include"EXTI_config.h"
#include"EXTI_private.h"

void MEXTI_voidInit()
{
	#if EXTI_MODE == RISING
		SET_BIT(EXTI->RTSR,EXTI_LINE);
	#elif EXTI_MODE == FALLING
		SET_BIT(EXTI->FTSR,EXTI_LINE);
	#elif EXTI_MODE == ON_CHANGE
		SET_BIT(EXTI->RTSR,EXTI_LINE);
		SET_BIT(EXTI->FTSR,EXTI_LINE);
	#else
		#error"Wrong Mode and Line Choice"
	#endif
}
void MEXTI_voidEnableEXTI(u8 copy_u8Line)
{
	SET_BIT(EXTI -> IMR,copy_u8Line);
}
void MEXTI_voidDisableEXTI(u8 copy_u8Line){
	CLR_BIT(EXTI -> IMR,copy_u8Line);
}
void MEXTI_voidSwTriger(u8 copy_u8Line)
{
	SET_BIT(EXTI -> SWIER, copy_u8Line);
}

void MEXTI_voidSetSigLatch(u8 copy_u8Line,u8 copy_u8Mode)//for changing during runtime
{
	switch(copy_u8Mode)
	{
	case RISING:SET_BIT(EXTI -> IMR,copy_u8Line);break;
	case FALLING:CLR_BIT(EXTI -> IMR,copy_u8Line);break;
	case ON_CHANGE:SET_BIT(EXTI->RTSR,EXTI_LINE);SET_BIT(EXTI->FTSR,EXTI_LINE);break;
	}
}
