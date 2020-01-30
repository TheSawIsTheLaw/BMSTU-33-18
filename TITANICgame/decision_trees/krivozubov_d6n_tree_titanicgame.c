#include "../d_trees_headers/krivozubov_d6n_tree_titanicgame.h"

bool age_condition(passenger person)
{
    if (person.age < 15)
    {
        return TRUE;
    }

    return FALSE;
}

bool class_condition(passenger person)
{
    if (person.pclass == 3)
    {
        return TRUE;
    }

    return FALSE;
}


bool sex_condition(passenger person)
{
    if (!strcmp(person.sex, "female"))
    {
        return TRUE;
    }

    return FALSE;
} 

node *krivozubov_d6n_tree_titanicgame()
{
    node *root = create(sex_condition);
    node *right_hook = create(age_condition);
    node *right_right_hook = create(class_condition);

    add(root, FALSE, right_hook);
    add(right_hook, FALSE, right_right_hook);

    return root;
}
