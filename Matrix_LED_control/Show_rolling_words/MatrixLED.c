#include <REGX52.H>
#include <INTRINS.H>
#include "Delay_s.h"

void SR_Write(unsigned char);

sbit RC = P3^5;
sbit SRC = P3^6;
sbit SER = P3^4;

void MLED_ShowColumn(unsigned char columnNub, rowData)
{
	SR_Write(rowData);
	P0 = ~(0x80 >> columnNub);
	Delay_s(50); //make light littler longer
	P0 = ~0x00; //zero it
	
}

void MLED_ShowPoint(unsigned char x, y)
{
	
	
	
}

void SR_Write(unsigned char byte) //push active row numbers to matrix
{
	unsigned int i;
	for (i = 0; i < 8; i++)
	{
		SER = byte & (0x80 >> i); //1000 0000 since the matrix's rows are down to up
		SRC = 1;
		SRC = 0;
	}
	
	RC = 1;
	RC = 0;
}

void MLED_Init()
{
	SRC = 0;
	RC = 0;
}