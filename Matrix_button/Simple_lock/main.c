/*
Xinyu Liu self-taught 8051 MCU
Description: this program achive simple lock.
Version@2024/12/23
*/

#include <REGX52.H>
#include <INTRINS.H>
#include <STDLIB.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

void main()
{
	unsigned char key;
	unsigned int try1;
	unsigned int try2;
	unsigned int try3;
	unsigned int try4;
	unsigned int password;
	int count;
	int i;
	LCD_Init();
	
	password = 5711;
	LCD_ShowString(1, 1, "Password: ");
	count = 0;
	try1 = 0;
	try2 = 0;
	try3 = 0;
	try4 = 0;
	while(1)
	{
		key = matrixKey();
		if(key) //it cannot show 1000 correctly, so dont make number that big, change plan.
		{ 
			count++;
			
			if (count == 1) {try1 = key;}
			if (count == 2) {try2 = key;}
			if (count == 3) {try3 = key;}
			if (count == 4) {try4 = key;}
			
			LCD_ShowNum(2, 1, try1, 1);
			LCD_ShowNum(2, 2, try2, 1);
			LCD_ShowNum(2, 3, try3, 1);
			LCD_ShowNum(2, 4, try4, 1);
			
			if (count == 4) //when enter 4 digits
			{
				if (try1 * 1000 + try2 * 100 + try3 * 10 + try4 != password)
				{
					LCD_ShowString(1, 14, "ERR");
					//LCD_ShowNum(2, 6, try1 * 1000 + try2 * 100 + try3 * 10 + try4, 4);
					//LCD_ShowNum(2, 11, password, 4);
				} else
				{
					LCD_ShowString(1, 14, "VAL");
				}
				try1 = 0;
				try2 = 0;
				try3 = 0;
				try4 = 0;
				count = 0;
			}
		}
	}
}