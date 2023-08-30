 /************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :12 Aug 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/

//libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//lower layers


//own drivers
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"

void RCC_voidEnableSysClocks(void)
{
	RCC_CR = 0x00;
	#if		RCC_HSI_MODE	==	RCC_CLOCK_ENABLE
	SET_BIT(RCC_CR,0); //enable HSI
	SET_BIT(RCC_CR,7); //no trimming
	#endif
	#if		RCC_HSE_MODE	==	RCC_CLOCK_ENABLE
	SET_BIT(RCC_CR,16); //enable HSE
	#if		RCC_HSE_RC_MODE == RCC_CLOCK_ENABLE
	SET_BIT(RCC_CR,18);//RC mode
	#endif//else crystal mode
	#endif
	#if		defined(RCC_PLL_MODE)
	#if 	RCC_PLL_MODE	==	RCC_CLOCK_ENABLE
	SET_BIT(RCC_CR,24);//enable PLL
	#endif
	#endif
	
}



void RCC_voidInitSysCLock(void)
{
	RCC_CFGR = RCC_CONC_CRFG_DEFAULTS(RCC_PLL_MUL_VALUE,RCC_PLL_INPUT,RCC_CLOCK_TYPE);
}


void RCC_voidEnableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB  : SET_BIT(RCC_AHBENR,Copy_u8PerId);   break;
		case RCC_APB1 : SET_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
		case RCC_APB2 : SET_BIT(RCC_APB2ENR,Copy_u8PerId);  break;

		}
	}
	else
	{
		/*Return Error*/
	}
	
}

void RCC_voidDisableClock(u8 Copy_u8BusId,u8 Copy_u8PerId)
{
	if(Copy_u8PerId <= 31)
	{
		switch(Copy_u8BusId)
		{
		case RCC_AHB  : CLR_BIT(RCC_AHBENR,Copy_u8PerId);   break;
		case RCC_APB1 : CLR_BIT(RCC_APB1ENR,Copy_u8PerId);  break;
		case RCC_APB2 : CLR_BIT(RCC_APB2ENR,Copy_u8PerId);  break;
		}
	}
	else
	{
		/*Return Error*/
	}
	
}


