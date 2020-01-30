#include <string.h>
#include "../d_trees_headers/sverdlov_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

bool check_age(passenger one)
{
    if (one.age > 10)
        return TRUE;
    return FALSE;
}

bool check_sex(passenger one)
{
    if (strcmp(one.sex, "female") == 0)
        return TRUE;
    return FALSE;
}

bool check_pclass(passenger one)
{
    if (one.pclass == 2)
        return TRUE;
    return FALSE;
}


node* sverdlov_d6n_tree_titanicgame()
{
    node *root = create(check_age);
    node *sex = create(check_sex);
    node *class = create(check_pclass);
    add(root, TRUE, sex);
    add(sex, TRUE, class);
    return root;
}
