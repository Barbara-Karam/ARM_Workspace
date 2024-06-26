/************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :24 August 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/

//libraries
#include "STD_TYPES.h"
#include "BIT_MATH.h"

//layers

//own driver
#include "GPIO_interface.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void MGPIO_voidSetPortDirection(u8 copy_u8PORT, u8 copy_u8Mode) {
	u8 copy_u8PIN = 0;
	switch (copy_u8PORT) {
	case GPIOA:
		for (copy_u8PIN = 0; copy_u8PIN <= 15; copy_u8PIN++) {
			if (copy_u8PIN <= 7) {
				//resetting register
				GPIOA_CRL &= ~((0b1111) << (copy_u8PIN * 4));
				//setting mode
				GPIOA_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));
			} else if (copy_u8PIN <= 15) {
				copy_u8PIN = copy_u8PIN - 8;
				//resetting register
				GPIOA_CRH &= ~((0b1111) << (copy_u8PIN * 4));
				//setting mode
				GPIOA_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4));
			}
		}
		break;
	case GPIOB:
		for (copy_u8PIN = 0; copy_u8PIN <= 15; copy_u8PIN++) {
			if (copy_u8PIN <= 7) {
				//resetting register
				GPIOB_CRL &= ~((0b1111) << (copy_u8PIN * 4));
				//setting mode
				GPIOB_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));
			} else if (copy_u8PIN <= 15) {
				copy_u8PIN = copy_u8PIN - 8;
				//resetting register
				GPIOB_CRH &= ~((0b1111) << (copy_u8PIN * 4));
				//setting mode
				GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4));
			}
		}
		break;
	case GPIOC:
		for (copy_u8PIN = 0; copy_u8PIN <= 15; copy_u8PIN++) {
			if (copy_u8PIN <= 7) {
				//resetting register
				GPIOC_CRL &= ~((0b1111) << (copy_u8PIN * 4));
				//setting mode
				GPIOC_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));
			} else if (copy_u8PIN <= 15) {
				copy_u8PIN = copy_u8PIN - 8;
				//resetting register
				GPIOC_CRH &= ~((0b1111) << (copy_u8PIN * 4));
				//setting mode
				GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4));

			}
		}
		break;
	default:
		break;

	}

}

void MGPIO_voidSetPinDirection(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Mode) {
	switch (copy_u8PORT) {
	case GPIOA:
		if (copy_u8PIN <= 7) {
			//resetting register
			GPIOA_CRL &= ~((0b1111) << (copy_u8PIN * 4));
			//setting mode
			GPIOA_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));
		} else if (copy_u8PIN <= 15) {
			copy_u8PIN = copy_u8PIN - 8;
			//resetting register
			GPIOA_CRH &= ~((0b1111) << (copy_u8PIN * 4));
			//setting mode
			GPIOA_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4));
		}
		break;
	case GPIOB:
		if (copy_u8PIN <= 7) {
			//resetting register
			GPIOB_CRL &= ~((0b1111) << (copy_u8PIN * 4));
			//setting mode
			GPIOB_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));
		} else if (copy_u8PIN <= 15) {
			copy_u8PIN = copy_u8PIN - 8;
			//resetting register
			GPIOB_CRH &= ~((0b1111) << (copy_u8PIN * 4));
			//setting mode
			GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4));
		}
		break;
	case GPIOC:
		if (copy_u8PIN <= 7) {
			//resetting register
			GPIOC_CRL &= ~((0b1111) << (copy_u8PIN * 4));
			//setting mode
			GPIOC_CRL |= ((copy_u8Mode) << (copy_u8PIN * 4));
		} else if (copy_u8PIN <= 15) {
			copy_u8PIN = copy_u8PIN - 8;
			//resetting register
			GPIOC_CRH &= ~((0b1111) << (copy_u8PIN * 4));
			//setting mode
			GPIOB_CRH |= ((copy_u8Mode) << (copy_u8PIN * 4));

		}
		break;
	default:
		break;

	}
}

void MGPIO_voidSetPinValue(u8 copy_u8PORT, u8 copy_u8PIN, u8 copy_u8Value) {
	switch (copy_u8PORT) {
	case GPIOA:
		if (copy_u8Value == GPIO_HIGH) {
			GPIOA_BSR = (1 << copy_u8PIN);
		} else if (copy_u8Value == GPIO_LOW) {
			GPIOA_BRR = (1 << copy_u8PIN);
		}
		break;
	case GPIOB: {
		if (copy_u8Value == GPIO_HIGH) {
			GPIOB_BSR = (1 << copy_u8PIN);
		} else if (copy_u8Value == GPIO_LOW) {
			GPIOB_BRR = (1 << copy_u8PIN);
		}
		break;
	}
	case GPIOC: {
		if (copy_u8Value == GPIO_HIGH) {
			GPIOC_BSR = (1 << copy_u8PIN);
		} else if (copy_u8Value == GPIO_LOW) {
			GPIOC_BRR = (1 << copy_u8PIN);
		}
		break;
	}
	default:
		break;
	}
}

void MGPIO_voidSetPortValue(u8 copy_u8PORT, u8 copy_u8Value) {
	switch (copy_u8PORT) {
	case GPIOA:
		if (copy_u8Value == GPIO_HIGH) {
			GPIOA_ODR |= (0b1111111);
		} else if (copy_u8Value == GPIO_LOW) {
			GPIOA_ODR &= (~0b1111111);
		}
		break;
	case GPIOB: {
		if (copy_u8Value == GPIO_HIGH) {
			GPIOB_ODR |= (0b1111111);
		} else if (copy_u8Value == GPIO_LOW) {
			GPIOB_ODR &= (~0b1111111);
		}
		break;
	}
	case GPIOC: {
		if (copy_u8Value == GPIO_HIGH) {
			GPIOC_ODR |= (0b1111111);
		} else if (copy_u8Value == GPIO_LOW) {
			GPIOC_ODR &= (~0b1111111);
		}
		break;
	}
	default:
		break;
	}

}

u8 MGPIO_voidGetPinValue(u8 copy_u8PORT, u8 copy_u8PIN) {
	u8 LOC_u8Reslt = 0;
	switch (copy_u8PORT) {
	case GPIOA: {
		LOC_u8Reslt = GET_BIT(GPIOA_IDR, copy_u8PIN);
		break;
	}
	case GPIOB: {
		LOC_u8Reslt = GET_BIT(GPIOB_IDR, copy_u8PIN);
		break;
	}
	case GPIOC: {
		LOC_u8Reslt = GET_BIT(GPIOC_IDR, copy_u8PIN);
		break;
	}
	default:
		break;
	}
	return LOC_u8Reslt;
}

void MGPIO_voidLockPinDirection(u8 copy_u8PORT, u8 copy_u8PIN) {
	switch (copy_u8PORT) {
	case GPIOA:
		SET_BIT(GPIOA_LCK,copy_u8PIN);
		break;
	case GPIOB:
		SET_BIT(GPIOA_LCK,copy_u8PIN);
		break;
	case GPIOC:
		SET_BIT(GPIOA_LCK,copy_u8PIN);
		break;
	default:
		break;

	}
}
