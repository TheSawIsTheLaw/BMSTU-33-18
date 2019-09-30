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

int check_print(matrix_t matrix)
{
    FILE *file_ptr = fopen("1.txt", "r");
    int element, check = ERROR;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            fscanf(file_ptr, "%d", &element);
            if (element != matrix.matrix[i][j])
                check = ERROR;
        }
    }
    fclose(file_ptr);
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
    
    FILE *file_ptr = fopen("1.txt", "w");
    
    print_matrix(&matrixor, file_ptr);
    
    fclose(file_ptr);
    
    int check = check_print(matrixor);
    
    if (check == SUCCESS)
    {
        printf("Тест пройден\n");
        return SUCCESS;
    }
    else
    {
        printf("Тест завален\n");
        return SUCCESS;
    }
    return SUCCESS;
}
