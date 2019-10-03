#include <stdio.h>

#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"
#include "../headers/martixgame_headers_del_row.h"

#define PASSED 0
#define FAILED 1

void fill_matrix(matrix_t *const to_fill)
{
    int filled = 1;

    for (int row = 0; row < to_fill->rows; ++row)
    {
        for (int col = 0; col < to_fill->columns; ++col)
        {
            *(*(to_fill->matrix + row) + col) = filled;
        }
        filled++;
    }
}

int count_matrix(matrix_t *const to_fill)
{
    int sum = 0;

    for (int row = 0; row < to_fill->rows; ++row)
    {
        for (int col = 0; col < to_fill->columns; ++col)
        {
            sum = sum + *(*(to_fill->matrix + row) + col);
        }
    }
    return sum;
}

int matrixgame_del_row_test()
{
    /*
    Test case 0. Normal mode.
    */
    matrix_t test_matrix_0;
    create_matrix(&test_matrix_0, 3, 3);
    fill_matrix(&test_matrix_0);

    del_row(&test_matrix_0, 0);

    if (count_matrix(&test_matrix_0) != 15)
    {
        return FAILED;
    }
    free_matrix(&test_matrix_0);
    /*
    Test case 1. Normal mode.
    */
    matrix_t test_matrix_1;
    create_matrix(&test_matrix_1, 5, 5);
    fill_matrix(&test_matrix_1);

    del_row(&test_matrix_1, 4);

    if (count_matrix(&test_matrix_1) != 50)
    {
        return FAILED;
    }
    free_matrix(&test_matrix_1);

    /*
    Test case 2. Normal mode.
    */
    matrix_t test_matrix_2;
    create_matrix(&test_matrix_2, 2, 2);
    fill_matrix(&test_matrix_2);

    del_row(&test_matrix_2, 1);

    if (count_matrix(&test_matrix_2) != 2)
    {
        return FAILED;
    }
    free_matrix(&test_matrix_2);

    /*
    Test case 3. Normal mode.
    */
    matrix_t test_matrix_3;
    create_matrix(&test_matrix_3, 6, 6);
    fill_matrix(&test_matrix_3);

    del_row(&test_matrix_3, 4);

    if (count_matrix(&test_matrix_3) != 96)
    {
        return FAILED;
    }
    free_matrix(&test_matrix_3);

    return PASSED;

}

int main()
{
    if (matrixgame_del_row_test() != PASSED)
    {
        printf("\nTHERE IS SOME FAILED TESTS\n");

        return FAILED;
    }

    printf("\nALL TESTS PASSED\n");

    return PASSED;
}
