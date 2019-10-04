#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#include "../headers/matrixgame_headers_add_column.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define OK 0
#define ERR 111
/**
* \brief Освобождение памяти, если realloc не сработал
* \param[in] matrix - указатель на структуру, описывающую матрицу
*/
void free_matr(matrix_t *const matrix)
{
    for (int i = 0; i < matrix -> rows; i ++)
    {
        free(*((matrix->matrix)+ i ));
    }
}
/**
* \brief Добавление памяти под столбец
* \param[in] matrix - указатель на структуру, описывающую матрицу
*/
int add_mem_for_vect(matrix_t *const matrix)
{
    matrix->matrix = (int**)realloc(matrix->matrix,(matrix->columns + 1) * sizeof(int*));
    if (matrix->matrix == NULL)
    {
            free_matr(matrix);
            return ERR;

    }
    return OK;
}
/**
* \brief Добавляет столбец
* \details Выделяет память для переданного столбца
*
* \param[in] matrix - указатель на структуру, описывающую матрицу
* \param[in] vect - указатель на нулевой элемент столбца
* \return Код ошибки
* \retval OK Успех
* \retval ERR Ошибка
*/
/*
 Допущение - количество элементов в инициализированном столбце должно совпадать с количеством рядов матрицы
*/
int add_column(matrix_t *const matrix, int vect[])
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
