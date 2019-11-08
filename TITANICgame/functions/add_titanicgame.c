#include "../f_headers/add_titanicgame.h"

int add(node *parent, bool choice, node *new_node)
{
    if (!parent)
    {
        return PARENT_IS_EMPTY;
    }

    if (!new_node)
    {
        return NODE_IS_EMPTY;
    }

    if (choice)
    {
        parent -> yes = new_node;
    }
    else
    {
        parent -> no = new_node;
    }

    return OK;
}