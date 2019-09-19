#include <stdlib.h>
#include <stdio.h>

#include "../headers/arrgame_headers_create.h"

#define META_DATA 3

void *create(int size)
{
    int *arr = calloc(size + META_DATA, sizeof(int));

    if (arr == NULL)
    {
        puts("ERROR, TRY AGAIN!");
        return NULL;
    }

    *arr = size;
    *(arr + 1) = size;
    *(arr + 2) = 0;

    return arr + 3;
}
