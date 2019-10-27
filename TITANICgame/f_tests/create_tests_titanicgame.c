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
    int errors_counter = 0;

    // Тест 1
    if ((root = create(&some_func)) == NULL)
    {
        return NOT_ALLOCATED;
    }

    if (root -> no != NULL || root -> yes != NULL)
    {
        return NOT_INIT;
    }
    
    free(root);    

    return OK; 
}
