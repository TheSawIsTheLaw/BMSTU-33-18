/**
 * \file matrixgame_functions_transpose.c
 * \brief Функция, выполняющая транспонирование переданной в неё матрицы
 */

#include <stdlib.h>

#include "../headers/matrixgame.h"

/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0
/**
 * \def SIZE_ERROR
 * \brief Код ошибки: в подпрограмму были передан массив некорректной размерности
 */
#define SIZE_ERROR 217
/**
 * \def SOME_ARE_NULL
 * \brief Код ошибки: в функцию был передан указатель
 * на массив с NULL указателем
 */
#define SOME_ARE_NULL 507
/**
 * \def MAIN_POINTER_NULL
 * \brief Код ошибки: в функцию был передан NULL указатель на матрицу
 */
#define MAIN_POINTER_NULL 411

/**
 * \fn static int data_check(matrix_t *const matrix)
 *
 * \param matrix_t *const matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Проверка переданных в функцию данных
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения проверки
 */
static int data_check(matrix_t *const matrix)
{
    if (matrix == NULL)
    {
        return MAIN_POINTER_NULL;
    }

    if (matrix->rows < 1 || matrix->columns < 1)
    {
        return SIZE_ERROR;
    }

    if (matrix->matrix == NULL)
    {
        return SOME_ARE_NULL;
    }

    for (int i = 0; i < matrix->rows; i++)
    {
        if (*(matrix->matrix + i) == NULL)
        {
            return SOME_ARE_NULL;
        }
    }

    return OK;
}

/**
 * \fn static void transpose_matrix(matrix_t *const matrix, matrix_t *const new_matrix)
 *
 * \param matrix_t *const matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \param matrix_t *const new_matrix - Особо заданная матрица, куда будет
 * записан результат транспонирования
 *
 * \brief Транспонирование матрицы
 */
static void transpose_matrix(matrix_t *const matrix, matrix_t *const new_matrix)
{
    for (int i = 0; i < matrix->rows; i++)
    {
        for (int j = 0; j < matrix->columns; j++)
        {
            *(*(new_matrix->matrix + j) + i) = *(*(matrix->matrix + i) + j);
        }
    }
}

/**
 * \fn int transpose(matrix_t *const matrix)
 *
 * \param matrix_t *const matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Функция вызова выполнения транспонирования матрицы для пользователя
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_transpose(matrix_t *const matrix)
{
    matrix_t new_matrix;
    int code_error;

    if ((code_error = data_check(matrix)))
    {
        return code_error;
    }

    if ((code_error = matrixgame_create_matrix(&new_matrix, matrix->columns, matrix->rows)))
    {
        return code_error;
    }

    transpose_matrix(matrix, &new_matrix);
    if ((code_error = matrixgame_free_matrix(matrix)))
    {
        return code_error;
    }

    *matrix = new_matrix;

    return OK;
}
