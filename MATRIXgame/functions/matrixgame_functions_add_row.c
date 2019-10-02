#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrixgame_headers_add_row.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define OK                      0
#define ALLOC_ERROR            -1
#define INDEX_OUT_OF_THE_RANGE -2
#define EMPTY_POINTER          -3

int my_realloc(matrix_t *matrix)
{
    matrix->rows += 1;
    matrix->matrix = (int**)realloc(matrix->matrix,matrix->rows * sizeof(int*));

    if (matrix->matrix == NULL)
    {
        for (int i = 0; i < matrix->rows; i++)
            free(*((matrix->matrix)+ i));

        return ALLOC_ERROR;
    }

    return OK;
}

int add_row(matrix_t *matrix, const int index)
{
    int rc = OK;

    if (matrix->rows + 1 < index || index < 0)
    {
        rc = INDEX_OUT_OF_THE_RANGE;

        return rc;
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        if ((matrix->matrix + i) == NULL)
        {
            rc = EMPTY_POINTER;

            return rc;
        }
    }

    rc = my_realloc(matrix);

    if (rc != OK)
        return rc;

    // Сдвигаем строки
    for (int i = matrix->rows; i > index; i--)
        *(matrix->matrix + i) = *(matrix->matrix + i - 1);

    // Обнуляем новую строку
    for (int j = 0; j < matrix->columns; ++j)
        *(*((matrix->matrix) + index) + j) = 0;

    return rc;
}

