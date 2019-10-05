/**
 * \file matrixgame_functions_input_matrix.c
 * \brief Функция, инициализирующая матрицу
 */

#include <stdio.h>
#include "../headers/matrixgame.h"

/**
 * \def ROW_ERROR
 * \brief Код ошибки: в функцию было передано некорректное значение количества строк матрицы
 */
#define ROW_ERROR 1 /*Некорректное значение строк матрицы*/
/**
 * \def COLUMN_ERROR
 * \brief Код ошибки: в функцию было передано некорректное значение количества столбцов матрицы
 */
#define COLUMN_ERROR 2 /*Некорректное значение столбцов матрицы*/
/**
 * \def POINT_ERROR
 * \brief Код ошибки: в качестве указаетля на структуру передан нулевой указатель
 */
#define POINT_ERROR 3 /*В качестве указателя на структуру передан нулевой указатель*/
/**
 * \def INPUT_ERROR
 * \brief Код ошибки: некорректный ввод значения ячейки матрицы
 */
#define INPUT_ERROR 4 // xd
/**
 * \def OK
 * \brief Код удачного завершения подпрограммы или программы
 */
#define OK 0 /*Матрица была удачно инициализирована*/

/*
 Функция для инициализации матрицы. Аргументом является указатель на структуру, содержащую данные для матрицы
 */

/**
 * \fn int matrixgame_input_matrix(matrix_t *matrix)
 *
 * \param matrix_t *matrix - Особо заданная матрица (см. matrixgame_
 * functions_create_matrix)
 *
 * \brief Функция, инициализирующая матрицу
 *
 * \return Код ошибки (отличное от нуля число) или
 * успешного завершения
 */
int matrixgame_input_matrix(matrix_t *matrix)
{
    if (matrix -> matrix == NULL)
        return POINT_ERROR;

    if (matrix -> rows <= 0)
        return ROW_ERROR;

    if (matrix -> columns <= 0)
        return COLUMN_ERROR;

    int i, j;

    for (i = 0; i < matrix -> rows; i++)
        for (j = 0; j < matrix -> columns; j++)
            if (scanf("%d", &matrix -> matrix[i][j]) != 1)
                return INPUT_ERROR;

    return OK;
}
