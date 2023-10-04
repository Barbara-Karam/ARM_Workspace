/*
 * STK_private.h
 *
 *  Created on: Oct 4, 2023
 *      Author: brbar
 */

#ifndef STK_PRIVATE_H_
#define STK_PRIVATE_H_

typedef struct{
	volatile u32 CTRL;
	volatile u32 LOAD;
	volatile u32 VAL;
	volatile u32 CALIB;

}STK_t;

#define STK ((STK_t *)0xE000E010)

#endif /* STK_PRIVATE_H_ */
