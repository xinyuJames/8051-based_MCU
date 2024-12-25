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
	
	LCD_Init();
	LCD_ShowString(1, 1, "Key pressed: ");
	while(1)
	{
		key = matrixKey();
		if(key)
		{
			LCD_ShowNum(2, 1, key, 2);
		}
	}
}