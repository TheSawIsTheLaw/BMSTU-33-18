#include "../p_headers/teen48game_player_sverdlov.h"
#include <stdlib.h>
#define SUCCESS 0

char teen48game_player_sverdlov(matrix_t *const matrix_buffer, int (*to_step)(matrix_t *const, const char))
{
    int direction_selection = rand() % 200;
    
    if (direction_selection < 50)
        return 'r';
    
    else if (direction_selection < 100)
        return 'l';
    
    else if (direction_selection < 150)
        return 'd';
    
    else if (direction_selection < 200)
        return 'u';
    
    return SUCCESS;
}
