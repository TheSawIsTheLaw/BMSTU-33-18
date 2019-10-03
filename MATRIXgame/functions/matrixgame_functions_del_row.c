#include <stdlib.h>
#include <stdio.h>

#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/martixgame_headers_del_row.h"

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

int **matr_realloc(int **matrix, const int rows)
{
    int **tmp;
    tmp = (int**)realloc(matrix, sizeof(int*) * rows);
    
    if (!tmp)
        return NULL;

    matrix = tmp;
    tmp = NULL;

    return matrix;
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
    
    free(*(edit_matrix->matrix + index_row));
    *(edit_matrix->matrix + index_row) = NULL;
    
    edit_matrix->rows -= 1;
    
    for (int i = index_row; i < edit_matrix->rows; i++)
        *(edit_matrix->matrix + i) = *(edit_matrix->matrix + i + 1);
    
    int** ok = matr_realloc(edit_matrix->matrix, edit_matrix->rows);
    if (!ok)
    {
        return REALLOC_ERROR;
    }
    
    return OK;
}
