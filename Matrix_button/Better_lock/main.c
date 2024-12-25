/*
Xinyu Liu self-taught 8051 MCU
Description: this program contains basic control to matrix_button module
Version@2024/12/23
*/

#include <REGX52.H>
#include <INTRINS.H>
#include "LCD1602.h"
#include "Delay.h"
#include "MatrixKey.h"

void main()
{
	unsigned char key;
	unsigned int password;
	unsigned int passtry;
	unsigned int count;
	LCD_Init();
	count = 0;
	password = 711;
	passtry = 0;
	
	LCD_ShowString(1, 1, "Password: ");
	
	while(1)
	{
		key = matrixKey();
		if(key)
		{
			count++;
			if (key <= 10 && count <= 4)
			{
				passtry *= 10;
				passtry += key % 10;
			} else if (key == 11)
			{
				if (passtry == password)
				{
					LCD_ShowString(1, 14, "OK");
				} else
				{
					LCD_ShowString(1, 14, "NO");
				}
				count = 0;
				passtry = 0;
			} else if (key == 12)
			{
				count = 0;
				passtry = 0;
				
			}
			LCD_ShowNum(2, 1, passtry, 4);
		}
	}
}