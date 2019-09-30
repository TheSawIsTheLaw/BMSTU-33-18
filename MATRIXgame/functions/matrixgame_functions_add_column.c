#include <stdio.h>
#include <malloc.h>

#include "../headers/matrixgame_headers_add_column.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define OK 1 // Успешно
#define ERR 111 // Ошибка выделения памяти
/*
add_mem_for_vect - выделяет память в каждой строке для нового элемента
add_column - добавляет инициализированный столбец в конец матрицы:
            int vect[] - вектор, являющийся инициализированным столбцом, который необходимо вставить.
            так как память для вставки столбца уже выделена, остается лишь добавить этот столбец в матрицу.Это происходит в цикле
*/
int add_mem_for_vect(matrix_t *const matrix)
{
    for (int i = 0; i < matrix->rows;  i++)
    {
        (matrix->matrix)[i] =  (int*)realloc(((matrix->matrix)[i]), sizeof(int*)* ((matrix->rows)+ 1));
        if ((matrix->matrix)[i] == NULL)
        {
            return ERR;
        }
    }
    return 0;
}
int add_column(matrix_t *const matrix, int vect[])
{
    if ((add_mem_for_vect(matrix))!= ERR)
    {
        for (int i = 0; i < matrix->rows;  i++)
        {
            *(*((matrix->matrix)+ i ) + matrix->columns) = vect[i];
        }
    }
    matrix->columns += 1;
    return OK;
}

