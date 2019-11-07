#ifndef STATISTICS_H

#define STATISTICS_H

#include "../../MATRIXgame/headers/matrixgame.h"

#include <inttypes.h>

// структура для хранения информации
// Об индексе игрока и его счете
typedef struct
{
    int index;
    int score;
} score_t;

#define NOP 14 // number of players == 10 ?
#define MAX_LEN_SURNAME 100

void live_print(matrix_t *const matrix_array, char surname_array[NOP][MAX_LEN_SURNAME], uint64_t *timer_array, uint64_t timer_limit);
void print_result(const matrix_t *matrix_array, char surname_array[NOP][MAX_LEN_SURNAME]);

#endif