/*
 * AFIO_program.c
 *
 *  Created on: Sep 30, 2023
 *      Author: brbar
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"AFIO_interface.h"
#include"AFIO_config.h"
#include"AFIO_private.h"


void MAFIO_voidSetEXTIConfig(u8 copy_u8Line, u8 copy_u8PORTMap)
{
	u8 Local_u8RegIndex = 0;
	if(copy_u8Line <= 15)
	{
		Local_u8RegIndex = (copy_u8Line / 4);
		copy_u8Line=copy_u8Line%4;
		AFIO->EXTICR[Local_u8RegIndex]  &= ~((0b1111) << (copy_u8Line*4));//resetting
		AFIO->EXTICR[Local_u8RegIndex]  |= ((copy_u8PORTMap) << (copy_u8Line*4));//setting
	}
}
