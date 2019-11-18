#include <matrixgame.h>
#include <stdlib.h>
#include "../f_headers/teen48game_to_step.h"
#include "../p_headers/teen48game_player_minenko.h"

#define ITER 6
#define OK 0
#define FAIL -1

static int cycle = -1;

char make_move_minenko(matrix_t const *field, int (*to_step)(matrix_t *const, const char))
{   
    cycle += 1;

    if (cycle > ITER * 3)
    {
        cycle = -1;
        return 'r';
    }

    if (cycle % ITER == 0)
        return 'l';
    else
        return 'd';
}

int main()
{
    matrix_t field;
    matrixgame_create_matrix(&field, 4, 4);

    for (int i = 0; i < field.rows; i++)
        for (int j = 0; j < field.columns; j++)
            *(*(field.matrix + i) + j) = 2;

    for (int i = 0; i < 100; i++)
    {
        char res = make_move_minenko(&field, to_step);

        if (!((res == 'u') || (res == 'd') || (res == 'l') || (res == 'r')))
        {
            printf("fail!!! %c ", res);
            return FAIL;
        }
    }
    printf("oki-doki");
    return 0;
}