/**
 * \file matrixgame_functions_add_column.c
 * \brief Функция, добавляющая столбец матрице
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../headers/matrixgame_headers_add_column.h"
#include "../headers/matrixgame_headers_matrix_t.h"

/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0
/**
 * \def SIZE_ERROR
 * \brief Код ошибки: в функцию были переданы некорректные данные или память
 * не была выделена
 */
#define ERR 111

/**
* \fn static void free_matr(matrix_t *const matrix)
*
* \param matrix_t *const matrix Особо заданная матрица (см. matrixgame_
* functions_create_matrix)
*
* \brief Освобождение памяти при некорректной работе realloc
*
* \return Код ошибки (отличное от нуля число) или
* успешного выполнения
*/
static void free_matr(matrix_t *const matrix)
{
    for (int i = 0; i < matrix -> rows; i ++)
    {
        free(*((matrix->matrix)+ i ) - 3);
    }
}

/**
* \fn static int add_mem_for_vect(matrix_t *const matrix)
*
* \param matrix_t *const matrix Особо заданная матрица (см. matrixgame_
* functions_create_matrix)
*
* \brief Выделение памяти под новый столбец
*
* \return Код ошибки (отличное от нуля число) или
* успешного выполнения
*/
static int add_mem_for_vect(matrix_t *const matrix)
{
    matrix->columns += 1;
    for (int i = 0; i < matrix->rows;  i++)
    {
        *((matrix->matrix)+ i ) =  (int*)realloc(*((matrix->matrix)+ i ), sizeof(int)* ((matrix->columns)));
        if (*((matrix->matrix)+ i ) == NULL)
        {
            free_matr(matrix);
            return ERR;
            break;

        }
    }
    return OK;
}

/**
* \fn int add_column(matrix_t *const matrix, int vect[])
*
* \details Количество элементов в инициализированном столбце должно совпадать
* с количеством рядов матрицы
*
* \param matrix_t *const matrix Особо заданная матрица (см. matrixgame_
* functions_create_matrix)
* \param int vect[] Вектор-столбец, который будет добавлен к матрице
*
* \brief Добавление задонного столбца к матрице
*
* \return Код ошибки (отличное от нуля число) или
* успешного выполнения
*/
int add_column(matrix_t *const matrix, int vect[])
{
    if (matrix->rows <= 0 || matrix->columns <= 0)
        return ERR;
    if ((add_mem_for_vect(matrix))!= ERR)
    {
        for (int i = 0; i < matrix->rows;  i++)
        {
            *(*((matrix->matrix)+ i ) + matrix->columns) = vect[i];
        }
    }
    else
        return ERR;
    return OK;
}
