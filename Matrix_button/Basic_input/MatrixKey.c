/*
Source codes for matrix keys

ps. so sad that I cannot use array to store them, whats a quicker way?
*/
#include <REGX52.H>
#include "Delay.h"

unsigned char matrixKey()
{
	unsigned char key = 0;
//	
//	unsigned char *columns[4] = {&P1_3, &P1_2, &P1_1, &P1_0};
//	unsigned char *rows[4] = {&P1_7, &P1_6, &P1_5, &P1_4};
//	unsigned char keys[4][4] = {{1, 2, 3, 4},{5, 6, 7, 8},{9, 10, 11, 12}, {13, 14, 15, 16}};
//	
//	for (int i = 0; i < 4; i++)
//	{
//		P1 = 0xFF;
//		*columns[i] = 0;
//		for (int j = 0; j < 4, j++)
//		{
//			if (*rows[j] == 0)
//			{
//				Delay(20);
//				while(*row[j] == 0);
//				Delay(20);
//				
//				key = keys[i][j];
//			}
//			
//		}
//	}

	P1 = 0xFF;
	P1_3 = 0;
	if (P1_7 == 0) {Delay(20); while(P1_7 == 0){Delay(20); key = 1;}}
	if (P1_6 == 0) {Delay(20); while(P1_6 == 0){Delay(20); key = 5;}}
	if (P1_5 == 0) {Delay(20); while(P1_5 == 0){Delay(20); key = 9;}}
	if (P1_4 == 0) {Delay(20); while(P1_4 == 0){Delay(20); key = 13;}}
	
	P1 = 0xFF;
	P1_2 = 0;
	if (P1_7 == 0) {Delay(20); while(P1_7 == 0){Delay(20); key = 2;}}
	if (P1_6 == 0) {Delay(20); while(P1_6 == 0){Delay(20); key = 6;}}
	if (P1_5 == 0) {Delay(20); while(P1_5 == 0){Delay(20); key = 10;}}
	if (P1_4 == 0) {Delay(20); while(P1_4 == 0){Delay(20); key = 14;}}
	
	P1 = 0xFF;
	P1_1 = 0;
	if (P1_7 == 0) {Delay(20); while(P1_7 == 0){Delay(20); key = 3;}}
	if (P1_6 == 0) {Delay(20); while(P1_6 == 0){Delay(20); key = 7;}}
	if (P1_5 == 0) {Delay(20); while(P1_5 == 0){Delay(20); key = 11;}}
	if (P1_4 == 0) {Delay(20); while(P1_4 == 0){Delay(20); key = 15;}}
	
	P1 = 0xFF;
	P1_0 = 0;
	if (P1_7 == 0) {Delay(20); while(P1_7 == 0){Delay(20); key = 4;}}
	if (P1_6 == 0) {Delay(20); while(P1_6 == 0){Delay(20); key = 8;}}
	if (P1_5 == 0) {Delay(20); while(P1_5 == 0){Delay(20); key = 12;}}
	if (P1_4 == 0) {Delay(20); while(P1_4 == 0){Delay(20); key = 16;}}
	
	return key;
}