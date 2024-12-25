/*
Xinyu Liu self-taught 8051 MCU
Description: this program can control nixie light show up many digits.
Version@2024/12/22
*/

#include <REGX52.H>
#include <INTRINS.H>
#include "Header_Delay.h"

void showDigit(unsigned int, unsigned int, int[], int[]);

void main()
{
	int positionSet[8] = {111, 110, 101, 100, 11, 10, 1, 0}; //position from first to last
	int numTable[10] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F}; //numbers from 0-9
	while(1)
	{
		showDigit(1, 8, positionSet, numTable);
		//Delay(20);
		showDigit(2, 7, positionSet, numTable);
		//Delay(20);
		showDigit(3, 6, positionSet, numTable);
		//Delay(20);
		showDigit(4, 5, positionSet, numTable);
//		showDigit(5, 4, positionSet, numTable);
//		showDigit(6, 3, positionSet, numTable);
//		showDigit(7, 2, positionSet, numTable);
//		showDigit(8, 1, positionSet, numTable);
	}
	
}

//show up one digit of number in assigned location with tables initialized
void showDigit(unsigned int position, number, int positionSet[], int numTable[])
{
	P2_2 = positionSet[position - 1] % 10;
	P2_3 = positionSet[position - 1] % 100 / 10;
	P2_4 = positionSet[position - 1] / 100;
	
	P0 = numTable[number];
	Delay(1);
	P0 = 0x00; //zero it before move on to the next
}