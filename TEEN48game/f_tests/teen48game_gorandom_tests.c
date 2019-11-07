#include "../f_headers/teen48game_gorandom.h"
#include <arrgame.h>
#include <matrixgame.h>
#include <stdio.h>

#define FLEXXX 0
#define CRINGE 1

#define TCOUNT 3

/*
Fills all field with a same number

Input data:
* field, number
*/
void fill_field(matrix_t* field, int num)
{   
    for (int row = 0; row < field->rows; ++row)
    {
        for (int col = 0; col < field->columns; ++col)
        {
            *(*(field->matrix + row) + col) = num;
        }
    }
}

/*
Test for function to do something with 1 empty field
 
Input data:
* r,c - rows and cols in test matrix

Output data:
* result of a test(pass/fail)
*/
int test_normal_adding(int r, int c)
{
    matrix_t tfield;
    matrixgame_create_matrix(&tfield, r, c);
    
    int magic_number = 5051;
    fill_field(&tfield, magic_number);
    *(*(tfield.matrix + (r-1)) + (c-1)) = 0;
    
    gorandom(&tfield);
    
    if ((*(*(tfield.matrix + (r-1)) + (c-1))) != 0)
    {
        matrixgame_free_matrix(&tfield);
        return FLEXXX;
    }
    
    matrixgame_free_matrix(&tfield);
    return CRINGE;
}

int test_empty_field(int r, int c)
{
    matrix_t tfield;
    matrixgame_create_matrix(&tfield, r, c);
    
    int magic_number = 0;
    fill_field(&tfield, magic_number);
    gorandom(&tfield);
    gorandom(&tfield);
    gorandom(&tfield);
    matrixgame_free_matrix(&tfield);
    return FLEXXX;
}

/*
Test for function not to do anything if field is full

Input data:
* r,c - rows and cols in test matrix

Output data:
* result of a test(pass/fail)
*/
int test_no_space(int r, int c)
{
    matrix_t tfield;
    matrixgame_create_matrix(&tfield, r, c);
    matrix_t bfield;
    matrixgame_create_matrix(&bfield, r, c);
    
    int magic_number = 5151;
    fill_field(&tfield, magic_number);
    fill_field(&bfield, magic_number);
    
    gorandom(&tfield);
    
    for (int row = 0; row < tfield.rows; ++row)
    {
        for (int col = 0; col < tfield.columns; ++col)
        {
            if ((*(*(tfield.matrix + row) + col)) != \
                (*(*(bfield.matrix + row) + col)))
            {
                matrixgame_free_matrix(&tfield);
                matrixgame_free_matrix(&bfield);
                return CRINGE;
            }
        }
    }
        
    matrixgame_free_matrix(&tfield);
    matrixgame_free_matrix(&bfield);
    return FLEXXX;
}

int teen48game_gorandom_test()
{
    int err_count = 0;
    err_count += test_normal_adding(5,7);
    err_count += test_no_space(8,6);
    err_count += test_empty_field(9,3);
    
    if (err_count > 0)
    {
        printf("%d failed tests out of %d\n", err_count, TCOUNT);
        return CRINGE;
    }

    return FLEXXX;
}

int main()
{
    if (teen48game_gorandom_test() != FLEXXX)
    {
        return CRINGE;
    }
    return FLEXXX;
}



/*
░░░░░░░░░░░░░░░░░░░▄░▄░░░░░░░░░░░░░░░
░░░░░░░░░░░░░░░▄█▄█████▄█░░░░░░░░░░░░
░░░░░░░░░░░░░░▄█████████▀░░░░░░░░░░░░
░░░░░░░░░░░░▄█▀▀▀▀▀▀▀▀▀█▄▄░░░░░░░░░░░
░░░░░░░░░▄█▀▀░░░░░░░░░░░░▀█▄░░░░░░░░░
░░░░░▄▄▄▄█░░░░░░░▄▄▄▄░░░░░░▀█▄▄▄░░░░░
░░░▄▄████░░░░░░░▄▄▄▄▄▄░░░░░░▀████▄░░░
░░▀█████░░░░░░░░░░░░░░░░░░░░░█████▀░░
░███████░░░░░░░░░░░░░░░░░░░░░░██████▄
█████▀██░░░░▄█░░░░░░░░░▄█▄░░░░█▀█████
█████░██░▄██▀▀██▄░░░▄██▀▀██▄░░█░█████
▀████░██░▀██████▀░░░░▀█████▀░░█░█████
░███████░░░░█▀░░░▄▄▄░░░░▀█░░░▄█▄████▀
░▀██████▄░░░░░░░█████▄░░░░░░░███████░
░░▀░█▀░▀█░░░░░░░██████░░░░░░██░▀█░░▀░
░░░░░░░░▀█░░▄▄░░░▀▀▀▀░░▄▄░░▄█░░░░░░░░
░░░░░░░░░▀█░▀█▄██▄░▄▄█▄█▀░▄█░░░░░░░░░
░░░░░░░░░░▀█▄░▀████████▀▄█▀░░░░░░░░░░
░░░░░░░░░░░░▀█▄░▀░▀░▀░▄█▀░░░░░░░░░░░░
░░░░░░░░░░░░░░▀▀▄▄▄▄▄▀▀░░░░░░░░░░░░░░
*/
