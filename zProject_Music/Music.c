/*
Xinyu Liu self-taught 8051 MCU
Description: this file store music library for Music1: Castle in the sky; Music2-5: Flower Dance. This also include functions nessasary for play music
Version@2025/1/3
*/

#include <REGX52.H>
#include "Delay.h"
#include "Timer0.h"

#define P	0
#define L1	1
#define L1_	2
#define L2	3
#define L2_	4
#define L3	5
#define L4	6
#define L4_	7
#define L5	8
#define L5_	9
#define L6	10
#define L6_	11
#define L7	12
#define M1	13
#define M1_	14
#define M2	15
#define M2_	16
#define M3	17
#define M4	18
#define M4_	19
#define M5	20
#define M5_	21
#define M6	22
#define M6_	23
#define M7	24
#define M7_ 25
#define H1	26
#define H1_	27
#define H2	28
#define H2_	29
#define H3	30
#define H4	31
#define H4_	32
#define H5	33
#define H5_	34
#define H6	35
#define H6_	36
#define H7	37
#define HH1 38
#define HH1_ 39
#define HH2 40
#define HH3 41

#define SPEED 110
//buzzer IO
sbit buzzer = P2^5;

unsigned int freqTable[]={
	0,
	63628,63731,63835,63928,64021,64103,64185,64260,64331,64400,64463,64528,
	64580,64633,64684,64732,64777,64820,64860,64898,64934,64968,65000,65030,65045,
	65058,65085,65110,65134,65157,65178,65198,65217,65235,65252,65268,65283,
	65300,65308,65316,65327,
};

xdata unsigned int music1[] = {
	//1
//	P,	4,
//	P,	4,
//	P,	4,
//	M6,	2,
//	M7,	2,
//	
//	H1,	4+2,
//	M7,	2,
//	H1,	4,
//	H3,	4,
//	
//	M7,	4+4+4,
//	M3,	2,
//	M3,	2,
//	
//	//2
//	M6,	4+2,
//	M5,	2,
//	M6, 4,
//	H1,	4,
//	
//	M5,	4+4+4,
//	M3,	4,
//	
//	M4,	4+2,
//	M3,	2,
//	M4,	4,
//	H1,	4,
//	
//	//3
//	M3,	4+4,
//	P,	2,
//	H1,	2,
//	H1,	2,
//	H1,	2,
//	
//	M7,	4+2,
//	M4_,2,
//	M4_,4,
//	M7,	4,
//	
//	M7,	8,
//	P,	4,
//	M6,	2,
//	M7,	2,
//	
//	//4
//	H1,	4+2,
//	M7,	2,
//	H1,	4,
//	H3,	4,
//	
//	M7,	4+4+4,
//	M3,	2,
//	M3,	2,
//	
//	M6,	4+2,
//	M5,	2,
//	M6, 4,
//	H1,	4,
//	
//	//5
//	M5,	4+4+4,
//	M2,	2,
//	M3,	2,
//	
//	M4,	4,
//	H1,	2,
//	M7,	2+2,
//	H1,	2+4,
//	
//	H2,	2,
//	H2,	2,
//	H3,	2,
//	H1,	2+4+4,
//	
//	//6
//	H1,	2,
//	M7,	2,
//	M6,	2,
//	M6,	2,
//	M7,	4,
//	M5_,4,
//	
//	
//	M6,	4+4+4,
//	H1,	2,
//	H2,	2,
//	
//	H3,	4+2,
//	H2,	2,
//	H3,	4,
//	H5,	4,
//	
//	//7
//	H2,	4+4+4,
//	M5,	2,
//	M5,	2,
//	
//	H1,	4+2,
//	M7,	2,
//	H1,	4,
//	H3,	4,
//	
//	H3,	4+4+4+4,
//	
//	//8
//	M6,	2,
//	M7,	2,
//	H1,	4,
//	M7,	4,
//	H2,	2,
//	H2,	2,
//	
//	H1,	4+2,
//	M5,	2+4+4,
//	
//	H4,	4,
//	H3,	4,
//	H3,	4,
//	H1,	4,
//	
//	//9
//	H3,	4+4+4,
//	H3,	4,
//	
//	H6,	4+4,
//	H5,	4,
//	H5,	4,
//	
//	H3,	2,
//	H2,	2,
//	H1,	4+4,
//	P,	2,
//	H1,	2,
//	
//	//10
//	H2,	4,
//	H1,	2,
//	H2,	2,
//	H2,	4,
//	H5,	4,
//	
//	H3,	4+4+4,
//	H3,	4,
//	
//	H6,	4+4,
//	H5,	4+4,
//	
//	//11
//	H3,	2,
//	H2,	2,
//	H1,	4+4,
//	P,	2,
//	H1,	2,
//	
//	H2,	4,
//	H1,	2,
//	H2,	2+4,
//	M7,	4,
//	
//	M6,	4+4+4,
//	P,	4,
//	
	0xFF
};

