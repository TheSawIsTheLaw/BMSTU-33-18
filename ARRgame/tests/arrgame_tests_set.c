//#include "../headers/arrgame_headers_set.h" //rak
#include <stdio.h>

#define SERVICE_INFO 3
#define OK 0
#define POS_ERROR 1
#define TEST_ERROR 1 
#define NO 0
#define YES 1

//delet plsss
#include <errno.h>

extern int errno;

/*
Setting an array[pos] element to num_to_be_set.

Input data:
* int *const array - array to be modified.
* const int num_to_bes_set - number to be set in array.
* pos - position where num_to_be_set will be set.

Output data:
* Return code - OK [and optional modified errno].
*/
int set(int *const array, const int num_to_be_set, const int pos)
{
    if (*(array - SERVICE_INFO) - pos <= 0 || pos < 0)
    {
        errno = POS_ERROR;
    }

    else
    {
        *(array + pos) = num_to_be_set;
    }

    return OK;
}

//delet plsss



void print_mas(int m[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", m[i]);

    printf("\n");
}

int same(int m1[], int m2[])
{    
    for (int i = 0; i < m1[0]; i++)
        if (m1[i] != m2[i])
            return NO;

    return YES;
}

int main()
{
    int bad_count = 0;
    //case 1 - нормальная работа
    int case1[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};
    int case1_g[10] = {7, 0xDEADA55, 0xDEADA55, 33, 1, 2, 3, 4, 5, 6};

    errno = 0;
    set((case1 + SERVICE_INFO), 33, 0);

    printf("First case \n");
    printf("Out: \n");
    print_mas(case1, case1[0] + SERVICE_INFO);
    printf("err %d\n", errno);
    printf("Expected out: \n");
    print_mas(case1_g, case1_g[0] + SERVICE_INFO);
    printf("err 0\n");

    if (same(case1, case1_g) && errno == OK)
        printf("GOOD\n");
    else
    {
        printf("BAD\n");
        bad_count++;
    }

    //case 2 - запись в служебные данные
    int case2[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};
    int case2_g[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};

    errno = 0;
    set((case2 + SERVICE_INFO), 0xA55, -1);

    printf("\nSecond case \n");
    printf("Out: \n");
    print_mas(case2, case2[0] + SERVICE_INFO);
    printf("err %d\n", errno);
    printf("Expected out: \n");
    print_mas(case2_g, case2_g[0] + SERVICE_INFO);
    printf("err 1\n");

    if (same(case2, case2_g) && errno == POS_ERROR)
        printf("GOOD\n");
    else
    {
        printf("BAD\n");
        bad_count++;
    }

    //case 3 - запись после массива
    int case3[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};
    int case3_g[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};

    errno = 0;
    set((case3 + SERVICE_INFO), 0xA55, 33);

    printf("\nThird case \n");
    printf("Out: \n");
    print_mas(case3, case3[0] + SERVICE_INFO);
    printf("err %d\n", errno);
    printf("Expected out: \n");
    print_mas(case3_g, case3_g[0] + SERVICE_INFO);
    printf("err 1\n");

    if (same(case3, case3_g) && errno == POS_ERROR)
        printf("GOOD\n");
    else
    {
        printf("BAD\n");
        bad_count++;
    }

    //case 4 - запись совсем до массива
    int case4[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};
    int case4_g[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};

    errno = 0;
    set((case4 + SERVICE_INFO), 0xA55, -100);

    printf("\nFourth case \n");
    printf("Out: \n");
    print_mas(case4, case4[0] + SERVICE_INFO);
    printf("err %d\n", errno);
    printf("Expected out: \n");
    print_mas(case4_g, case4_g[0] + SERVICE_INFO);
    printf("err 1\n");

    if (same(case4, case4_g) && errno == POS_ERROR)
        printf("GOOD\n");
    else
    {
        printf("BAD\n");
        bad_count++;
    }

    //case 5 - запись в конец
    int case5[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 6};
    int case5_g[10] = {7, 0xDEADA55, 0xDEADA55, 0, 1, 2, 3, 4, 5, 11};

    errno = 0;
    set((case5 + SERVICE_INFO), 11, 6);

    printf("\nFifth case \n");
    printf("Out: \n");
    print_mas(case5, case5[0] + SERVICE_INFO);
    printf("err %d\n", errno);
    printf("Expected out: \n");
    print_mas(case5_g, case5_g[0] + SERVICE_INFO);
    printf("err 0\n");

    if (same(case5, case5_g) && errno == OK)
        printf("GOOD\n");
    else
    {
        printf("BAD\n");
        bad_count++;
    }

    printf("\nFAILED TESTS: %d\n", bad_count);
    
    if (bad_count > 0)
        return TEST_ERROR;
    else
        return OK;
}