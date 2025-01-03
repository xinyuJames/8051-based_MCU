#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"
#include "Music.h"

void main()
{
	Timer0_Init();
	musicSelect(2);
	while(1)
	{
		musicUpdate();	
	}
}

void Timer0_Routine() interrupt 1
{
	//static unsigned int count;
	TL0 = freqLUpdate();
	TH0 = freqHUpdate();
	//count++;
	buzz();
}