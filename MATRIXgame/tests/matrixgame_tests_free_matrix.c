#include "../headers/matrixgame_headers_free_matrix.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#include<stdlib.h>

#define OK 0
#define SOME_ARE_NULL 507
#define MAIN_POINTER_NULL 411

#define PASSED 0
#define FAILED 1

int matrixgame_functions_free_matrix_test_1()
{
    matrix_t tmp_matrix;

    tmp_matrix.rows = 3;
    tmp_matrix.columns = 3;

    tmp_matrix.matrix = (int **) malloc(tmp_matrix.rows * sizeof(int *));
    for (int i = 0; i < tmp_matrix.rows; i++)
        (tmp_matrix.matrix)[i] = (int *) malloc(tmp_matrix.columns * sizeof(int));

    if (free_matrix(&tmp_matrix) == OK)
        return PASSED;

    return FAILED;
}

/*int matrixgame_functions_free_matrix_test_2()
{
    matrix_t tmp_matrix;

    if (free_matrix(&tmp_matrix) == MAIN_POINTER_NULL)
        return PASSED;

    return FAILED;
}*/

int matrixgame_functions_free_matrix_test_3()
{
    matrix_t tmp_matrix;
    tmp_matrix.rows = 3;

    tmp_matrix.matrix = (int **) malloc(tmp_matrix.rows * sizeof(int *));

    if (free_matrix(&tmp_matrix) == SOME_ARE_NULL)
        return PASSED;

    return FAILED;
}

int main()
{
    if (matrixgame_functions_free_matrix_test_1() != PASSED)
    {
        return FAILED;
    }

    if (matrixgame_functions_free_matrix_test_2() != PASSED)
    {
        return FAILED;
    }

    if (matrixgame_functions_free_matrix_test_3() != PASSED)
    {
        return FAILED;
    }

    return PASSED;
}
