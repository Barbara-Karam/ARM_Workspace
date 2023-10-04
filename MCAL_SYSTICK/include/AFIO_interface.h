/*
 * AFIO_interface.h
 *
 *  Created on: Sep 30, 2023
 *      Author: brbar
 */

#ifndef AFIO_INTERFACE_H_
#define AFIO_INTERFACE_H_

void MAFIO_voidSetEXTIConfig(u8 copy_u8Line, u8 copy_u8PORTMap);

#define EXTI_PORTA 0b0000
#define EXTI_PORTB 0b0001
#define EXTI_PORTC 0b0010


#endif /* AFIO_INTERFACE_H_ */
