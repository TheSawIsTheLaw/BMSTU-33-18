#include <stdio.h>
#include <stdlib.h>

#include "../headers/matrixgame_headers_input_matrix.h"
#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_headers_free_matrix.h"

#define ROW_ERROR 1
#define COLUMN_ERROR 2
#define POINT_ERROR 3
#define OK 0

#define ZERO 0
#define ALL_PASSED 0
#define FAILED 1
#define FAILED_POINTER 2


int matrixgame_input_matrix_tests(matrix_t *matrix1, matrix_t *matrix2)
{
    int error = ZERO;
    int error_null = ZERO;
  
    /*Test 1: NULL pointer*/
    matrix1 = NULL;
    if (input_matrix(matrix1) == POINT_ERROR)
        error_null++;
    
    /*Test 2: correct input*/
    if (input_matrix(matrix2) != OK)
        error++;
    
    if (error && error_null)
        return FAILED;
    else if (!error && error_null)
        return FAILED_POINTER;
    return ALL_PASSED;
}

int main(int argc, const char * argv[])
{
    matrix_t matrix1;
    matrix1.rows = 3;
    matrix1.columns = 3;
    
    matrix_t matrix2;
    matrix2.rows = 3;
    matrix2.columns = 3;
    
    matrix1.matrix = (int**)calloc(matrix1.rows, sizeof(int*));
    for (int i = 0; i < matrix1.rows; i++)
        matrix1.matrix[i] = (int*)calloc(matrix1.columns, sizeof(int));
    
    matrix2.matrix = (int**)calloc(matrix2.rows, sizeof(int*));
    for (int i = 0; i < matrix2.rows; i++)
        matrix2.matrix[i] = (int*)calloc(matrix2.columns, sizeof(int));
    
    int test = matrixgame_input_matrix_tests(&matrix1, &matrix2);
    
    if (test == ALL_PASSED)
    {
        puts("All tests passed (success)");
        return ALL_PASSED;
    }
    else
    {
        puts("Not all the tests passed (failure)");
        return FAILED;
    }
}