#include <string.h>

#include "../d_trees_headers/romanov_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

#define FIRST_GRADE 3330
#define SECOND_GRADE 65

bool check_age(passenger chelik)
{
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
    if (chelik.fare >= SECOND_GRADE)
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

    add(root, TRUE, first_second_grade);
    add(first_second_grade, FALSE, first_second_grade_not_woman);

    return root;
}
