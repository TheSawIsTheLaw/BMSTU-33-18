#include "../p_headers/teen48game_player_nitenko.h"
#include "../f_headers/teen48game_to_step.h"

#include <stdlib.h>

static char lastmove = 'u';
/*
static char aids(matrix_t ss, const char bab)
{
    return 'a';
}*/

char teen48game_player_nitenko(matrix_t *matrix, int (*to_step)(matrix_t *const, const char))
{
    int ra;

    if (lastmove == 'u')
    {
        srand(1234);
        lastmove = 'd';
        return 'd';
    }
    if (lastmove == 'l' || lastmove == 'r')
    {
        lastmove = 'd';
        return 'd';
    }
    if (lastmove == 'd')
    {
        ra = rand() % 2;
        if (ra == 0)
        {
            lastmove = 'r';
            return 'r';
        }
        else
        {
            lastmove = 'l';
            return 'l';
        }        
    }
    
    return 'd';
}

/*int main()
{
    matrix_t *joj;
    for (int i = 0; i < 10; i++)
        printf("%c ", teen48game_player_nitenko(joj, aids));

    matrix_t sample_state;

    matrixgame_create_matrix(&sample_state, 4, 4);

    sample_state.matrix[0][0] = 0;
    sample_state.matrix[0][1] = 2;
    sample_state.matrix[0][2] = 2;
    sample_state.matrix[0][3] = 2;
    
    sample_state.matrix[1][0] = 4;
    sample_state.matrix[1][1] = 0;
    sample_state.matrix[1][2] = 0;
    sample_state.matrix[1][3] = 0;
    
    sample_state.matrix[2][0] = 0;
    sample_state.matrix[2][1] = 0;
    sample_state.matrix[2][2] = 0;
    sample_state.matrix[2][3] = 0;

    sample_state.matrix[3][0] = 0;
    sample_state.matrix[3][1] = 0;
    sample_state.matrix[3][2] = 0;
    sample_state.matrix[3][3] = 0;
    char move;
    for (int i = 0; i < 10; i++)
    {
        print_matrix(&sample_state, 0);
        scanf("%c\n", &move);
        printf("resulting move is %c\n", move);
        
        to_step(&sample_state, move);

        
    }


    matrixgame_free_matrix(&sample_state);
    printf("FINISHED\n");

    return 0;
}*/