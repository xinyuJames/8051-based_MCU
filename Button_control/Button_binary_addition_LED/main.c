/*
Xinyu Liu self-taught 8051 MCU
Description: this program can accomplish addition of binary number displayed by LED.
Version@2024/12/21
*/
#include <REGX52.H>
#include <INTRINS.H>

void Delay(unsigned int);

void main()
{
	unsigned int led = 0x00;
	
	while(1)
	{
		if (P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20); //simpler way to write one click
			//codes after one click
			led++;
			P2 = ~led;
		}
	}
}

/*
Delay customizable number of ms.
*/
void Delay(unsigned int xms)	//@11.0592MHz
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