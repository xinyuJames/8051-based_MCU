/*
Xinyu Liu self-taught 8051 MCU
Description: this program can set up timer using interrupts, show on LCD screen
Version@2024/12/24
*/

#include <REGX52.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "Delay.h"
#include "Timer0.h"

unsigned int sec = 0;
unsigned int min = 0;
unsigned int hour = 0;

void main()
{
	LCD_Init();
	Timer0_Init();
	
	LCD_ShowString(1, 1, "Timer:");
	while(1)
	{
		LCD_ShowNum(2, 1, hour, 2);
		LCD_ShowString(2, 3, ":");
		LCD_ShowNum(2, 4, min, 2);
		LCD_ShowString(2, 6, ":");
		LCD_ShowNum(2,7, sec, 2);
	}
}

void Timer0_Routine() interrupt 1
{
	static unsigned int count;
	
	TL0 = 0x66;
	TH0 = 0xFC;
	
	count++;
	while(count >= 1000)
	{	
		count = 0;
		
		sec++;
		if (sec >= 60)
		{
			min++;
			sec = 0;
		}
		if (min >= 60)
		{
			hour++;
			min = 0;
		}
	}
}