#include <stdlib.h>
#include <stdio.h>

#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/martixgame_headers_del_row.h"
#include "../headers/matrixgame_headers_create_matrix.h"


#define INDEX_OUT_OF_RANGE_ERROR 318
#define FALSE_POINTER_ERROR 319
#define REALLOC_ERROR 320
#define OK 0

/*
Deletes chosen row. First row has number 1.

Input data:
* matrix_t *matrix - matrix struct where need to delete row.
* const int index_row - index of row to be deleted.

Output data:
* Return code - INDEX_OUT_OF_RANGE_ERROR or 
FALSE_POINTER_ERROR or REALLOC_ERROR.
*/

int matr_realloc(matrix_t *matrix)
{
    int **tmp = realloc(matrix->matrix, sizeof(int*) * matrix->rows);
    if (!tmp)
        return REALLOC_ERROR;
    matrix->matrix = (int**)tmp;
    tmp = NULL;
    return OK;
}

void remove_matrix(matrix_t *matrix, const int i_row)
{
    for (int i = i_row; i < matrix->rows - 1; i++)
    {
        *(matrix->matrix + i) = *(matrix->matrix + i + 1);
    }
}

int del_row(matrix_t *edit_matrix, const int index_row)
{
    if (edit_matrix->rows - 1 < index_row || index_row < 0)
        return INDEX_OUT_OF_RANGE_ERROR;

    for (int row = 0; row < edit_matrix->rows; ++row)
    {
        if (!(*(edit_matrix->matrix + row)))
        {
            return FALSE_POINTER_ERROR;
        }
    }

    *(edit_matrix->matrix + index_row) -= 3;
    free(*(edit_matrix->matrix + index_row));
    remove_matrix(edit_matrix, index_row);
    
    edit_matrix->rows -= 1;

    int error = matr_realloc(edit_matrix);
    if (error)
        return REALLOC_ERROR;

    return OK;
}


/*int main(void)
{
    matrix_t matrix;
    int check;

    check = create_matrix(&matrix, 10, 10);

    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            matrix.matrix[i][j] =  i;
        }
    }

    printf("\n\n");
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            printf("%d ", matrix.matrix[i][j]);
        }
        printf("\n\n");
    }

    check = del_row(&matrix, 8);     

    printf("\n\n");
    for (int i = 0; i < matrix.rows; i++)
    {
        for (int j = 0; j < matrix.columns; j++)
        {
            printf("%d ", matrix.matrix[i][j]);
        }
        printf("\n\n");
    }

    for (int i = 0; i < matrix.rows; i++)
    {
        free(*(matrix.matrix + i) - 3);
    }

    free(matrix.matrix);
    return 0;
}*/