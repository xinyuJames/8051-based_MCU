#include <REGX52.H>
#include "Delay.h"
#include "MLED_Lib.h"
#include "MatrixLED.h"
#include "MatrixKey.h"
#include "Snake.h"
#include "Timer0.h"

//TODO: 1. difficulty selection
//IDEA: 1. use independent button do move, use matrix to restart, so we can use buzzer
unsigned char key;
unsigned char movementMode = 1; //1 - up; 2 - down; 3 - left; 4 - right
unsigned char level = 0;

void Key_Input();
void levelSelection();

void main()
{
	unsigned int i;
	
	MLED_Init();
	Snake_Init();
	Timer0_Init();
	while(1)
	{
		if (isOver())
		{
			if (isWin())
			{
				//go into win page
				for (i = 0; i < 50; i ++)
				{
					showSnake();
				}
				MLEDShow_WIN();	
				MLEDShow_SCORE(getScore());
				
				//after displaying win page, waiting to restart
				while(isOver())
				{
					MLEDShow_SMILE();
					Key_Input();
				}
				
			} else
			{
				//go into game over page
				for (i = 0; i < 50; i ++)
				{
					showSnake();
				}
				MLEDShow_GAMEOVER();	
				MLEDShow_SCORE(getScore());
				
				//after displaying game over page, waiting to restart
				while(isOver())
				{
					MLEDShow_SAD();
					Key_Input();
				}
			}
			
		} else
		{
			//select level first
			levelSelection();
			//game playing phase
			Key_Input();
			showSnake(); //show snake body and food	
		}
		
	}
}

void Timer0_Routine() interrupt 1
{
	//timer setup
	static unsigned int count;
	TL0 = 0x66; 
	TH0 = 0xFC;
	count++;
	
	//refresh rate 500ms
	if (level)
	{
		if (count >= (5 - level) * 250)
		{
			if (!isOver())
			{
				if (movementMode == 1) {moveUp();}
				if (movementMode == 2) {moveDown();}	
				if (movementMode == 3) {moveLeft();}
				if (movementMode == 4) {moveRight();}
			}
			//change status of snake
				
			count = 0;
		}
	}
	
}




//identify key input
void Key_Input()
{	
	key = getMKey();
	
	if (level)
	{
		//press 16 in matrix button to restart the game
		if(key)
		{
			if (key == 16)
			{
				snakeRestart();
				movementMode = 1;
				level = 0;
			}
			//take input of movement if restart is not pressed
			if (key == 2)
			{
				movementMode = 1;
			} else if (key == 10)
			{
				movementMode = 2;
			} else if (key == 5)
			{
				movementMode = 3;
			} else if (key == 7)
			{
				movementMode = 4;
			}
		}
	} else
	{
		if (P3_1 == 0)
		{
			Delay(20);
			while(P3_1 == 0);
			Delay(20);
			level = 1;
		}
		if (P3_0 == 0)
		{
			Delay(20);
			while(P3_0 == 0);
			Delay(20);
			level = 2;
		}
		if (P3_2 == 0)
		{
			Delay(20);
			while(P3_2 == 0);
			Delay(20);
			level = 3;
		}
		if (P3_3 == 0)
		{
			Delay(20);
			while(P3_3 == 0);
			Delay(20);
			level = 4;
		}
	}
	
}

void levelSelection()
{
	
	while (!level)
	{
		MLEDShow_TITLE();
		Key_Input();
	}
}