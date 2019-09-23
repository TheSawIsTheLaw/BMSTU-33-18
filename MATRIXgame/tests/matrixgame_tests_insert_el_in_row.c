#include "../headers/matrixgame_headers_insert_el_in_row.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define PASSED 0
#define FAILED 1

int matrixgame_insert_el_in_row_test()
{
    matrix_t matrix;
    
    matrix.rows = 3
    matrix.columns = 4
    matrix.matrix = (int **) malloc(matrix.rows * sizeof(int *));
    for (int i = 0; i < matrix.rows; i++)
        (matrix.matrix)[i] = (int *) malloc(matrix.columns * sizeof(int));
}

int main()
{
    if (matrixgame_<имя_вашей_функции>_test() != PASSED)
    {
        return FAILED;
    }

    return PASSED;
}

