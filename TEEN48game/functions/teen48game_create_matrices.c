/**
 * \file teen48game_create_matrices.c
 * \brief Функция, создающая матрицы для участников
 */

#include "../f_headers/teen48game_create_matrices.h"

/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0
#define BUFFER_COUNT 2
/**
 * \fn int create_matrices(matrix_t *players_matrices, matrix_t *matrix_buffer,
 *  const int rows, const int columns, const int count)
 *
 * \param matrix_t *players_matrices - Структура матриц игроков
 * \param matrix_t *matrix_buffer - Буфер матриц
 * \param const int rows - Количестов строк матриц
 * \param const int columns - Количество столбцов матриц
 * \param const int count - Количество участников
 *
 * \brief Создаёт матрицы для участников
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
int create_matrices(matrix_t *players_matrices, matrix_t *matrix_buffer,
    const int rows, const int columns, const int count)
{
    int code_error;

    for (int i = 0; i < count; i++)
    {
        if ((code_error = matrixgame_create_matrix(&players_matrices[i], rows, columns)))
        {
            return code_error;
        }
    }
    for (int i = 0; i < BUFFER_COUNT; i++)
    {
        if ((code_error = matrixgame_create_matrix(matrix_buffer + i, rows, columns)))
        {
            return code_error;
        }
    }

    return OK;
}
