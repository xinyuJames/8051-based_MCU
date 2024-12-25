#include <REGX52.H>
#include <INTRINS.H>

void delay(unsigned int);

void main() //press the first and the last button to make LED move to left or right
{
	unsigned int led = 0x80; //1000 0000
	P2 = ~led;
	while(1)
	{
		if (P3_3 == 0 && led != 0x80)
		{
			delay(20);
			while(P3_3 == 0);
			delay(20);
			
			led <<= 1;
			P2 = ~led;
		}
		
		if (P3_1 == 0 && led != 0x01)
		{
			delay(20);
			while(P3_1 == 0);
			delay(20);
			
			led >>= 1;
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