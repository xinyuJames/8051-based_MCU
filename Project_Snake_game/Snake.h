#ifndef __SNAKE_H__
#define __SNAKE_H__

void Snake_Init();
void snakeRestart();
void showSnake();
void moveUp();
void moveDown();
void moveRight();
void moveLeft();
void eat();
//void isCollide();
unsigned char isOver();
unsigned char getScore();

#endif