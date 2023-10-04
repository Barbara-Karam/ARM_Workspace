/*
 * STK_interface.h
 *
 *  Created on: Oct 4, 2023
 *      Author: brbar
 */

#ifndef STK_INTERFACE_H_
#define STK_INTERFACE_H_

void	MSTK_voidLoad(u32 copy_u32DelayedClockCycle,u8 copy_u8Mode);
u32		MSTK_u32ReadTime(void);
u8		MSTK_u8ReadCountFlag(void);
void	MSTK_voidClockSource(u8 copy_u8Mode);
void	MSTK_voidEnableTimerINT(u8 copy_u8INTtMode);
void	MSTK_voidEnableTimer(u8 copy_u8TimerMode);


#define INT_MODE_SINGLE 0
#define INT_MODE_RECURRENT 1

#define AHB_DIV_8 0
#define AHB_NO_DIV 1

#define INT_OFF 0
#define INT_ON 1

#define TMR_OFF 0
#define TMR_ON 1

#endif /* STK_INTERFACE_H_ */
