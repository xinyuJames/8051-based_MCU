/*
Xinyu Liu self-taught 8051 MCU
Description: this program include multiple helper functions associate with controlling LED light.
Version@2024/12/21
*/

#include <REGX52.H>
#include <INTRINS.H>

void sepLight();
void blinkLight();
void Delay1ms(unsigned int);
void oneByOneLight(unsigned int);

void main()
{
	oneByOneLight(125);
}

/*
LED will light up separately.
*/
void sepLight()
{
	P2 = 0xAA + 1; //1010 1010
}

/*
LED will blink separately every second.
*/
void blinkLight()
{
	while(1)
	{
		P2 = 0x55;
		Delay1ms(500);
		P2 = 0xAA;
		Delay1ms(500);
	}
}

/*
Delay for 500ms
*/
void Delay1ms(unsigned int xms)	//@11.0592MHz
{
	unsigned char data i, j;
	
	while(xms)
	{
			_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		
		xms--;
	}
	
}

/*
Control light up one by one from left to right and from right to left,
with customizable time separation. 
*/
void oneByOneLight(unsigned int xms) //use of shift << in 0 also important...
{
	unsigned led = 0x01;
	
	while (1)
	{
		while (led != 0x01) //0000 0001
		{
			P2 = ~led;
			led >>= 1;
			Delay1ms(xms);
		}
		
		while (led != 0x80) //1000 0000
		{
			P2 = ~led;
			led <<= 1;
			Delay1ms(xms);
		}
	}
}
