/*
 * NVIC_config.h
 *
 *  Created on: Sep 25, 2023
 *      Author: brbar
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define	NVIC_BASE_ADDRESS	0xE000E100

#define NVIC_ISER0 			*((u32*)NVIC_BASE_ADDRESS+0)//enable external interrupts from 0 to 31
#define NVIC_ISER1 			*((u32*)NVIC_BASE_ADDRESS+4)//enable external interrupts from 32 to 60

#define NVIC_ICER0 			*((u32*)NVIC_BASE_ADDRESS+80)//disable external interrupts from 0 to 31
#define NVIC_ICER1 			*((u32*)NVIC_BASE_ADDRESS+84)//disable external interrupts from 32 to 60

#define NVIC_ISPR0 			*((u32*)NVIC_BASE_ADDRESS+100)//enable pending flag from 0 to 31
#define NVIC_ISPR1 			*((u32*)NVIC_BASE_ADDRESS+104)//enable pending flag from 32 to 60

#define NVIC_ICPR0 			*((u32*)NVIC_BASE_ADDRESS+180)//disable pending flag from 0 to 31
#define NVIC_ICPR1 			*((u32*)NVIC_BASE_ADDRESS+184)//disable pending flag from 32 to 60

#define NVIC_IABR0 			*((volatile u32*)NVIC_BASE_ADDRESS+200)//read active flag from 0 to 31
#define NVIC_IABR1 			*((volatile u32*)NVIC_BASE_ADDRESS+204)//read active flag from 32 to 60
#endif /* NVIC_PRIVATE_H_ */
