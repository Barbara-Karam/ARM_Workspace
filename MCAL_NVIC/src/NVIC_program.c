/*
 * NVIC_program.c
 *
 *  Created on: Sep 25, 2023
 *      Author: brbar
 */
#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_config.h"
#include "NVIC_private.h"

void MNVIC_voidInit(void)
{
	#define SCB_AIRCR *((u32*)0xE000ED)
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}



void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ISER0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber=Copy_u8IntNumber-32;
		NVIC_ISER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ICER0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber=Copy_u8IntNumber-32;
		NVIC_ICER1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ISPR0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber=Copy_u8IntNumber-32;
		NVIC_ISPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber)
{
	if ( Copy_u8IntNumber <=31)
	{
		NVIC_ICPR0 = (1 << Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber=Copy_u8IntNumber-32;
		NVIC_ICPR1 = (1 << Copy_u8IntNumber);
	}
	else
	{
		/*Return Error*/
	}
}
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber)
{
	u8 Local_u8Result;
	if ( Copy_u8IntNumber <=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if ( Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber=Copy_u8IntNumber-32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else
	{
		Local_u8Result = 255; // Set to error value
	}

	return Local_u8Result;
}
void MNVIC_voidSetPriority (s8 Copy_s8InterruptID,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority,u32 Copy_u32GROUP)
{
	u8 Local_u8Priority =Copy_u8SubPriority | (Copy_u8GroupPriority<<((Copy_u32GROUP-0x05FA0300)/256));
	//core peripheral


	//external peripheral
	if(Copy_s8InterruptID >= 0)
	{
		NVIC_IPR[Copy_s8InterruptID]=Local_u8Priority << 4;//since the first 4 bits are reserved
	}
	SCB_AIRCR = Copy_u32GROUP;
}

