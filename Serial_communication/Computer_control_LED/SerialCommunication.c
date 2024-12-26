#include <REGX52.H>
#include <INTRINS.H>

void UART_Init()
{
	//serial control/power control
	PCON &= 0x7F;		
	SCON = 0x50;
	
	TMOD &= 0x0F;		
	TMOD |= 0x20;	
	TL1 = 0xFD;
	TH1 = 0xFD;
	ET1 = 0;
	TR1 = 1;
	EA = 1;
	ES = 1;
}

void UART_Send(unsigned char byte)
{
	SBUF = byte;
	while(TI == 0);
	TI = 0;
}