#include "../f_headers/create_titanicgame.h"

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