xdata unsigned int music2[] = 
{
	//1
	H3, 2,
	H2, 2,
	H6, 2,
	H2, 2,
	
	H3, 2,
	H2, 2,
	M6, 2,
	H2, 2,
	
	//2
	H3, 2,
	H2, 2,
	H6, 2,
	H2, 2,
	
	H3, 2,
	H2, 2,
	M6, 2,
	H2, 2,
	
	//3
	H3, 2,
	H2, 2,
	H6, 2,
	H2, 2,
	
	H3, 2,
	H2, 2,
	M6, 2,
	H2, 2,
	
	//4
	H3, 2,
	H2, 2,
	H6, 2,
	H2, 2,
	
	H3, 2,
	H2, 2,
	M6, 2,
	H2, 2,
	
	//5
	H3, 2,
	H2, 2,
	H6, 2,
	H2, 2,
	
	H3, 2,
	H2, 2,
	M6, 2,
	H2, 2,
	
	//6
	H3, 2,
	H2, 2,
	H6, 2,
	H2, 2,
	
	H3, 2,
	H2, 2,
	M6, 2,
	H2, 4,
	P, 6,
	
	//7
	P, 2,
	H3, 2,
	H3, 4+1,
	M6, 1,
	H1, 1,
	H3, 1,
	H2, 4,
	H5, 4,
	
	//8
	H2, 3,
	H7, 1,
	H6, 3,
	H5_, 1,
	H6, 4,
	HH1_, 4,
	
	//9
	H6, 4,
	HH1_, 4,
	HH1, 1,
	HH1, 1,
	HH1_, 1,
	HH1, 1,
	H7, 2,
	H5_, 2,
	
	//10
	H6, 4+4,
	P, 4+4,
	H1, 2,
	M3, 2,
	M6, 2,
	H3, 2,
	
	//11
	H3, 4+1,
	M6, 1,
	H1, 1,
	H3, 1,
	H2, 4, 
	H5, 4,
	
	//12
	H2, 2,
	H5_, 2,
	H6, 2,
	H7, 2,
	H3, 1,
	HH1, 1,
	H2, 1,
	H7, 1,
	H1, 1,
	H6, 1,
	M7_, 1,
	H5_, 1,
	
	//13
	H6, 1,
	HH2, 1, 
	HH1, 1,
	HH2, 1,
	H6, 1,
	HH1, 1, 
	HH1, 1,
	HH2, 1,
	H6, 1,
	HH2, 1, 
	HH1, 1,
	HH2, 1,
	H6, 1,
	HH2, 1, 
	HH1, 1,
	HH2, 1,
	//14
	H6, 1,
	HH2, 1,
	HH1, 1,
	HH2, 1,
	H6, 1,
	HH2, 1,
	H7, 1,
	HH2, 1,
	H6, 1,
	HH2, 1,
	H6_, 1,
	HH2, 1,
	H6, 2,
	H3, 2,
	H7, 1,
	H3, 1,
	H7, 1,
	H7, 1,
	H3, 1,
	H2, 1,
	H3, 1,
	H7, 1,
	M7, 1,
	H6, 1,
	M7, 1,
	H5, 2,
	H3, 1,
	H5, 1,

	//make a new list here
	
	//make a new list here
	
	
	0xFF,
};

