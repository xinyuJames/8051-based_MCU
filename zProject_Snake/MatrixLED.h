#ifndef __MATRIXLED_H__
#define __MATRIXLED_H__

/**
 * @brief Initializes the Matrix LED module.
 */
void MLED_Init();

/**
 * @brief Displays a specific column of the LED matrix.
 * 
 * @param column The column index to display.
 * @param rows to display.
 */
void MLED_ShowColumn(unsigned char, unsigned char);

/**
 * @brief Lights up a specific point (LED) on the matrix.
 * 
 * @param x The x-coordinate of the point.
 * @param y The y-coordinate of the point.
 */
void MLED_ShowPoint(unsigned char, unsigned char);

#endif