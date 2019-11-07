/**
 * \file teen48game_gorandom.c
 * \brief Пресвятой рандомайзер
 */

#include <arrgame.h>
#include <matrixgame.h>

#include <time.h>
#include <stdlib.h>

/**
 * \fn int teen_random(const int offset)
 *
 * \param const int offset - offset from current system time
 *
 * \brief Random system based on DOOM random seed
 *
 * \return Random number
 */
/*
Random system based on DOOM random seed.

Input data:
* const int offset - offset from current system time.

Output data:
* Random number.
*/
int teen_random(const int offset)
{
    int doom_seed[] = {
        151,160,137,91,90,15,131,13,201,95,96,53,194,233,7,225,140,36,103,30,
        69,142,8,99,37,240,21,10,23,190,6,148,247,120,234,75,0,26,197,62,94,
        252,219,203,117,35,11,32,57,177,33,8,237,149,56,87,174,20,125,136,171,
        168,68,175,74,165,71,134,139,48,27,166,77,146,158,231,83,111,229,122,
        60,211,133,230,220,105,92,41,55,46,245,40,244,102,143,54,65,25,63,161,
        1,216,80,73,209,76,132,187,208,89,18,169,200,196,135,130,116,188,159,
        86,164,100,109,198,173,186,3,64,52,217,226,250,124,123,5,202,38,147,
        118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,223,183,
        170,213,119,248,152,2,44,154,163,70,221,153,101,155,167,43,172,9,129,
        22,39,253,9,98,108,110,79,113,224,232,178,185,112,104,218,246,97,228,
        251,34,242,193,238,210,144,12,191,179,162,241,81,51,145,235,249,14,239,107,
        49,192,214,31,181,199,106,157,184,84,204,176,115,121,50,45,127,4,150,254,
        138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
    };

    time_t now = time(0) + offset + doom_seed[offset % 256];
    int seed = now % 256;

    return abs(doom_seed[seed] + doom_seed[(seed + 1) % 256] - doom_seed[(seed + 2) % 256]);
}

/**
 * \fn int get_empty_tiles(const matrix_t playfield)
 *
 * \param const matrix_t playfield - matrix to be checked
 *
 * \brief Get amount of empty tiles in matrix
 *
 * \return Amount of empty tiles
 */
/*
Get amount of empty tiles in matrix.

Input data:
* const matrix_t playfield - matrix to be checeked.

Output data:
* Amount of empty tiles.
*/
int get_empty_tiles(const matrix_t playfield)
{
    int empty_tiles = 0;

    for (int row = 0; row < playfield.rows; ++row)
    {
        for (int col = 0; col < playfield.columns; ++col)
        {
            if (*(*(playfield.matrix + row) + col) == 0)
            {
                empty_tiles++;
            }
        }
    }

    return empty_tiles;
}

/**
 * \fn void gorandom(matrix_t *const playfield)
 *
 * \param matrix_t *const playfield - matrix to be filled
 *
 * \brief Fill matrix playfield with 4 (10% chance) or 2 (90% chance)
 */
/*
Fill matrix playfield with 4 (10% chance) or 2 (90% chance).

Input data:
* matrix_t *const playfield - matrix to be filled.
*/
void gorandom(matrix_t *const playfield)
{
    int empty_tiles = get_empty_tiles(*playfield);

    if (!empty_tiles)
    {
        return;
    }

    int random = teen_random(empty_tiles) % empty_tiles;
    int tile = (!(teen_random(empty_tiles) % 9)) ? 4 : 2;

    for (int row = 0; row < playfield->rows; ++row)
    {
        for (int col = 0; col < playfield->columns; ++col)
        {
            if (!(*(*(playfield->matrix + row) + col)) && random)
            {
                --random;
            }
            else
            {
                if (!(*(*(playfield->matrix + row) + col)) && !random)
                {
                    *(*(playfield->matrix + row) + col) = tile;

                    return;
                }
            }
        }
    }
}
