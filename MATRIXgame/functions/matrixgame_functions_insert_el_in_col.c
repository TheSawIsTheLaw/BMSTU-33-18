#include <stdlib.h>

#include "../headers/matrixgame_headers_insert_el_in_col.h"
#include "../headers/matrixgame_headers_matrix_t.h"


#define SUCCESS 0
#define APPEND_ROW_ERROR 100  // refused to calloc memory for a new row
#define EXTEND_MATRIX_ERROR 110  // refused to realloc memory for int **matrix
#define ELEM_INDEX_ERROR 200  // invalid element's index

#define INVALID_INDICES 0  // invalid indices for insertion
#define VALID_INDICES 1  // valid indices for insertion



// Appending one row at the bottom of the matrix
int append_row(matrix_t *const matrix)
{
    int *new_row = (int *)calloc(matrix->columns, sizeof(int));
    if (!new_row)
        return APPEND_ROW_ERROR;

    matrix->matrix = (int **)realloc(matrix->matrix,  (matrix->rows + 1) * sizeof(int *));
    if (!matrix->matrix)
        return EXTEND_MATRIX_ERROR;
    
    *((matrix->matrix) + matrix->rows) = new_row;
    (matrix->rows)++;

    free(new_row);

    return SUCCESS;
}


// Check if indices valid or not
int check_indices(const matrix_t *const matrix, const int i, const int j)
{
    if ((i < 0) || (j < 0))
        return INVALID_INDICES;
    
    if ((matrix->rows <= i) || (matrix->columns <= j))
        return INVALID_INDICES;
    
    return VALID_INDICES;
}


int insert_el_in_col(matrix_t *const matrix, const int index_row, const int index_column, const int el)
{
    if (append_row(matrix) == SUCCESS)
    {
        if (check_indices(matrix, index_row, index_column) == VALID_INDICES)
        {
            for (int i = (matrix->rows) - 1; i > index_row; i--)
                *(*((matrix->matrix) + i) + index_column) = *(*((matrix->matrix) + (i - 1)) + index_column);
 
            *(*((matrix->matrix) + index_row) + index_column) = el;
            return SUCCESS;
        }

        return ELEM_INDEX_ERROR;
    }

    return APPEND_ROW_ERROR;
}
