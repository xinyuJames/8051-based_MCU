#ifndef __SNAKE_H__
#define __SNAKE_H__

/**
 * @brief Initializes the Snake game, setting up the game and snake's initial state.
 */
void Snake_Init();

/**
 * @brief Restarts the game, resetting the snake and the game environment to the starting state.
 */
void snakeRestart();

/**
 * @brief Displays the snake and game board on the matrix LED.
 */
void showSnake();

/**
 * @brief Moves the snake one step up.
 */
void moveUp();

/**
 * @brief Moves the snake one step down.
 */
void moveDown();

/**
 * @brief Moves the snake one step to the right.
 */
void moveRight();

/**
 * @brief Moves the snake one step to the left.
 */
void moveLeft();

/**
 * @brief Handles the logic for when the snake eats a food item, growing the snake and updating the score.
 */
void eat();

/**
 * @brief Checks if the game is over (e.g., snake hits a wall or itself).
 * @return 1 if the game is over, 0 otherwise.
 */
unsigned char isOver();

/**
 * @brief Checks if the player has won the game, in this game, score of 32 count as win.
 * @return 1 if the player has won, 0 otherwise.
 */
unsigned char isWin();

/**
 * @brief Gets the current score of the game.
 * @return The score as an unsigned char.
 */
unsigned char getScore();

#endif