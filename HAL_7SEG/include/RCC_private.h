/************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :12 Aug 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/
#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* Register Definition */

#define	 	 RCC_CR	 	 		*((volatile u32*)0x40021000)
#define	 	 RCC_CFGR	 		*((volatile u32*)0x40021004)
#define	 	 RCC_CTR	 		*((volatile u32*)0x40021008)
#define	 	 RCC_APB2RSTR		*((volatile u32*)0x4002100C)
#define		 RCC_APB1RSTR		*((volatile u32*)0x40021010)
#define		 RCC_AHBENR	 		*((volatile u32*)0x40021014)
#define		 RCC_APB2ENR		*((volatile u32*)0x40021018)
#define	 	 RCC_APB1ENR		*((volatile u32*)0x4002101C)
#define	 	 RCC_BDCR	 		*((volatile u32*)0x40021020)
#define	 	 RCC_CSR	 		*((volatile u32*)0x40021024)

/* Clock Types*/
#define		 RCC_HSI	 			00
#define 	 RCC_HSE				01
#define 	 RCC_PLL 	 			10	

/*CLOCK OPTIONS*/
#define 	RCC_CLOCK_ENABLE			1
#define 	RCC_CLOCK_DISABLE			0

/*PLL Options*/
#define 	RCC_PLL_IN_HSI_DIV_2	00
#define 	RCC_PLL_IN_HSE_DIV_2	11
#define 	RCC_PLL_IN_HSE			01

/*Macros for PLL Multiplication Factors*/
#define 	PLL_MUL_2			0000
#define 	PLL_MUL_3			0001
#define 	PLL_MUL_4			0010
#define 	PLL_MUL_5			0011
#define 	PLL_MUL_6			0100
#define 	PLL_MUL_7			0101
#define 	PLL_MUL_8			0110
#define 	PLL_MUL_9			0111
#define 	PLL_MUL_10			1000
#define 	PLL_MUL_11			1001
#define 	PLL_MUL_12			1010
#define 	PLL_MUL_13			1011
#define 	PLL_MUL_14			1100
#define 	PLL_MUL_15			1101
#define 	PLL_MUL_16			1101



/* Macros for CONC */
#define		RCC_CONC_CR_DEFAULTS(b6,b4,b2,b0)			 CONC(00000000,b6,00000,b4,0,b2,00000000000000,b0)
#define 	RCC_CONC_CRFG_DEFAULTS(b5,b4,b0)     	     CONC(0000,0000,00,b5,b4,0000000,0000000,b0)
#define 	CONC(b7,b6,b5,b4,b3,b2,b1,b0)                CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)
#define 	CONC_HELP(b7,b6,b5,b4,b3,b2,b1,b0)           0b##b7##b6##b5##b4##b3##b2##b1##b0

#endif
