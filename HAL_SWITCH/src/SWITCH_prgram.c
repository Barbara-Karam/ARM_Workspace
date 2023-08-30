/************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :26 Aug 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/

//libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"
//layers
#include "GPIO_interface.h"
#include "LED_interface.h"

//own driver
#include "SWITCH_interface.h"
#include "SWITCH_config.h"
#include"SWITCH_private.h"

void delayy(u32 counter)
{
	for(u32 i=0;i<=counter;i++)
	{
		for(u32 j=0;j<counter;j++)
		{
			asm("NOP");
		}

	}
}

void SWITCH_voidLED(u8 copy_u8SWITCH_PORT, u8 copy_u8SWITCH_PIN,
		u8 copy_u8LEDPORT, u8 copy_u8LEDPIN) {
	if (MGPIO_voidGetPinValue(copy_u8SWITCH_PORT,
			copy_u8SWITCH_PIN) == GPIO_HIGH) {
		delayy(1000);
		LED_voidOn(copy_u8LEDPORT, copy_u8LEDPIN);
	} else if (MGPIO_voidGetPinValue(copy_u8SWITCH_PORT,
			copy_u8SWITCH_PIN) == GPIO_LOW) {
		delayy(1000);
		LED_voidOff(copy_u8LEDPORT, copy_u8LEDPIN);
	}
}
