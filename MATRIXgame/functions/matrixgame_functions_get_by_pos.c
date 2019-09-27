#include "../headers/matrixgame_headers_get_by_pos.h"

#define DIMENSION_OUT_OF_RANGE_ERROR 218
#define FALSE_POINTER_ERROR 219

/*
Get matrix element by it's position.

Input data:
* const matrix_t *const matrix - matrix struct where need to get element.
* const int index_row - index of needed element's row.
* const int index_column - index of needed elements's column.

Output data:
* Found element or return code - DIMENSION_OUT_OF_RANGE_ERROR or 
FALSE_POINTER_ERROR.
*/
int get_by_pos(const matrix_t *const init_matrix,
               const int index_row,
               const int index_column)
{
    if (init_matrix->rows - 1 < index_row || init_matrix->columns - 1 < index_column ||
        index_row < 0 || index_column < 0)
    {
        return DIMENSION_OUT_OF_RANGE_ERROR;
    }

    for (int row = 0; row < init_matrix->rows; ++row)
    {
        if (!(init_matrix->matrix + row))
        {
            return FALSE_POINTER_ERROR;
        }
    }

    return *(*(init_matrix->matrix + index_row) + index_column);
}
