#include <stdlib.h>
#include <matrixgame.h>
#include "../p_headers/teen48game_player_romanov.h"

#define STACK_UP(curr) *((curr) + i)
#define STACK_DOWN(curr) *((curr) - i)
#define STACK_STEP 5000

char teen48game_player_romanov(matrix_t *const matrix, int (*func)(matrix_t *const, const char))
{
    int curr = 0xDEADBEEF;

    for (int i = 0; i < STACK_STEP; i++)
    {
        if (STACK_UP(&curr) == 'u' || STACK_UP(&curr) == 'r' || 
            STACK_UP(&curr) == 'l' || STACK_UP(&curr) == 'd')
        {
            return STACK_UP(&curr);
        }
    }

    for (int i = 0; i < STACK_STEP; i++)
    {
        if (STACK_DOWN(&curr) == 'u' || STACK_DOWN(&curr) == 'r' || 
            STACK_DOWN(&curr) == 'l' || STACK_DOWN(&curr) == 'd')
        {
            return STACK_DOWN(&curr);
        }
    }

    return 'l';
}
