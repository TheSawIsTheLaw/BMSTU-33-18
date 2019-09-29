#include <stdlib.h>

#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_del_row.h"
#include "../../ARRgame/headers/arrgame_headers_pop.h"
#include "../../ARRgame/functions/arrgame_functions_pop.c"


#define INDEX_OUT_OF_RANGE_ERROR 318
#define FALSE_POINTER_ERROR 319
#define REALLOC_ERROR 320
#define OK 0

/*
Deletes chosen row. First row has number 1.

Input data:
* const matrix_t *const matrix - matrix struct where need to delete row.
* const int index_row - index of row to be deleted.

Output data:
* Edited matrix_t sample or return code - INDEX_OUT_OF_RANGE_ERROR or 
FALSE_POINTER_ERROR.
*/

void matr_realloc(int **matrix, int rows)
{
    int **tmp = realloc(matrix, sizeof(int*) * rows);
    if (!tmp)
    {
        return REALLOC_ERROR;
    }
    matrix = tmp;
    return OK;
}


matrix_t *get_by_pos(const matrix_t *const edit_matrix, const int index_row)
{
    if (edit_matrix->rows - 1 < index_row || index_row < 0)
        return INDEX_OUT_OF_RANGE_ERROR;

    for (int row = 0; row < edit_matrix->rows; ++row)
    {
        if (!((edit_matrix->matrix + row))
        {
            return FALSE_POINTER_ERROR;
        }
    }

    free(*(edit_matrix->matrix + index_row));
    *(edit_matrix->matrix + index_row) = NULL;

    edit_matrix->rows -= 1;

    pop_base(edit_matrix->matrix, index_row);
    
    int error = matr_realloc(edit_matrix->matrix, edit_matrix->rows);
    if (error)
        return REALLOC_ERROR;

    return edit_matrix;
}

