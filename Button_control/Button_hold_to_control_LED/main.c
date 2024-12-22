/*
Xinyu Liu self-taught 8051 MCU
Description: this program can accomplish that holding leftmost button so LED can light up.
Version@2024/12/21
*/
#include <REGX52.H>
#include <INTRINS.H>

void hold2Light();

void main()
{
	hold2Light();
}

void hold2Light()
{
	while(1)
	{
		if (P3_1 == 0)
		{
			P2_0 = 0;
		} else
		{
			P2_0 = 1;
		}
	}
}
