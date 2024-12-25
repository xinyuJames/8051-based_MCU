#include <REGX52.H>
#include <INTRINS.H>
#include "SerialCommunication.h"
#include "Delay.h"

unsigned char sec = 0;

void main()
{
	UART_Init();
	UART_Send(0x00);
	while(1)
	{
		Delay(1000);
		sec++;
		UART_Send(sec);
		
	}
}
