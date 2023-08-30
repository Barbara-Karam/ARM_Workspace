/************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :24 Aug 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/

//libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//layers
#include "GPIO_interface.h"
#include "GPIO_private.h"

//OWN DRIVER
#include "SEVEN_SEG_interface.h"
#include "SEVEN_SEG_config.h"
#include "SEVEN_SEG_private.h"



void SEVEN_SEG_voidDisplay(u8 copy_u8PORT,u8 copy_u8START_PIN,u8 copy_u8NUM,u8 copy_u8Mode)
{
if (copy_u8Mode == COMMON_CATH)
{
	MGPIO_voidSetPortDirection(copy_u8PORT,OUTPUT_SPEED_2M_PP);
	MGPIO_voidSetPortValue(copy_u8PORT,GPIO_HIGH);
	switch (copy_u8PORT) {
		case GPIOA:
			GPIOA_ODR &= ~((0b1111111)<< (copy_u8START_PIN));//resetting register
			GPIOA_ODR |= ((copy_u8NUM)<< (copy_u8START_PIN));
			break;
		case GPIOB:
			GPIOB_ODR &= ~((0b1111111)<< (copy_u8START_PIN));//resetting register
			GPIOB_ODR |= ((copy_u8NUM)<< (copy_u8START_PIN));
			break;
		case GPIOC:
			GPIOC_ODR &= ~((0b1111111)<< (copy_u8START_PIN));//resetting register
			GPIOC_ODR |= ((copy_u8NUM)<< (copy_u8START_PIN));
			break;
		default:
			break;

		}
}
else if (copy_u8Mode == COMMON_ANO)
{
	MGPIO_voidSetPortDirection(copy_u8PORT,OUTPUT_SPEED_2M_OD);
	MGPIO_voidSetPortValue(copy_u8PORT,GPIO_HIGH);
	switch (copy_u8PORT) {
			case GPIOA:
				GPIOA_ODR |= ((0b1111111)<< (copy_u8START_PIN));//resetting register
				GPIOA_ODR &= ~((copy_u8NUM)<< (copy_u8START_PIN));
				break;
			case GPIOB:
				GPIOB_ODR |= ((0b1111111)<< (copy_u8START_PIN));//resetting register
				GPIOA_ODR &= ~((copy_u8NUM)<< (copy_u8START_PIN));
				break;
			case GPIOC:
				GPIOC_ODR |= ((0b1111111)<< (copy_u8START_PIN));//resetting register
				GPIOA_ODR &= ~((copy_u8NUM)<< (copy_u8START_PIN));
				break;
			default:
				break;

			}
}
else {
	asm("NOP");
}
};
