/*
Xinyu Liu self-taught 8051 MCU

version@2024/12/22
*/
#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms(unsigned int);

void main()
{
	P2_0 = 1;
	while(1)
	{
		if (P3_1 == 0) //click it
		{
			Delay1ms(20);
			while(1) //waiting to release button
			{
				if (P3_1 == 1) //released
				{
					Delay1ms(20);
					P2_0 = ~P2_0; //change LED status and exit inner loop
					break;
				}
			}
		}
		
	}
}

/*
Delay customizable number of ms.
*/
void Delay1ms(unsigned int xms)	//@11.0592MHz
{
	unsigned char data i, j;
	while(xms)
	{
		_nop_();
		_nop_();
		_nop_();
		i = 11;
		j = 190;
		do
		{
			while (--j);
		} while (--i);
		
		xms--;
	}
}
