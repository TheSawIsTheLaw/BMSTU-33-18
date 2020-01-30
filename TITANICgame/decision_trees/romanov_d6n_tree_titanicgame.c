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

bool children_rand(passenger chelik)
{
    if (!(chelik.passenger_id % 3))
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

bool woman_third_grade_rand(passenger chelik)
{
    if ((!chelik.passenger_id % 2))
    {
        return TRUE;
    }

    return FALSE;
}

bool is_fst(passenger chelik)
{
    if (chelik.pclass == 1)
    {
        return TRUE;
    }

    return FALSE;
}

bool first_grade_rand(passenger chelik)
{
    if ((!chelik.passenger_id % 3))
    {
        return TRUE;
    }

    return FALSE;
}

bool second_grade_rand(passenger chelik)
{
    if ((!chelik.passenger_id % 11))
    {
        return TRUE;
    }

    return FALSE;
}

bool third_grade_rand(passenger chelik)
{
    if ((!chelik.passenger_id % 5))
    {
        return TRUE;
    }

    return FALSE;

}

node *romanov_d6n_tree_titanicgame()
{
    node *root = create(check_age);
    node *grade = create(check_grade);
    node *children = create(children_rand);
    node *not_children = create(check_sex);
    node *woman_class = create(check_grade);
    node *woman_third_grade = create(woman_third_grade_rand);
    node *not_woman_grade = create(check_grade);
    node *is_fst_grade = create(is_fst);
    node *first_grade = create(first_grade_rand);
    node *second_grade = create(second_grade_rand);
    node *third_grade = create(third_grade_rand);

    add(root, TRUE, grade);
    add(grade, FALSE, children);
    add(root, FALSE, not_children);

    add(not_children, TRUE, woman_class);
    add(woman_class, FALSE, woman_third_grade);
    add(not_children, FALSE, woman_class);

    add(not_children, FALSE, not_woman_grade);
    add(not_woman_grade, TRUE, is_fst_grade);
    add(is_fst_grade, TRUE, first_grade);
    add(is_fst_grade, FALSE, second_grade);
    add(not_woman_grade, FALSE, third_grade);

    return root;
}
