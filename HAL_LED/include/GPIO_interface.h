/************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :24 Aug 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/
#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/*pin values*/
#define GPIO_LOW	0
#define GPIO_HIGH	1

/*GPIO PORTS*/
#define GPIOA	0
#define GPIOB	1
#define GPIOC	2

/*GPIO PINS*/
#define	PIN0		0
#define	PIN1		1
#define	PIN2		2
#define	PIN3		3
#define	PIN4		4
#define	PIN5		5
#define	PIN6		6
#define	PIN7		7
#define	PIN8		8
#define	PIN9		9
#define	PIN10		10
#define	PIN11		11
#define	PIN12		12
#define	PIN13		13
#define	PIN14		14
#define	PIN15		15


			/*  modes  */
#define INPUT_ANALOG		0b0000
#define INPUT_FLOATING		0b0100
#define INPUT_PULL_U_D		0b1000


#define OUTPUT_SPEED_10M_PP		0b0001
#define OUTPUT_SPEED_10M_OD		0b0101
#define OUTPUT_SPEED_10M_AFPP	0b1001
#define OUTPUT_SPEED_10M_AFOD	0b1101


#define OUTPUT_SPEED_2M_PP		0b0010
#define OUTPUT_SPEED_2M_OD		0b0110
#define OUTPUT_SPEED_2M_AFPP	0b1010
#define OUTPUT_SPEED_2M_AFOD	0b1110


#define OUTPUT_SPEED_50M_PP		0b0011
#define OUTPUT_SPEED_50M_OD		0b0111
#define OUTPUT_SPEED_50M_AFPP	0b1011
#define OUTPUT_SPEED_50M_AFOD	0b1111



/*Functions Declarations*/
void MGPIO_voidSetPortDirection(u8 copy_u8PORT,u8 copy_u8Mode);

void MGPIO_voidSetPortValue(u8 copy_u8PORT, u8 copy_u8Value);

void MGPIO_voidSetPinDirection(u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Mode); 

void MGPIO_voidSetPinValue(u8 copy_u8PORT,u8 copy_u8PIN,u8 copy_u8Value); 

u8 MGPIO_voidGetPinValue(u8 copy_u8PORT,u8 copy_u8PIN); 



#endif
