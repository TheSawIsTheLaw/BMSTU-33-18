/**
 * \file teen48game_free_matrices.c
 * \brief Функция, освобождающая память под матрицами
 */

#include "../f_headers/teen48game_free_matrices.h"

/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0
#define BUFFER_SIZE 2

/**
 * \fn int free_matrices(matrix_t *players_matrices, matrix_t *matrix_buffer, const int count)
 *
 * \param matrix_t *players_matrices - Структура матриц игроков
 * \param matrix_t *matrix_buffer - Буфер для копирования матриц
 * \param const int count - Количестов участников
 *
 * \brief Освобождает память под всеми матрицами игроков
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
int free_matrices(matrix_t *players_matrices, matrix_t *matrix_buffer, const int count)
{
    int code_error;

    for (int i = 0; i < count; i ++)
    {
        if ((code_error = matrixgame_free_matrix(&players_matrices[i])))
        {
            return code_error;
        }
    }
    for (int i = 0; i < BUFFER_SIZE; i++)
    {
        if ((code_error = matrixgame_free_matrix(matrix_buffer)))
        {
            return code_error;
        }
    }
    return OK;
}
