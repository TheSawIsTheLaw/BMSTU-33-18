#include "../headers/matrixgame_headers_free_matrix.h"
#include "../headers/matrixgame_errno.h"
#include <stdio.h>
#include <stdlib.h>

#define OK 0
#define SOME_ARE_NULL 507
#define MAIN_POINTER_NULL 411

#define SERVICE_INFO 3
// free_matrix - освобождает что может, ошибки не дает и,
// скорее всего, не создает.

int free_matrix(matrix_t *to_free)
{
    int ec = OK;
    if (to_free->matrix)
    {
        for (int i = 0; i < to_free->rows; i++)
        {
            if (*(to_free->matrix + i))
            {
                *(to_free->matrix + i) -= SERVICE_INFO;
                free(*(to_free->matrix + i));
                *(to_free->matrix + i) = NULL;
            }
            else
            {
                ec = SOME_ARE_NULL;
            }
        }

        free(to_free->matrix);
        to_free->rows = 0;
        to_free->columns = 0;
        to_free->matrix = NULL;
    }
    else
    {
        ec = MAIN_POINTER_NULL;
    }
    
    return ec;
}
/*
int main()
{
        matrix_t test;
        test.matrix = malloc(sizeof(int**) * 4);
        test.rows = 4;
        test.matrix[0] = malloc(12 * sizeof(int));
        test.matrix[0] = test.matrix[0] + SERVICE_INFO;
        test.matrix[1] = NULL;
        test.matrix[2] = malloc(12 * sizeof(int));
        test.matrix[2] = test.matrix[2] + SERVICE_INFO;
        test.matrix[3] = NULL;

        free_matrix(&test);
}*/