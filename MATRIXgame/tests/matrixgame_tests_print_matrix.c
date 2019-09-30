#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/matrixgame_headers_print_matrix.h"
#include "../headers/matrixgame_headers_matrix_t.h"
#define ERROR -1
#define SUCCESS 0




void array_matrix(matrix_t *matrix)
{
    for (int i = 0; i < matrix -> rows; i++)
        for (int j = 0; j < matrix -> columns; j++)
            matrix -> matrix[i][j] = i + j;
}

int compare_matrix(matrix_t matrix)
{
    int need_matrix[2][3] = {{0, 1, 2}, {1, 2, 3}};
    for (int i = 0; i < matrix.rows; i++)
        for (int j = 0; j < matrix.columns; j++)
        {
            if (matrix.matrix[i][j] != need_matrix[i][j])
                return ERROR;
        }
    return SUCCESS;
}
int main()
{
    matrix_t matrixor;
    matrixor.rows = 2;
    matrixor.columns = 3;
    matrixor.matrix = (int**)calloc(matrixor.rows, sizeof(int*));
    for (int i = 0; i < matrixor.rows; i++)
        matrixor.matrix[i] = (int*)calloc(matrixor.columns, sizeof(int));
    array_matrix(&matrixor);
    int check = ERROR;
    print_matrix(&matrixor);
    check = SUCCESS;
    if (check == ERROR)
    {
        printf("Тест завален\n");
        return ERROR;
    }
    check = compare_matrix(matrixor);
    if (check == SUCCESS)
    {
        printf("Тест пройден\n");
        return SUCCESS;
    }
    else
        return ERROR;
    return SUCCESS;
}

