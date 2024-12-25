/*
Xinyu Liu self-taught 8051 MCU
Description: this program is test program for LCD1602 debugging tool
Version@2024/12/22
*/

#include <REGX52.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "Header_Delay.h"

void main()
{
	int counter = 0;
	LCD_Init();
	while(1)
	{
		counter++;
		Delay(1000);
		LCD_ShowNum(1, 1, counter, 3);
	}
}