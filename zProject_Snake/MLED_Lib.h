#ifndef __MLED_LIB_H__
#define __MLED_LIB_H__

/**
 * @brief Displays the "GAME OVER" message on the LED matrix.
 */
void MLEDShow_GAMEOVER();

/**
 * @brief Displays the current score on the LED matrix.
 * @param score The score to be displayed as an unsigned char.
 */
void MLEDShow_SCORE(unsigned char);

/**
 * @brief Displays the title or welcome message on the LED matrix.
 */
void MLEDShow_TITLE();

/**
 * @brief Displays the "WIN" message on the LED matrix, indicating the player has won.
 */
void MLEDShow_WIN();

/**
 * @brief Displays a smiling face on the LED matrix.
 */
void MLEDShow_SMILE();

/**
 * @brief Displays a sad face on the LED matrix.
 */
void MLEDShow_SAD();

#endif




