#ifndef __MUSIC_H__
#define __MUSIC_H__

/**
 * @brief Selects which music track to play.
 *
 * @param selection A numeric identifier for the music track.
 *                  1 or 2 in the current implementation.
 */
void musicSelect(unsigned char);

/**
 * @brief update the music nodes in music list.
 */
void musicUpdate();

/**
 * @brief update correspond music nodes to frequency in timer set up, this is for Low.
 */
unsigned int freqLUpdate();

/**
 * @brief update correspond music nodes to frequency in timer set up, this is for High.
 */
unsigned int freqHUpdate();

/**
 * @brief make buzzer to have buzz sounds.
 */
void buzz();

#endif