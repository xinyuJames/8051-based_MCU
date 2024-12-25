#include <REGX52.H>
#include <INTRINS.H>
#include "SerialCommunication.h"
#include "Delay.h"

unsigned char sec = 0;

void main()
{
	UART_Init();
	//UART_Send(0x00);
	while(1)
	{
		
	}
}

void UART_Routine() interrupt 4
{
	if (RI == 1)
	{
		P2 = ~SBUF;
		UART_Send(~SBUF);
		RI = 0;
	}
}
