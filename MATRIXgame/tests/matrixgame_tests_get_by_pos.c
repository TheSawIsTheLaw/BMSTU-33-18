#include "../headers/matrixgame_headers_get_by_pos.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"

#define PASSED 0
#define FAILED 1

void fill_matrix(matrix_t *const to_fill)
{
    for (int row = 0; row < to_fill->rows; ++row)
    {
        for (int col = 0; col < to_fill->columns; ++col)
        {
            *(*(to_fill->matrix + row) + col) = col + col * to_fill->rows;
        }
    }
}

int matrixgame_get_by_pos_test()
{
    int err_cnt = 0;

    matrix_t test_matrix_1;
    create_matrix(&test_matrix_1, 5, 5);
    fill_matrix(&test_matrix_1);

    /*if (get_by_pos(&test_matrix_1, 0, 3) != 3)
    {
        err_cnt++;
    }*/

    free_matrix(&test_matrix_1);

    if (err_cnt)
    {
        return FAILED;
    }

    return PASSED;
}

int main()
{
    if (matrixgame_get_by_pos_test() != PASSED)
    {
        return FAILED;
    }

    return PASSED;
}
