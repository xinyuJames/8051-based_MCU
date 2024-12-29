/*
Xinyu Liu self-taught 8051 MCU
Description: this program can control matrix LED to show words and make them roll
Version@2024/12/25

using new concept of Shift Register for matrix LED, pretty cool
*/

#include <REGX52.H>
#include <INTRINS.H>
#include "Delay_s.h"
#include "MatrixLED.h"
#include "MLED_Lib.h"

void main()
{
	MLED_Init();
	
	while(1)
	{
		MLEDShow_HELLO();
	}
}