/*
 * Delay.c
 *
 *  Created on: Aug 26, 2023
 *      Author: brbar
 */

//delay
void delay(int counter)
{
for(int i=0;i<counter;i++)
{
	for(int j=0;j<counter;j++)
	{
		asm("NOP");
	}

}
}
