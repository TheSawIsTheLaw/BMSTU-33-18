#ifndef _MATRIXGAME_HEADERS_INSERT_EL_IN_ROW_H_
#define _MATRIXGAME_HEADERS_INSERT_EL_IN_ROW_H_
#include "matrixgame_headers_matrix_t.h"

int append_row(matrix_t *const matrix);
int check_indices(const matrix_t *const matrix, const int i, const int j);

int insert_el_in_col(matrix_t *const matrix, const int index_row, const int index_column, const int el);

#endif
