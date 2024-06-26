/*
 * NVIC_config.h
 *
 *  Created on: Sep 25, 2023
 *      Author: brbar
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

void MNVIC_voidInit(void);


void MNVIC_voidEnableInterrupt (u8 Copy_u8IntNumber);
void MNVIC_voidDisableInterrupt (u8 Copy_u8IntNumber);

void MNVIC_voidSetPendingFlag (u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag (u8 Copy_u8IntNumber);

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8IntNumber);

void MNVIC_voidSetPriority (s8 Copy_s8InterruptID,u8 Copy_u8GroupPriority,u8 Copy_u8SubPriority,u32 Copy_u32GROUP);

#define			GROUP3		0x05FA0300 //4 bits for group, 0 bits for sub-group
#define			GROUP4		0x05FA0400 //3 bits for group, 1 bits for sub-group
#define			GROUP5		0x05FA0500 //2 bits for group, 2 bits for sub-group
#define			GROUP6		0x05FA0600 //1 bits for group, 3 bits for sub-group
#define			GROUP7		0x05FA0700 //0 bits for group, 4 bits for sub-group

#endif /* NVIC_INTERFACE_H_ */
