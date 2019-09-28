#include <stdio.h>

#include "../headers/matrixgame_headers_set_by_pos.h"

#define INITIAL 0
#define PASSED 0
#define FAILED 1

int matrixgame_set_by_pos_test()
{
    int number_of_errors = INITIAL;
  
    if (number_of_errors)
        return FAILED;
    return PASSED;
}

int main()
{
    if (matrixgame_set_by_pos_test() != PASSED)
    {
    	printf("\nNot all tests passed successfully.");
        return FAILED;
    }
    printf("\nThere is no failed tests.");
    return PASSED;
}
