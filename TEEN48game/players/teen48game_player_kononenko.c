#include <stdlib.h>
#include "../p_headers/teen48game_player_kononenko.h"
#include "../f_headers/teen48game_gorandom.h"

#define COUNT_MOVES 4

char teen48game_player_kononenko(matrix_t *matrix, int (*to_step)(matrix_t *const, const char))
{
    char move = teen_random(COUNT_MOVES) % COUNT_MOVES;

    switch (move)
    {
        case 0:
            return 'l';
        case 1:
            return 'r';
        case 2:
            return 'u';
        default:
            return 'b';
    }
}
