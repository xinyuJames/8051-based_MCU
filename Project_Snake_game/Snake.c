#include <REGX52.H>
#include <INTRINS.H>
#include <STDLIB.H>
#include "MatrixLED.h"

//coordinate of snake start from (1,1), x and y
unsigned char snake[40][2] = {{1, 1}, {1, 2}};
unsigned char food[2];
unsigned char previousHeadNode[2];
unsigned char previousNode[2];
unsigned char snakeLen = 2;
unsigned char gameOver;

void eat();	
void generateFood();
void isCollide();

//initialize snake
void Snake_Init()
{
	generateFood();
}

//restart the snake game, reset parameters
void snakeRestart()
{
	unsigned int i;
	for (i = 0; i < 40; i++)
	{
		if (i == 0) {snake[i][0] = 1; snake[i][1] = 1;}
		else if (i == 1) {snake[i][0] = 1; snake[i][1] = 2;}
		else {snake[i][0] = 0; snake[i][1] = 0;}
	}
	snakeLen = 2;
	gameOver = 0;
}

//show snake body to the screen
void showSnake()
{
	unsigned char i;
	for (i = 0; i < snakeLen; i++)
	{
		MLED_ShowPoint(snake[i][0], snake[i][1]);
	}
	
	MLED_ShowPoint(food[0], food[1]);
}
	
//all the functions below should modify snake array in one unit of time
void bodyFollow()
{
	unsigned int i;
	
	for (i = 0; i < snakeLen - 2; i++)
	{
		snake[i][0] = snake[i+1][0];
		snake[i][1] = snake[i+1][1];
	}
	snake[snakeLen - 2][0] = previousHeadNode[0];
	snake[snakeLen - 2][1] = previousHeadNode[1];
}	

void moveUp()
{
	//store previous node
	previousNode[0] = snake[0][0];
	previousNode[1] = snake[0][1];
	//store previous head node
	previousHeadNode[0] = snake[snakeLen - 1][0];
	previousHeadNode[1] = snake[snakeLen - 1][1];
	//head of snake move up
	snake[snakeLen - 1][1] += 1;
	//the body follow up with head
	bodyFollow();
	isCollide();
	//see if snake can eat
	eat();
}

void moveDown()
{
	previousNode[0] = snake[0][0];
	previousNode[1] = snake[0][1];
	previousHeadNode[0] = snake[snakeLen - 1][0];
	previousHeadNode[1] = snake[snakeLen - 1][1];
	snake[snakeLen - 1][1] -= 1;
	bodyFollow();
	isCollide();
	eat();
}

void moveLeft()
{
	previousNode[0] = snake[0][0];
	previousNode[1] = snake[0][1];
	previousHeadNode[0] = snake[snakeLen - 1][0];
	previousHeadNode[1] = snake[snakeLen - 1][1];
	snake[snakeLen - 1][0] -= 1;
	bodyFollow();
	isCollide();
	eat();
}

void moveRight()
{
	previousNode[0] = snake[0][0];
	previousNode[1] = snake[0][1];
	previousHeadNode[0] = snake[snakeLen - 1][0];
	previousHeadNode[1] = snake[snakeLen - 1][1];
	snake[snakeLen - 1][0] += 1;
	bodyFollow();
	isCollide();
	eat();
}

//determine if has food, and eat if yes, and then generate new food
void eat()
{
	unsigned int i;
	
	if (snake[snakeLen - 1][0] == food[0] && snake[snakeLen - 1][1] == food[1])
	{
		//snake array enlength a unit
		for (i = snakeLen; i > 0; i--)
		{
			snake[i][0] = snake[i - 1][0];
			snake[i][1] = snake[i - 1][1];
		}
		//add in the previous node to tail
		snake[0][0] = previousNode[0];
		snake[0][1] = previousNode[1];
		
		snakeLen++;
		
		if (snakeLen == 39)
		{
			gameOver = 1;
		} else
		{
			generateFood();
		}
		
	}
}

//determine if snake collide with itself or wall
void isCollide()
{
	unsigned int i;
	
	
	if (snake[snakeLen - 1][0] > 8 || snake[snakeLen - 1][0] <= 0 || snake[snakeLen - 1][1] > 8 || snake[snakeLen - 1][1] <= 0)
	{
		gameOver = 1;
	}
	
	for (i = 0; i < snakeLen - 1; i++)
	{
		if (snake[snakeLen - 1][0] == snake[i][0] && snake[snakeLen - 1][1] == snake[i][1])
		{
			gameOver = 1;
			break;
		}
	}
}

unsigned char isOver()
{
	return gameOver;
}

void generateFood()
{
	unsigned char newX, newY, isOverlap, i;
	
	do
	{
		//make sure x and y range from 1-8
		newX = (rand() % 8) + 1;
    newY = (rand() % 8) + 1;
		
		//make sure new food is not overlapping body
		isOverlap = 0;
		for (i = 0; i < snakeLen; i++)
		{
			if (snake[i][0] == newX && snake[i][1] == newY)
			{
				isOverlap = 1;
				break;
			}
		}
		
	} while(isOverlap);
	
	//assign value to food
	food[0] = newX;
	food[1] = newY;
}

unsigned char getScore()
{
	return snakeLen;
}