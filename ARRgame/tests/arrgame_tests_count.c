#include <stdio.h>

#define HIDDEN_ELEMENTS 3
#define INITIAL 0
#define CONSTANT 1
#define ALL_PASSED 0
#define FAILED 1

// Getting the number that is counting throughout the array, 
/// also the place where that array is starting and its length (from
// the additional data in the hidden part of the array).
int count(const int x, int const* start, const int length)
{
    int counting_element = INITIAL;
    int const* end = start + length;
    
    while (start <= end)
        if (*start++ == x)
            counting_element++;
    
    return counting_element;
}

void print_array(int array[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", array[i]);
    printf("\n");
}

int main()
{
    int counting_errors = 0;
    int result;
    
    // Test 1 - ordinary work
    int first_array[10] = {7, 0xDEADA59, 0xDEADA52, 9, 5, -1, 9, 0, 9, 9};
    int special_element = 9;
    int expected_result = 4;

    printf("\n  - - -\nFirst array:\n");
    print_array(first_array, first_array[0] + HIDDEN_ELEMENTS);
    printf("Result: ");
    result = count(special_element, first_array + HIDDEN_ELEMENTS, first_array[0]);
    printf("%d", result);
    printf("\nExpected result: ");
    printf("%d", expected_result);
    if (result == expected_result)
    	printf("\nFirst test passed.");
    else
    {
    	counting_errors ++;
    	printf("\nFirst test failed.");
    }

    // Test 2 - there is no such element that is equal to the given one
    int second_array[8] = {5, 0xDEADA55, 0xDEADA55, 90, -9, 89, 2, 8};
    special_element = 1;
    expected_result = 0;

    printf("\n  - - -\nSecond array:\n");
    print_array(second_array, second_array[0] + HIDDEN_ELEMENTS);
    printf("Result: ");
    result = count(special_element, second_array + HIDDEN_ELEMENTS, second_array[0]);
    printf("%d", result);
    printf("\nExpected result: ");
    printf("%d", expected_result);
    if (result == expected_result)
    	printf("\nSecond test passed.");
    else
    {
    	counting_errors ++;
    	printf("\nSecond test failed.");
    }

    // Test 3 - there is no elements in the work part of the array at all
    int third_array[3] = {0, 0xDEADA55, 0xDEADA55};
    special_element = 11;
    expected_result = 0;

    printf("\n  - - -\nThird array:\n");
    print_array(third_array, third_array[0] + HIDDEN_ELEMENTS);
    printf("Result: ");
    result = count(special_element, third_array + HIDDEN_ELEMENTS, third_array[0]);
    printf("%d", result);
    printf("\nExpected result: ");
    printf("%d", expected_result);
    if (result == expected_result)
    	printf("\nThird test passed.");
    else
    {
    	counting_errors ++;
    	printf("\nThird test failed.");
    }

    printf("\nNumber of failed tests: %d", counting_errors);
    if (counting_errors != 0)
        return FAILED;
    else
        return ALL_PASSED;
}
