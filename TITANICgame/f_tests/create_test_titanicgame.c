#include "../f_headers/create_titanicgame.h"

#define OK 0 
#define NOT_ALLOCATED 1
#define NOT_INIT 2

bool some_func(passenger info)
{
    return OK;
}

int main()
{
    node *root = NULL;
    
    // Тест 1
    if ((root = create(&some_func)) == NULL)
    {
        printf("TEST1.....FAILED\n");
        return NOT_ALLOCATED;
    }

    if (root -> no != NULL || root -> yes != NULL)
    {
        printf("TEST1.....FAILED\n");
        return NOT_INIT;
    }

    printf("TEST1.....PASSED\n");
    free(root);    

    return OK; 
}
