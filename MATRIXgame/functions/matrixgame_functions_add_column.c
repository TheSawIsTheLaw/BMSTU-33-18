/**
 * \file matrixgame_functions_add_column.c
 * \brief Функция, добавляющая столбец в матрицу
 */
#include <stdlib.h>

#include "../headers/matrixgame.h"

/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0
/**
 * \def ERR
 * \brief Код ошибки: Сабуров не сказал, что это за ошибка. Вредина. Не будьте Сабуровым.
 */
#define ERR 111

/**
 * \def SOME_ARE_NULL
 * \brief Код ошибки: память не была перераспределена
 */
#define SOME_ARE_NULL 507
/**
 * \def MAIN_POINTER_NULL
 * \brief Код ошибки: в функцию был передан пустой указатель на матрицу
 */
#define MAIN_POINTER_NULL 411
/**
 * \def SERVICE_INFO
 * \brief Метаданные проекта ARRgame
 */
#define SERVICE_INFO 3

/**
 * \fn static int add_mem_for_vect(matrix_t *const matrix)
 *
 * \param matrix_t *const matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Функция, инициализирующая новую память под матрицу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
static int add_mem_for_vect(matrix_t *const matrix)
{
    matrix->matrix = (int**)realloc(matrix->matrix,(matrix->columns + 1) * sizeof(int*));
    if (matrix->matrix == NULL)
    {

    }
    return OK;
}

/**
 * \fn int matrixgame_add_column(matrix_t *const matrix, int vect[])
 *
 * \param matrix_t *const matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 * \param int vect - Добавляемый в матрицу столбец
 *
 * \brief Функция, добавляющая столбец в матрицу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_add_column(matrix_t *const matrix, int vect[])
{
    if (matrix->rows <= 0 || matrix->columns <= 0)
        return ERR;
    if ((add_mem_for_vect(matrix))!= ERR)
    {
        matrix->columns += 1;
        for (int i = 0; i < matrix->rows;  i++)
        {
            *(*((matrix->matrix)+ i ) + matrix->columns - 1) = vect[i];
        }
    }
    else
        return ERR;
    return OK;
}
