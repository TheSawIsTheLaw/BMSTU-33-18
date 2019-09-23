#ifndef _MATRIXGAME_HEADERS_INSERT_EL_IN_ROW_H_
#define _MATRIXGAME_HEADERS_INSERT_EL_IN_ROW_H_
#include "matrixgame_headers_matrix_t.h"

int one_pos_shifting(matrix_t *const matrix);

int insert_el_in_row(matrix_t *const matrix, int index_row, int index_column, int el);

#endif

