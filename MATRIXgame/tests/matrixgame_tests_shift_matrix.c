#include "../headers/matrixgame_headers_shift_matrix.h"
#include "../headers/matrixgame_headers_create_matrix.h"
#include "../headers/matrixgame_headers_free_matrix.h"

#include <stdio.h>
#include <stdlib.h>

// Types of returns
#define DIRECTION_ERROR 11
#define POINTER_ERROR 12
#define SIZE_ERROR 13
#define PASSED 0
#define FAILED 1

// To refer to the begining of something
#define INITIAL 0
// The matrix size
#define SIZE 4
// Matrixes are not equal
#define NOT_EQUAL 1
// Matrixes are equal
#define EQUAL 0

// Filling matrix with zeros
void make_zero(matrix_t *const matrix_to_zero)
{
    for (int row = INITIAL; row < matrix_to_zero->rows; ++row)
    {
        for (int col = INITIAL; col < matrix_to_zero->columns; ++col)
        {
            *(*(matrix_to_zero->matrix + row) + col) = INITIAL;
        }
    }
}

// Finding out if we got the expected result from shift_matrix
int compare_matrix(const matrix_t *const matrix1, const matrix_t *const matrix2)
{
    for (int i = INITIAL; i < matrix1->rows; i++)
        for (int j = INITIAL; j < matrix1->columns; j++)
            if (*(*(matrix1->matrix + i) + j) != *(*(matrix2->matrix + i) + j))
                return NOT_EQUAL;
    return EQUAL;
}

// Leaves no zeros in matrix, only numbers
void full_fill_matrix(matrix_t *init_matrix)
{
  int value = 2;
  for (int i = INITIAL; i < SIZE; i ++)
  {
    for (int j = INITIAL; j < SIZE; j ++)
    {
      *(*(init_matrix->matrix + i) + j) = value;
      value *= 2;
    }
  }
}

