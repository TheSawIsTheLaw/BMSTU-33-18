#include <stdio.h>
#include <malloc.h>

#include "../headers/matrixgame_headers_insert_el_in_row.h"
#include "../headers/matrixgame_headers_matrix_t.h"

#define OK 1
#define ERR 111

int add_mem_for_vect(matrix_t *const matrix)
{
    int *a_1;
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

