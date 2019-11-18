/**
 * \file teen48game_copy_matrix.c
 * \brief Функция, копирующая матрицы
 */

#include "../f_headers/teen48game_copy_matrix.h"

/**
 * \fn void copy_matrix(matrix_t *matrix, matrix_t *matrix_buffer)
 *
 * \param matrix_t *matrix - Копируемая матрица
 * \param matrix_t *matrix_buffer - Точка назначения
 *
 * \brief Копирует матрицу
 */
void copy_matrix(matrix_t *matrix, matrix_t *matrix_buffer)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            matrix_buffer->matrix[i][j] = matrix->matrix[i][j];
        }
    }
}
