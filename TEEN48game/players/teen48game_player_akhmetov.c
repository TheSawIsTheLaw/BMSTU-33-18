#include "../p_headers/teen48game_player_akhmetov.h"
#include <stdlib.h>

#define ERROR 0

char teen48game_player_akhmetov(matrix_t *const matrix_buffer, int(*to_step)(matrix_t *const, const char))
{
    int choice = rand() % 6;
    switch (choice)
    {
        case 5:
            return 'l';
        case 4:
            return 'r';
        case 0:
            return 'r';
        case 1:
            return 'l';
        case 2:
            return 'd';
        case 3:
            return 'u';
    }
    return ERROR;
}