xdata unsigned int music3[] = 
{
	H6, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	H6, 1,
	H1, 1,
	HH1, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	H4, 1,
	H1, 1,
	H3, 2,
	H3, 1,
	H5, 1,
	
	H4, 1,
	M6, 1,
	H3, 1,
	M6, 1,
	H2, 1,
	M6, 1,
	H4, 1,
	M6, 1,
	H3, 1,
	M6, 1,
	H2, 1,
	M6, 1,
	H1, 1,
	M6, 1,
	H3, 1,
	M6, 1,
	
	H2, 1,
	M4, 1,
	HH1, 1,
	M4, 1,
	M7, 1,
	M4, 1,
	M6, 1,
	M4, 1,
	M5_, 2,
	M6, 2,
	M7, 4,
	//continue from section B 2nd line...
	H1, 1,
	M3, 1,
	M7, 1, 
	M3, 1,
	H1, 1,
	M3, 1, 
	H2, 1,
	M3, 1,
	M7, 1,
	M3, 1,
	M6, 1,
	M3, 1,
	M5, 2,
	M3, 1,
	M5, 1,
	M6, 1,
	M1, 1,
	M5, 1,
	M1, 1,
	M6, 1,
	M1, 1,
	H1, 1,
	M1, 1,
	M5, 1,
	M1, 1,
	M4, 1,
	M1, 1,
	M3, 2,
	M3, 1,
	M5, 1,
	
	M4, 2,
	H4, 1,
	H3, 1,
	H2, 1,
	H1, 1,
	M7, 1,
	M6, 1,
	H3, 1,
	H2, 1,
	H3, 1,
	H4, 1,
	H3, 1,
	H2, 1,
	H1, 1,
	M7, 1,
	M6, 2,
	H3, 2,
	H5_, 2,
	H3, 2,
	M6, 4+4,
	
	H6, 1,
	M6, 1,
	H1, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	H3, 1,
	H6, 1,
	
	
	0xFF,
};

code unsigned int music4[] = 
{
	H7, 1,
	H2, 1,
	HH1, 1,
	H7, 1,
	
	H6, 1,
	H3, 1,
	HH1, 1,
	H3, 1,
	
	H7, 1,
	H3, 1,
	H5, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	
	H3, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	
	
	H6, 1,
	M6, 1,
	H1, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	HH1, 1,
	H7, 1,
	
	
	H6, 1,
	H3, 1,
	HH1, 1,
	H3, 1,
	
	HH1_, 1,
	H3, 1,
	HH2, 1,
	H3, 1,
	
	HH1_, 1,
	H3, 1,
	HH1, 1,
	H3, 1,
	
	H6, 4,
	
	H6, 1,
	M6, 1,
	H1, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	HH1, 1,
	H7, 1,
	
	
	H6, 1,
	H3, 1,
	HH1, 1,
	H3, 1,
	
	H7, 1,
	H3, 1,
	H5, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	
	H3, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	
	
	H6, 1,
	M6, 1,
	H1, 1,
	H3, 1,
	
	0xFF,
};

code unsigned int music5[] =
{
	H6, 1,
	H1, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	HH1, 1,
	H7, 1,
	
	
	H6, 1,
	H3, 1,
	HH1, 1,
	H3, 1,
	
	HH1_, 1,
	H3, 1,
	HH2, 1,
	H3, 1,
	
	HH1_, 1,
	H3, 1,
	HH1, 1,
	H3, 1,
	
	H6, 4,
	
	H6, 1,
	M6, 1,
	H1, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	HH1, 1,
	H7, 1,
	
	
	H6, 1,
	H3, 1,
	HH1, 1,
	H3, 1,
	
	H7, 1,
	H3, 1,
	H5, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	
	H3, 1,
	H1, 1,
	H5, 1,
	H1, 1,
	
	
	H6, 1,
	M6, 1,
	H1, 1,
	H3, 1,
	
	H6, 1,
	H1, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	H3, 1,
	H6, 1,
	
	H7, 1,
	H2, 1,
	HH1, 1,
	H7, 1,
	
	H6, 4+4,
	0xFF,
};

