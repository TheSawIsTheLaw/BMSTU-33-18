#ifndef __TEEN48GAME_CALL_PLAYERS_FUNCS_H__
#define __TEEN48GAME_CALL_PLAYERS_FUNCS_H__

#include <matrixgame.h>
#include <inttypes.h>

#define N 100

void call_players_funcs(matrix_t *players_matrices, matrix_t *matrix_buffer,
    char (**players_funcs_ptr)(matrix_t *const, int (*)(matrix_t *const, const char)),
    uint64_t *players_time, char players_names[][N]);

#endif
