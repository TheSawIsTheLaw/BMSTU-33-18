#include "../d_trees_headers/yakuba_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

bool dead(passenger dead)
{
    return FALSE;
}

node* yakuba_d6n_tree_titanicgame()
{
    node *root = create(dead);

    return root;
}
