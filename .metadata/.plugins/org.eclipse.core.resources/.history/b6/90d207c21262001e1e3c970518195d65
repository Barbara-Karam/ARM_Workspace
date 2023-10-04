/*
 * NVIC_config.h
 *
 *  Created on: Sep 25, 2023
 *      Author: brbar
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

#define	NVIC_BASE_ADDRESS	0xE000E100
#define	SCB_BASE_ADDRESS	0xE000ED00


#define NVIC_ISER0 			*((u32*)NVIC_BASE_ADDRESS+0x000)//enable external interrupts from 0 to 31
#define NVIC_ISER1 			*((u32*)NVIC_BASE_ADDRESS+0x004)//enable external interrupts from 32 to 60

#define NVIC_ICER0 			*((u32*)NVIC_BASE_ADDRESS+0x080)//disable external interrupts from 0 to 31
#define NVIC_ICER1 			*((u32*)NVIC_BASE_ADDRESS+0x084)//disable external interrupts from 32 to 60

#define NVIC_ISPR0 			*((u32*)NVIC_BASE_ADDRESS+0x100)//enable pending flag from 0 to 31
#define NVIC_ISPR1 			*((u32*)NVIC_BASE_ADDRESS+0x104)//enable pending flag from 32 to 60

#define NVIC_ICPR0 			*((u32*)NVIC_BASE_ADDRESS+0x180)//disable pending flag from 0 to 31
#define NVIC_ICPR1 			*((u32*)NVIC_BASE_ADDRESS+0x184)//disable pending flag from 32 to 60

#define NVIC_IABR0 			*((volatile u32*)NVIC_BASE_ADDRESS+0x200)//read active flag from 0 to 31
#define NVIC_IABR1 			*((volatile u32*)NVIC_BASE_ADDRESS+0x204)//read active flag from 32 to 60


#define NVIC_IPR			((volatile u8*)NVIC_BASE_ADDRESS+ 0x300)//an array since it's byte accessed

#define SCB_CPUID			*((volatile u32*)SCB_BASE_ADDRESS)
#define SCB_ICSR			*((volatile u32*)SCB_BASE_ADDRESS+0x04)
#define SCB_VTOR			*((volatile u32*)SCB_BASE_ADDRESS+0x08)
#define SCB_AIRCR			*((volatile u32*)SCB_BASE_ADDRESS+0x0C)
#define SCB_SCR				*((volatile u32*)SCB_BASE_ADDRESS+0x10)
#define SCB_CCR				*((volatile u32*)SCB_BASE_ADDRESS+0x14)
#define SCB_SHPR1			*((volatile u32*)SCB_BASE_ADDRESS+0x18)
#define SCB_SHPR2			*((volatile u32*)SCB_BASE_ADDRESS+0x1C)
#define SCB_SHPR3			*((volatile u32*)SCB_BASE_ADDRESS+0x20)
#define SCB_SHCRS			*((volatile u32*)SCB_BASE_ADDRESS+0x24)
#define SCB_CFSR			*((volatile u32*)SCB_BASE_ADDRESS+0x28)
#define SCB_HFSR			*((volatile u32*)SCB_BASE_ADDRESS+0x2C)
#define SCB_MMAR			*((volatile u32*)SCB_BASE_ADDRESS+0x34)
#define SCB_BFAR			*((volatile u32*)SCB_BASE_ADDRESS+0x38)




#endif /* NVIC_PRIVATE_H_ */
