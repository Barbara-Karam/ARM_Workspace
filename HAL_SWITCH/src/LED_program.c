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

//own driver
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

void delay(u32 counter)
{
	for(u32 i=0;i<=counter;i++)
	{
		for(u32 j=0;j<counter;j++)
		{
			asm("NOP");
		}

	}
}




void LED_voidOn(u8 copy_u8PORT, u8 copy_u8PIN) {
	MGPIO_voidSetPinDirection(copy_u8PORT, copy_u8PIN, OUTPUT_SPEED_2M_PP);
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, GPIO_HIGH);

}
void LED_voidOff(u8 copy_u8PORT, u8 copy_u8PIN) {
	MGPIO_voidSetPinDirection(copy_u8PORT, copy_u8PIN, OUTPUT_SPEED_2M_PP);
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, GPIO_LOW);
}
void LED_voidTog(u8 copy_u8PORT, u8 copy_u8PIN) {
	MGPIO_voidSetPinDirection(copy_u8PORT, copy_u8PIN, OUTPUT_SPEED_2M_PP);
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, GPIO_HIGH);
	delay(1000);
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, GPIO_LOW);
	delay(1000);
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, GPIO_HIGH);
	delay(1000);
	MGPIO_voidSetPinValue(copy_u8PORT, copy_u8PIN, GPIO_LOW);
	delay(1000);

}
