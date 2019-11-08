#include <string.h>

#include "../d_trees_headers/romanov_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

bool check_age(passenger chelik)
{
    if (chelik.age == -1)
    {
        return FALSE;
    }

    if (chelik.age < 16)
    {
        return TRUE;
    }

    return FALSE;
}

bool check_sex(passenger chelik)
{
    if (!strcmp("female", chelik.sex))
    {
        return TRUE;
    }

    return FALSE;
}

bool check_grade(passenger chelik)
{
    if (chelik.pclass <= 2)
    {
        return TRUE;
    }

    return FALSE;
}

node *romanov_d6n_tree_titanicgame()
{
    node *root = create(check_age);
    node *grade = create(check_grade);
    node *third_grade = create(check_sex);

    add(root, TRUE, grade);
    add(root, FALSE, third_grade);

    return root;
}
