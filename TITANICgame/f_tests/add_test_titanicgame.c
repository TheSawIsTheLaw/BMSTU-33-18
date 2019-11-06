#include "../f_headers/add_titanicgame.h"

#define OK 0
#define ERRORS_DETECTED 1

node* create(bool (*decision)(passenger info))
{
    node *new = NULL;
    
    if ((new = malloc(sizeof(node))) == NULL)
    {
        return NULL;
    }

    new -> no = NULL;
    new -> yes = NULL;
    new -> decision = decision;

    return new;
}

bool some_func(passenger info)
{
    return OK;
}

int main()
{
    node root = {NULL, NULL, &some_func}, *new_node = NULL; 
    int err_counter = 0, error_code = 0;

    // Тест 1

    if ((new_node = create(&some_func)) == NULL)
    {
        printf("TEST1.....FAILED\n");
        err_counter++;
    }
    else
    {
        if ((error_code = add(&root, TRUE, new_node)) != OK)
        {
            printf("TEST1.....FAILED\n");
            err_counter++;
        }
        else if (root.yes == new_node)
        {
            printf("TEST1.....PASSED\n");
            free(root.yes);
            new_node = NULL;
        }
        else
        {
            printf("TEST1.....FAILED\n");
            err_counter++;
        }  
    }

    // Тест 2

    if ((new_node = create(&some_func)) == NULL)
    {
        printf("TEST2.....FAILED\n");
        err_counter++;
    }
    else
    {
        if ((error_code = add(&root, FALSE, new_node)) != OK)
        {
            printf("TEST2.....FAILED\n");
            err_counter++;
        }
        else if (root.no == new_node)
        {
            printf("TEST2.....PASSED\n");
            free(root.no);
            new_node = NULL;
        }
        else
        {
            printf("TEST2.....FAILED\n");
            err_counter++;
        }   
    }

    // Тест 3

    node *fake_root = NULL;

    if ((new_node = create(&some_func)) == NULL)
    {
        printf("TEST3.....FAILED\n");
        err_counter++;
    }
    else
    {
        if ((error_code = add(fake_root, FALSE, new_node)) == OK)
        {
            printf("TEST3.....FAILED\n");
            err_counter++;
        }
        else
        {
            printf("TEST3.....PASSED\n");
            free(new_node);
            new_node = NULL;
        }
    }

    // Тест 4

    if ((error_code = add(&root, FALSE, new_node)) == OK)
    {
        printf("TEST4.....FAILED\n");
        err_counter++;
    }
    else
    {
        printf("TEST4.....PASSED\n");
    }

    if (err_counter)
    {
        return ERRORS_DETECTED;
    }
    
    return OK;
}