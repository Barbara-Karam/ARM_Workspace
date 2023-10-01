/************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :12 Aug 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/
#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB  0
#define RCC_APB1 1
#define RCC_APB2 2

#define   GPIOA_Clock	2
#define   GPIOB_Clock	3
#define   GPIOC_Clock	4



void RCC_voidEnableSysClocks(void);
void RCC_voidInitSysCLock(void);
void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);
void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId);





#endif
