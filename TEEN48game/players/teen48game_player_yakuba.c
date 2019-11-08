#include <stdlib.h>
#include "../p_headers/teen48game_player_yakuba.h"

static int smert = 0;

char teen48game_player_yakuba(matrix_t *matrix, int (*to_step)(matrix_t *const, const char))
{
    if (!smert)
    {
        smert++;
        return 'r';
    }
    else if (smert == 1)
    {
        smert++;
        return 'u';
    }
    else if (smert == 2)
    {
        smert++;
        return 'l';
    }
    else if (smert == 3)
    {
        smert++;
        return 'l';
    }
    else
    {
        smert = 0;
        return 'd';
    }
}
