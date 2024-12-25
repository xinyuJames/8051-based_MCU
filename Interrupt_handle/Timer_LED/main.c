/*
Xinyu Liu self-taught 8051 MCU
Description: this program uses timer interrupts to handle LED light with buttons.
Version@2024/12/23

note: timer timed by crystal oscillator in CPU, and to a certain inpulse, send
request to interrupts, and we need to handle that interrupts, which is called interrupt
handling. There're interrupts priorities to handle, and when CPU to from lower to a higer
priority, this is called "Interrupt nesting".
*/

#include <REGX52.H>
#include <INTRINS.H>
#include "Timer0.h"
#include "Delay.h"

unsigned char getKey();
unsigned int LEDmode;
unsigned char LED = 0x01; //use _crol_() becaues integer has too many bits.

void main()
{
	int key;
	LEDmode = 0;
	Timer0_Init();
	
	while(1)
	{
		key = getKey();
		if (key)
		{
			if (key == 1) //press the first key to enter mode 1
			{ 
				LEDmode = 1;
			}
			if (key == 2) //press the second key to enter mode 2
			{
				LEDmode = 2;
				
			}
		}
	}
}

//handle interruptions from timer0
void Timer0_Routine() interrupt 1
{
	static 	unsigned int count = 0;
	
	TL0 = 0x66; //reset TL and TH
	TH0 = 0xFC;
	
	count++;
	if (count >= 500)
	{
		count = 0;
		
		if (LEDmode == 1) //mode 1, when LED all move to left one by one, used riht rotation
		{
			LED = _cror_(LED, 1);
		}
		
		if (LEDmode == 2) //vice versa
		{
			LED = _crol_(LED, 1);
		}
		
		P2 = ~LED;
	}
}

unsigned char getKey()
{
	unsigned char key;
	key = 0;
	if (P3_1 == 0)
	{
		Delay(20);
		while(P3_1 == 0);
		Delay(20);
		key = 1;
	}
	
	if (P3_0 == 0)
	{
		Delay(20);
		while(P3_0 == 0);
		Delay(20);
		key = 2;
	}
	
	if (P3_2 == 0)
	{
		Delay(20);
		while(P3_2 == 0);
		Delay(20);
		key = 3;
	}
	
	if (P3_3 == 0)
	{
		Delay(20);
		while(P3_3 == 0);
		Delay(20);
		key = 4;
	}
	
	return key;
}

