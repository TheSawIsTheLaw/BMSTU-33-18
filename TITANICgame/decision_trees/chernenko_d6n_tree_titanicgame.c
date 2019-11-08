#include "string.h"

#include "../headers/struct.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"
#include "../d_trees_headers/chernenko_d6n_tree_titanicgame.h"


bool sex_split(passenger sample)
{
    if (strcmp(sample.sex, "female") == 0)
        return TRUE;
    else
        return FALSE;
}

bool class_split(passenger sample)
{
    if (sample.pclass <= 2)
        return TRUE;
    else
        return FALSE;
}

node *chernenko_d6n_tree_titanicgame()
{
    node *root = create(sex_split);
    node *if_female = create(class_split);

    add(root, TRUE, if_female);
    
    return root;
}
