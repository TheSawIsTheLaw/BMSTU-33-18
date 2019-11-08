#include <string.h>

#include "../d_trees_headers/minenko_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

bool check_sex(passenger human)
{
    if (strcmp(human.sex, "male") == 0)
        return TRUE;
    return FALSE;
}

node* minenko_d6n_tree_titanicgame()
{
    node *root = create(check_sex);
    
    return root;
}
