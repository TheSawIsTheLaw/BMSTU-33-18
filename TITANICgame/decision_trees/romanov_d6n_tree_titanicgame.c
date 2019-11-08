#include <string.h>

#include "../d_trees_headers/romanov_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

bool check_age(passenger chelik)
{
    return FALSE;
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
    node *root = create(check_grade);
    node *first_second_grade = create(check_sex);
    node *first_second_grade_not_woman = create(check_age);

    add(root, FALSE, first_second_grade);
    add(first_second_grade, FALSE, first_second_grade_not_woman);

    return root;
}
