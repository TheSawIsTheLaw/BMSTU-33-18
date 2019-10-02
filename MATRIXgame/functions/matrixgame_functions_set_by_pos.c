#include "../headers/matrixgame_headers_set_by_pos.h"

// The index of a row/column is not valid (that number is more or less than possible)
#define RANGE_ERROR 11
// False pointer
#define POINTER_ERROR 12
// Normal work without errors
#define PASSED 0

// To refer to the begining of something
#define INITIAL 0

/*
Function to set matrix element by it's position.
Input is the matrix itself, two indexes that clarify the element position and the value to be set in it.
Output is the return code - about success/error.
*/

int set_by_pos(const matrix_t *const init_matrix, const int index_row, const int index_column, const int el)
{
    if (index_row < INITIAL || index_column < INITIAL || index_row >= init_matrix->rows || index_column >= init_matrix->columns)
        return RANGE_ERROR;
    if (!(init_matrix->matrix + index_row))
    	return POINTER_ERROR;
    *(*(init_matrix->matrix + index_row) + index_column) = el;

    return PASSED;
}
