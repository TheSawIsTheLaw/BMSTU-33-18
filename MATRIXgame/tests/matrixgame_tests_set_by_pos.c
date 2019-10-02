#include <stdio.h>

#include "../headers/matrixgame_headers_set_by_pos.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"

#define INITIAL 0

#define RANGE_ERROR 11
#define POINTER_ERROR 12

#define PASSED 0
#define FAILED 1

// Filling matrix with zeros
void make_zero(matrix_t *const matrix_to_zero)
{
    for (int row = 0; row < matrix_to_zero -> rows; ++row)
    {
        for (int col = 0; col < matrix_to_zero -> columns; ++col)
        {
            *(*(matrix_to_zero -> matrix + row) + col) = INITIAL;
        }
    }
}

int matrixgame_set_by_pos_test()
{
    int number_of_errors = INITIAL;
  
    // Test 1: normal work
    matrix_t matrix_1;
    create_matrix(&matrix_1, 5, 5);
    make_zero(&matrix_1);
    set_by_pos(&matrix_1, 3, 3, 20);
    if (*(*(matrix_1.matrix + 3) + 3) != 20)
        number_of_errors ++;
    free_matrix(&matrix_1);

    // Test 2: row index is too big
    matrix_t matrix_2;
    create_matrix(&matrix_2, 5, 5);
    make_zero(&matrix_2);
    if (set_by_pos(&matrix_2, 30, 3, -20) != RANGE_ERROR)
        number_of_errors ++;
    free_matrix(&matrix_2);
 
    // Test 3: column index is too big
    matrix_t matrix_3;
    create_matrix(&matrix_3, 5, 5);
    make_zero(&matrix_3);
    if (set_by_pos(&matrix_3, 2, 31, -20) != RANGE_ERROR)
        number_of_errors ++;
    free_matrix(&matrix_3);

    // Test 4: row index is negative
    matrix_t matrix_4;
    create_matrix(&matrix_4, 5, 5);
    make_zero(&matrix_4);
    if (set_by_pos(&matrix_4, -2, 3, 20) != RANGE_ERROR)
        number_of_errors ++;
    free_matrix(&matrix_4);
 
    // Test 5: column index is negative
    matrix_t matrix_5;
    create_matrix(&matrix_5, 5, 5);
    make_zero(&matrix_5);
    if (set_by_pos(&matrix_5, 2, -3, 23) != RANGE_ERROR)
        number_of_errors ++;
    free_matrix(&matrix_5);
/*
    // Test 6: false pointer
    matrix_t matrix_6;
    create_matrix(&matrix_6, 5, 5);
    make_zero(&matrix_6);
    matrix_6.matrix = NULL;
    if (set_by_pos(&matrix_6, 2, 3, 10) != POINTER_ERROR)
        number_of_errors ++;
    free_matrix(&matrix_6);

    // Test 7: normal work (low boundary)
    matrix_t matrix_7;
    create_matrix(&matrix_7, 5, 5);
    make_zero(&matrix_7);
    set_by_pos(&matrix_7, 0, 0, 7);
    if (*(*(matrix_7.matrix + 0) + 0) != 7)
        number_of_errors ++;
    free_matrix(&matrix_7);

    // Test 8: normal work (high boundary)
    matrix_t matrix_8;
    create_matrix(&matrix_8, 5, 5);
    make_zero(&matrix_8);
    set_by_pos(&matrix_8, 4, 4, 20);
    if (*(*(matrix_8.matrix + 4) + 4) != 20)
        number_of_errors ++;
    free_matrix(&matrix_8);
  */  
    if (number_of_errors)
        return FAILED;
    return PASSED;
}

int main()
{
    if (matrixgame_set_by_pos_test() != PASSED)
    {
    	printf("Not all tests passed successfully.\n");
        return FAILED;
    }
    else
    {
        printf("\nThere is no failed tests.");
        return PASSED;
    }
}
