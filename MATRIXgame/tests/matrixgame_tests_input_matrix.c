#include <stdio.h>

#include "../headers/matrixgame_headers_input_matrix.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"

#define ROW_ERROR 1
#define COLUMN_ERROR 2
#define POINT_ERROR 3
#define OK 0

#define ZERO 0
#define ALL_PASSED 0
#define FAILED 1

int matrixgame_input_matrix_tests()
{
    int error = ZERO;
  
    /*Test 1: NULL pointer*/
    matrix_t matrix1;
    create_matrix(&matrix1, 10, 5);
    matrix1.matrix = NULL;
    if (input_matrix(&matrix1) == POINT_ERROR)
        error++;
    free_matrix(&matrix1);
    
    /*Test 2: incorrect input*/
    matrix_t matrix2;
    create_matrix(&matrix2, 10, 5);
    if (input_matrix(&matrix2) != OK)
        error++;
    free_matrix(&matrix2);
    
    /*Test 3: correct input*/
    matrix_t matrix3;
    create_matrix(&matrix3, 4, 4);
    if (input_matrix(&matrix3) != OK)
        error++;
    free_matrix(&matrix3);

    
    if (error)
        return FAILED;
    return ALL_PASSED;
}


int main()
{
    if (matrixgame_input_matrix_tests() == ALL_PASSED)
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