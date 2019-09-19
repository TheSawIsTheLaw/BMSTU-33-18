#include <stdio.h>
#include "../headers/arrgame_headers_reverse.h"

#define SERVICE_INFO 3
#define OK 0
#define ERROR 1 
#define ZERO 0
#define SUCCESS 0
#define MIN_LENGTH 1
#define TWO 2

int equal(int *ar_res, int *ar_check)
{
    for (int i = 0; i < ar_res[0]; i++)
        if (ar_res[i] != ar_check[i])
            return 0;
    return 1;
}

int main()
{
    // positive test
    int kit1[11] = {8, 0xC001BEE5, 0xDEADBEEF, 1, 2, 3, 4, 5, 6, 7, 8};
    int kit1_check[11] = {8, 0xC001BEE5, 0xDEADBEEF, 8, 7, 6, 5, 4, 3, 2, 1};

    reverse(&kit1[3], &kit1[10]);
    if (equal(kit1, kit1_check))
        printf("1st test - OK\n");
    else
        printf("1st test - FAILED\n");

    int kit2[11] = {8, 0xC001BEE5, 0xDEADBEEF, 1, 2, 3, 4, 5, 6, 7, 8};
    int kit2_check[11] = {8, 0xC001BEE5, 0xDEADBEEF, 1, 5, 4, 3, 2, 6, 7, 8};

    reverse(&kit2[4], &kit2[7]);
    if (equal(kit2, kit2_check))
        printf("2nd test - OK\n");
    else
        printf("2nd test - FAILED\n");

    // border tests
    int kit3[11] = {8, 0xC001BEE5, 0xDEADBEEF, 1, 2, 3, 4, 5, 6, 7, 8};
    int kit3_check[11] = {8, 0xC001BEE5, 0xDEADBEEF, 1, 2, 3, 4, 5, 6, 7, 8};
    
    reverse(&kit2[7], &kit2[7]);
    if (equal(kit3, kit3_check))
        printf("3rd test - OK\n");
    else
        printf("3rd test - FAILED\n");


    // negative tests
    int kit4[11] = {8, 0xC001BEE5, 0xDEADBEEF, 1, 2, 3, 4, 5, 6, 7, 8};
    if (reverse(&kit4[6], &kit4[4]) == ERROR)
        printf("4th test - OK\n");
    else
        printf("4th test - FAILED\n");


    return OK;
} 
