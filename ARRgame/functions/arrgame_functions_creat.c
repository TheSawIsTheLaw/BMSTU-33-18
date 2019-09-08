#include <stdio.h>
#include <stdlib.h>

#include "../headers/arrgame_headers_creat.h"

#define COUNT_NEED_ELEMENT 3

#define NO_CORRECT_SIZE_ARRAY 101


int* creat(const int sizeArray)
{
    if (sizeArray < 1)
        return NO_CORRECT_SIZE_ARRAY;
    
    int* pointUserStart;
    
    pointUserStart = 
        (int*)malloc((sizeArray + COUNT_NEED_ELEMENT) * sizeof(int));
    
    pointUserStart += 3;

    return pointUserStart;
}

/*
int main()
{
    return 0;
}
*/
