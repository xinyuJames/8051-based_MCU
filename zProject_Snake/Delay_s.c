/*
Delay_s function source codes, this is shorter time than Delay...
*/

#include <REGX52.H>
#include <INTRINS.H>

void Delay_s(unsigned char x10us)	//@11.0592MHz
{
	unsigned char data i;
	
	while(x10us--)
	{
		i = 2;
		while (--i);	
	}
}

