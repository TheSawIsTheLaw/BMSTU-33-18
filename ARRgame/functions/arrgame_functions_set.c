#include "../headers/arrgame_headers_set.h"
#include <errno.h>

#define OK 0
#define POS_ERROR 1

#define SERVICE_INFO 3

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
    if (*array - pos <= 0 || pos < 0)
    {
        errno = POS_ERROR;
    }

    else
    {
        *(array + SERVICE_INFO + pos) = num_to_be_set;
    }

    return OK;
}
