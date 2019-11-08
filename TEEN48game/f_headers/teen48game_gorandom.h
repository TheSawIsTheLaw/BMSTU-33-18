#ifndef __TEEN48GAME_GORANDOM_H__
#define __TEEN48GAME_GORANDOM_H__

#include <matrixgame.h>

int teen_random(const int offset);

int get_empty_tiles(const matrix_t playfield);

void gorandom(matrix_t *const playfield);

#endif