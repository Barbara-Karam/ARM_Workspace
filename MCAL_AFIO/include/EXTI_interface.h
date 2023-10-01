/*
 * EXTI_interface.h
 *
 *  Created on: Sep 28, 2023
 *      Author: brbar
 */

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

void MEXTI_voidInit();//u8 copy_u8Line,u8 copy_u8Mode
void MEXTI_voidEnableEXTI(u8 copy_u8Line);
void MEXTI_voidDisableEXTI(u8 copy_u8Line);
void MEXTI_voidSetSigLatch(u8 copy_u8Line,u8 copy_u8Mode);//for changing during runtime
#endif /* EXTI_INTERFACE_H_ */