// Testing shift_matrix, counting failed tests
int matrixgame_shift_matrix_test()
{
  int number_of_errors = INITIAL;

  // Test 1: normal work, "up"
  matrix_t matrix_1;
  matrixgame_create_matrix(&matrix_1, SIZE, SIZE);
  make_zero(&matrix_1);
  matrix_t matrix_1_result;
  matrixgame_create_matrix(&matrix_1_result, SIZE, SIZE);
  make_zero(&matrix_1_result);

  *(*(matrix_1.matrix + 0) + 3) = 4;
  *(*(matrix_1.matrix + 1) + 2) = 2;
  *(*(matrix_1.matrix + 2) + 2) = 16;
  *(*(matrix_1.matrix + 3) + 0) = 8;

  *(*(matrix_1_result.matrix + 0) + 0) = 8;
  *(*(matrix_1_result.matrix + 0) + 2) = 2;
  *(*(matrix_1_result.matrix + 0) + 3) = 4;
  *(*(matrix_1_result.matrix + 1) + 2) = 16;

  shift_matrix(&matrix_1, 'u');
  if (compare_matrix(&matrix_1, &matrix_1_result) != EQUAL)
    number_of_errors ++;
  matrixgame_free_matrix(&matrix_1);
  matrixgame_free_matrix(&matrix_1_result);

  // Test 2: normal work, "down"
  matrix_t matrix_2;
  matrixgame_create_matrix(&matrix_2, SIZE, SIZE);
  make_zero(&matrix_2);
  matrix_t matrix_2_result;
  matrixgame_create_matrix(&matrix_2_result, SIZE, SIZE);
  make_zero(&matrix_2_result);

  *(*(matrix_2.matrix + 0) + 3) = 4;
  *(*(matrix_2.matrix + 1) + 2) = 2;
  *(*(matrix_2.matrix + 2) + 2) = 16;
  *(*(matrix_2.matrix + 3) + 0) = 8;
  
  *(*(matrix_2_result.matrix + 3) + 0) = 8;
  *(*(matrix_2_result.matrix + 2) + 2) = 2;
  *(*(matrix_2_result.matrix + 3) + 3) = 4;
  *(*(matrix_2_result.matrix + 3) + 2) = 16;
  
  shift_matrix(&matrix_2, 'd');
  if (compare_matrix(&matrix_2, &matrix_2_result) != EQUAL)
    number_of_errors ++;
  matrixgame_free_matrix(&matrix_2); 
  matrixgame_free_matrix(&matrix_2_result);

  // Test 3: normal work, "right"
  matrix_t matrix_3;
  matrixgame_create_matrix(&matrix_3, SIZE, SIZE);
  make_zero(&matrix_3);
  matrix_t matrix_3_result;
  matrixgame_create_matrix(&matrix_3_result, SIZE, SIZE);
  make_zero(&matrix_3_result);

  *(*(matrix_3.matrix + 0) + 3) = 4;
  *(*(matrix_3.matrix + 1) + 2) = 2;
  *(*(matrix_3.matrix + 2) + 2) = 16;
  *(*(matrix_3.matrix + 3) + 0) = 8;
  *(*(matrix_3.matrix + 0) + 1) = 64;
  
  *(*(matrix_3_result.matrix + 0) + 3) = 4;
  *(*(matrix_3_result.matrix + 1) + 3) = 2;
  *(*(matrix_3_result.matrix + 2) + 3) = 16;
  *(*(matrix_3_result.matrix + 3) + 3) = 8;
  *(*(matrix_3_result.matrix + 0) + 2) = 64;

  shift_matrix(&matrix_3, 'r');
  if (compare_matrix(&matrix_3, &matrix_3_result) != EQUAL)
    number_of_errors ++;
  matrixgame_free_matrix(&matrix_3); 
  matrixgame_free_matrix(&matrix_3_result);

  // Test 4: normal work, "left"
  matrix_t matrix_4;
  matrixgame_create_matrix(&matrix_4, SIZE, SIZE);
  make_zero(&matrix_4);
  matrix_t matrix_4_result;
  matrixgame_create_matrix(&matrix_4_result, SIZE, SIZE);
  make_zero(&matrix_4_result);

  *(*(matrix_4.matrix + 0) + 3) = 4;
  *(*(matrix_4.matrix + 1) + 2) = 2;
  *(*(matrix_4.matrix + 2) + 2) = 16;
  *(*(matrix_4.matrix + 3) + 0) = 8;
  *(*(matrix_4.matrix + 3) + 3) = 64;

  *(*(matrix_4_result.matrix + 3) + 0) = 8;
  *(*(matrix_4_result.matrix + 1) + 0) = 2;
  *(*(matrix_4_result.matrix + 2) + 0) = 16;
  *(*(matrix_4_result.matrix + 0) + 0) = 4;
  *(*(matrix_4_result.matrix + 3) + 1) = 64;
  
  shift_matrix(&matrix_4, 'l');
  if (compare_matrix(&matrix_4, &matrix_4_result) != EQUAL)
    number_of_errors ++;
  matrixgame_free_matrix(&matrix_4); 
  matrixgame_free_matrix(&matrix_4_result);

  // Test 5: error about direction
  matrix_t matrix_5;
  matrixgame_create_matrix(&matrix_5, SIZE, SIZE);
  make_zero(&matrix_5);
  if (shift_matrix(&matrix_5, 'z') != DIRECTION_ERROR)
    number_of_errors ++;
  matrixgame_free_matrix(&matrix_5); 

  // Test 6: error about false pointer
  matrix_t matrix_6;
  matrixgame_create_matrix(&matrix_6, SIZE, SIZE);
  make_zero(&matrix_6);
  matrix_6.matrix = NULL;
  if (shift_matrix(&matrix_6, 'u') != POINTER_ERROR)
    number_of_errors ++;
  matrixgame_free_matrix(&matrix_6);

  // Test 7: matrix is full and isn't going to change
  matrix_t matrix_7;
  matrixgame_create_matrix(&matrix_7, SIZE, SIZE);
  make_zero(&matrix_7);
  matrix_t matrix_7_result;
  matrixgame_create_matrix(&matrix_7_result, SIZE, SIZE);
  make_zero(&matrix_7_result);

  full_fill_matrix(&matrix_7);
  full_fill_matrix(&matrix_7_result);
  shift_matrix(&matrix_7, 'l');

  if (compare_matrix(&matrix_7, &matrix_7_result) != EQUAL)
     number_of_errors ++;
  matrixgame_free_matrix(&matrix_7); 
  matrixgame_free_matrix(&matrix_7_result);

  // Test 8: matrix is not of a right size
  matrix_t matrix_8;
  matrixgame_create_matrix(&matrix_8, SIZE + 1, SIZE);
  matrix_8.rows = SIZE + 1;
  matrix_8.columns = SIZE;
  make_zero(&matrix_8);
  if (shift_matrix(&matrix_8, 'd') != SIZE_ERROR)
      number_of_errors ++;
  matrixgame_free_matrix(&matrix_8);

  if (number_of_errors)
    return FAILED;
  return PASSED;
}

int main()
{
    if (matrixgame_shift_matrix_test() != PASSED)
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