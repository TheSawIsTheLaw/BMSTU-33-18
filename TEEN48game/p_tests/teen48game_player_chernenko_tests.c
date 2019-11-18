#include "../f_headers/teen48game_to_step.h"
#include "../f_headers/teen48game_gorandom.h"
#include "../functions/teen48game_to_step.c"
#include "../functions/teen48game_gorandom.c"
#include "../p_headers/teen48game_player_chernenko.h"

void play_once(void)
{
    matrix_t sample_state;

    matrixgame_create_matrix(&sample_state, 4, 4);

    gorandom(&sample_state);

    char move;
    do {
        move = teen48game_player_chernenko(&sample_state, to_step);
        
        to_step(&sample_state, move);

        gorandom(&sample_state);
        
    } while (move != -1);
	print_matrix(&sample_state, 0);    
    matrixgame_free_matrix(&sample_state);
}

int main(void)
{
    play_once();

    if (super_errno)
        return super_errno;
    
    return 0;
}
