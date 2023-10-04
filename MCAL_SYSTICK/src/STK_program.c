/*
 * STK_program.c
 *
 *  Created on: Oct 4, 2023
 *      Author: brbar
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"STK_interface.h"
#include"STK_config.h"
#include"STK_private.h"


void MSTK_voidLoad(u32 copy_u32DelayedClockCycle,u8 copy_u8Mode)
{
	if(copy_u32DelayedClockCycle <= 0x00FFFFFF)
	{
		if(copy_u8Mode == INT_MODE_RECURRENT)
		{
			copy_u32DelayedClockCycle--;
		}
		STK->LOAD = copy_u32DelayedClockCycle;
		STK->VAL = 0;
		MSTK_voidEnableTimer(TMR_ON);
		// wait till COUNTFLAG is set 1, indicating counter in LOAD register has decremented to 0
		while ((STK->CTRL & MSTK_u8ReadCountFlag()) == 0);
	}
	else
	{
		//error
	}
}

u32 MSTK_u32ReadTime(void)
{
	return STK->VAL;
}
u8 MSTK_u8ReadCountFlag(void)
{
	u8 Local_u8CountFlag = GET_BIT(STK->CTRL,16);
	return Local_u8CountFlag;
}
void MSTK_voidClockSource(u8 copy_u8Mode)
{
	if(copy_u8Mode == AHB_DIV_8)
	{
		CLR_BIT(STK->CTRL,2);
	}
	else if(copy_u8Mode == AHB_NO_DIV)
	{
		SET_BIT(STK->CTRL,2);
	}
	else
	{
		//error
	}
}
void MSTK_voidEnableTimerINT(u8 copy_u8INTtMode)
{
	if(copy_u8INTtMode == INT_OFF)
		{
			CLR_BIT(STK->CTRL,1);
		}
		else if(copy_u8INTtMode == INT_ON)
		{
			SET_BIT(STK->CTRL,1);
		}
		else
		{
			//error
		}
}
void MSTK_voidEnableTimer(u8 copy_u8TimerMode)
{
	if(copy_u8TimerMode == TMR_OFF)
		{
			CLR_BIT(STK->CTRL,0);
		}
		else if(copy_u8TimerMode == TMR_ON)
		{
			SET_BIT(STK->CTRL,0);
		}
		else
		{
			//error
		}
}
