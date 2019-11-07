#include <matrixgame.h>
#include <stdlib.h>
#include "../f_headers/teen48game_to_step.h"
#include "../p_headers/teen48game_player_minenko.h"

#define ITER 6

static int cycle = 0;

char teen48game_player_minenko(matrix_t *const matrix, int (*func)(matrix_t *const, const char))
{   
    if (cycle % ITER == 0)
        return 'l';
    else
        return 'd';
    
    cycle += 1;
    printf("%d ", cycle);
    if (cycle > ITER * 3 + 1)
    {
        cycle = 0;
        return 'r';
    }
}

/*
int main()
{
    matrix_t field;
    matrixgame_create_matrix(&field, 4, 4);
    matrixgame_input_matrix(&field);

    for (int i = 0; i < 100; i++)
    {
        char res = make_move_minenko(&field, to_step);
        printf("%c\n", res);
    }

    return 0;
}
*/