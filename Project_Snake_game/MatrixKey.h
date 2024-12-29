/*
Header file for matrix keys
*/
#ifndef __MATRIXKEY_H__
#define __MATRIXKEY_H__

/**
 * @brief Reads user input from a 4x4 matrix keypad.
 * @param N/A
 * @return The key value corresponding to the button pressed by the user 
 *         (1 to 16), or 0 if no key is pressed.
 */
unsigned char getMKey();

#endif