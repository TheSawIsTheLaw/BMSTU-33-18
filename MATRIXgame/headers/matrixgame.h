#ifndef __MATRIXGAME_H__
#define __MATRIXGAME_H__

#include <stdio.h>

typedef struct
{
	int rows;
	int columns;
	int **matrix;
} matrix_t;

int matrixgame_add_column(matrix_t *const matrix, int vect[]);

int matrixgame_add_row(matrix_t *matrix, const int index);

int matrixgame_create_matrix(matrix_t *const matrix, const int rows, const int columns);

int matrixgame_del_column(matrix_t *const m, const int column);

int matrigame_del_row(matrix_t *edit_matrix, const int index_row);

int matrixgame_free_matrix(matrix_t *to_free);

int matrixgame_get_by_pos(const matrix_t *const init_matrix,
               const int index_row,
               const int index_column);

int matrixgame_input_matrix(matrix_t *matrix);

int matrixgame_insert_el_in_col(matrix_t *const matrix, const int index_row,
    const int index_column, const int el);

int matrixgame_insert_el_in_row(matrix_t *const matrix, int index_row, int index_column, int el);

int matrixgame_mult_matrices(const matrix_t *const matrix1, const matrix_t *const matrix2,
                  matrix_t *const res);

int matrixgame_print_matrix(const matrix_t *const matrix, FILE *file);

int matrixgame_set_by_pos(const matrix_t *const init_matrix,
    const int index_row, const int index_column, const int el);

int matrixgame_transpose(matrix_t *const matrix);

#endif
