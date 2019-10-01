#include <stdio.h>

#include "../headers/matrixgame_headers_set_by_pos.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"

#define INITIAL 0

#define RANGE_ERROR 11

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
    
    matrix_t matrix_0;
    create_matrix(&matrix_0, 5, 5);
    make_zero(&matrix_0);
    set_by_pos(&matrix_0, 3, 3, 20);
    if (*(*(matrix_0.matrix + 3) + 3) != 20)
        number_of_errors ++;
    
    free_matrix(&matrix_0);
    
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