unsigned int freqNode,musicNode,musicChoice,musicMove;

void musicSelect(unsigned char selection)
{
	if (selection == 1)
	{
		musicChoice = 1;
	} else if(selection == 2)
	{
		musicChoice = 2;
	}
}

void musicUpdate()
{
	if (musicChoice == 1)
	{
		if (music1[musicNode] != 0xFF)
		{
			if (!music1[musicNode])
			{
				//freqNode = music[musicNode];
				musicNode++;
				TR0 = 0;
				Delay(SPEED * music1[musicNode]);
				TR0 = 1;
				musicNode++;
				
				TR0 = 0;
				Delay(10);
				TR0 = 1;
			} else
			{
				freqNode = music1[musicNode];
				musicNode++;
				Delay(SPEED * music1[musicNode]);
				musicNode++;
				
				TR0 = 0;
				Delay(10);
				TR0 = 1;
			}
			
		}	else
		{
			TR0 = 0;
			while(1);
		}
		
	} else if (musicChoice == 2)
	{
		if (musicMove == 0)
		{
			if (music2[musicNode] != 0xFF)
			{
				P2_0 = 0;
				if (!music2[musicNode])
				{
					//freqNode = music[musicNode];
					musicNode++;
					TR0 = 0;
					Delay(SPEED * music2[musicNode]);
					TR0 = 1;
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				} else
				{
					freqNode = music2[musicNode];
					musicNode++;
					Delay(SPEED * music2[musicNode]);
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				}
				
			} else
			{
				musicMove = 3;
				musicNode = 0;
				P2_0 = 1;
			}
		} else if (musicMove == 3)
		{
			if (music3[musicNode] != 0xFF)
			{
				P2_1 = 0;
				if (!music3[musicNode])
				{
					//freqNode = music[musicNode];
					musicNode++;
					TR0 = 0;
					Delay(SPEED * music3[musicNode]);
					TR0 = 1;
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				} else
				{
					freqNode = music3[musicNode];
					musicNode++;
					Delay(SPEED * music3[musicNode]);
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				}
				
			} else
			{
				musicMove = 4;
				musicNode = 0;
				P2_1 = 1;
			}
		} else if (musicMove == 4)
		{
			if (music4[musicNode] != 0xFF)
			{
				P2_2 = 0;
				if (!music4[musicNode])
				{
					//freqNode = music[musicNode];
					musicNode++;
					TR0 = 0;
					Delay(SPEED * music4[musicNode]);
					TR0 = 1;
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				} else
				{
					freqNode = music4[musicNode];
					musicNode++;
					Delay(SPEED * music4[musicNode]);
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				}
			} else
			{
				musicMove = 5;
				musicNode = 0;
				P2_2 = 1;
			}
		} else if (musicMove == 5)
		{
			if (music5[musicNode] != 0xFF)
			{
				P2_3 = 0;
				if (!music5[musicNode])
				{
					//freqNode = music[musicNode];
					musicNode++;
					TR0 = 0;
					Delay(SPEED * music5[musicNode]);
					TR0 = 1;
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				} else
				{
					freqNode = music5[musicNode];
					musicNode++;
					Delay(SPEED * music5[musicNode]);
					musicNode++;
					
					TR0 = 0;
					Delay(10);
					TR0 = 1;
				}
			} else
			{
				musicNode = 0;
				TR0 = 0;
				P2_3 = 1;
				while(1);
			}
		}
	}
}

unsigned int freqLUpdate()
{
	return freqTable[freqNode] % 256;
}

unsigned int freqHUpdate()
{
	return freqTable[freqNode] / 256;
}

void buzz()
{
	buzzer = !buzzer;
}