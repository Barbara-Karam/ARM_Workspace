/************************************************************************/
/*Author  :Barbara Karam                                                */
/*Date    :24 Aug 2023                                                  */
/*Version :V01                                                          */
/************************************************************************/
#ifndef SEVEN_SEG_INTERFACE_H
#define SEVEN_SEG_INTERFACE_H


void SEVEN_SEG_voidDisplay(u8 copy_u8PORT,u8 copy_u8START_PIN,u8 copy_u8NUM,u8 copy_u8Mode);


#define ZERO   0b00111111
#define ONE    0b00000110
#define TWO    0b01011011
#define THREE  0b01001111
#define FOUR   0b01100110
#define FIVE   0b01101101
#define SIX    0b01111101
#define SEVEN  0b00000111
#define EIGHT  0b01111111
#define NINE   0b01101111

#define COMMON_CATH 0
#define COMMON_ANO 1

#endif
