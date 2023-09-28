/*
 * EXTI_private.h
 *
 *  Created on: Sep 28, 2023
 *      Author: brbar
 */

#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#include"STD_TYPES.h"

typedef struct{
	 u32 IMR;
	 u32 EMR;
	 u32 RTSR;
	 u32 FTSR;
	 u32 SWIER;
	 u32 PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t *) 0x40010400)

#endif /* EXTI_PRIVATE_H_ */
