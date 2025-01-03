/*
Xinyu Liu self-taught 8051 MCU
Description: source codes of initializing timer0
Version@2024/12/23
*/

#include <REGX52.H>

void Timer0_Init()
{
//	TMOD = 0x01; //0000 0001 Manual 7.1.1 set mode to timer1 and 16bit timer or adder
	TMOD &= 0xF0;
	TMOD |= 0x01;
	TF0 = 0;
	TR0 = 1;
	//assume that 1000 difference is required to make 1ms time difference
	//store 0 - 65535, TL will flow to TH, and TH flow to TF, so as to interrupt
//	TH0 = 64535 / 256; //first 8bit
//	TL0 = 64535 % 256; //last 8bit
	TL0 = 0x66;
	TH0 = 0xFC;
	
	//interrupt enable control register. manual 6.1
	ET0 = 1;
	EA = 1;
	//interrupt priority control register
	PT0 = 0; //lower priority as default
}
