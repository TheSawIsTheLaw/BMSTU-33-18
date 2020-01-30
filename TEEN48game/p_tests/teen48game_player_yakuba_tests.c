#include <matrixgame.h>

#include "../p_headers/teen48game_player_yakuba.h"
#include "../f_headers/teen48game_to_step.h"
#include "../f_headers/teen48game_gorandom.h"

void fill(matrix_t *const matrix)
{
    for (int row = 0; row < matrix->rows; ++row)
    {
        for (int col = 0; col < matrix->columns; ++col)
        {
            *(*(matrix->matrix + row) + col) = 0;
        }
    }
}

void kill_me(void)
{
    int satan = 666;
    matrix_t playfield;
    matrixgame_create_matrix(&playfield, satan, satan);
    fill(&playfield);

    gorandom(&playfield);
    gorandom(&playfield);

    while (satan)
    {
        teen48game_player_yakuba(&playfield, to_step);
        gorandom(&playfield);
        satan--;
    }

    matrixgame_free_matrix(&playfield);
}

int main()
{
    kill_me();

    return 0;
}
