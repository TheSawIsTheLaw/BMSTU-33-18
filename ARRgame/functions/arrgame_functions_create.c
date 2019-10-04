#include <stdio.h>
#include <stdlib.h>

#include "../headers/arrgame_headers_create.h"

#define COUNT_NEED_ELEMENT 3

#define NO_CORRECT_SIZE_ARRAY 101
#define MEMORY_ERROR 102

int* create(const int sizeArray)
{
    if (sizeArray <= 0)
        return NULL;
       
    int* pointUserStart;
    int allocatSize = 0;


    pointUserStart = 
        (int*)calloc((sizeArray * 2) + COUNT_NEED_ELEMENT,  sizeof(int));
    
    if (pointUserStart)
    {
        allocatSize = sizeArray * 2;
    }
    else
    {
        puts("Не удалось выделить память.");
        return NULL;
    }
        
    
    //array[0] - длинна массива, запрошенного пользователем
    *pointUserStart = sizeArray;
    
    //array[1] - количество аллоцированнх элементов(не считая первых 3х)
    pointUserStart = pointUserStart + 1;
    *pointUserStart = allocatSize;
    
    //array[2] - количество занятых ячеек
    pointUserStart = pointUserStart + 1;
    *pointUserStart = 0;

    pointUserStart = pointUserStart + 1;
    
    return pointUserStart;
}

/*
int main()
{
    int* p = create(10000000);
    for (int i = 0; i <= 15000000; i++)
        *(p + i) = i;
    for (int i = 0; i < 15000000; i++)
        printf("%d) = %d\n", i, *(p + i));
    printf("n = %d p-3=%d p-2=%d p-1=%d\n", 5, *(p - 3), *(p - 2), *(p - 1));
    return 0;
}*/
