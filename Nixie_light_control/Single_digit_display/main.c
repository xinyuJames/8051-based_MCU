/*
Xinyu Liu self-taught 8051 MCU
Description: this program can control nixie light show up any digit in any position.
Version@2024/12/22
*/

#include <REGX52.H>
#include <INTRINS.H>

void showDigit(unsigned int, unsigned int, int[], int[]);

void main()
{
	int positionSet[8] = {0, 1, 10, 11, 100, 101, 110, 111}; //position from first to last
	int numTable[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //numbers from 0-9
	while(1)
	{
		showDigit(1, 9, positionSet, numTable);
	}
	
}

//show up one digit of number in assigned location with tables initialized
void showDigit(unsigned int position, number, int positionSet[], int numTable[])
{
	P2_4 = positionSet[8-position] % 10;
	P2_3 = positionSet[8-position] % 100 / 10;
	P2_2 = positionSet[8-position] / 100;
	
	P0 = numTable[number];
}
