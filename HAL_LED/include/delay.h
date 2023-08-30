#ifndef DELAY_H_
#define DELAY_H_

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



#endif /* DELAY_H_ */