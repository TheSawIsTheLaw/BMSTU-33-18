#include <string.h>
#include "../headers/struct.h"
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
    if (chelik.fare > SECOND_GRADE)
    {
        return TRUE;
    }

    return FALSE;
}

bool dead(passenger chelik)
{
    return FALSE;
}

bool alive(passenger chelik)
{
    return TRUE;
}

node *romanov__d6n_tree_titanic_game()
{
    node *root = create(check_grade);
    node *first_second_grade = create(check_sex);
    node *first_second_grade_not_woman = create(check_age);

    add(root, TRUE, first_second_grade);
    add(root, FALSE, dead);
    add(first_second_grade, TRUE, alive);
    add(first_second_grade, FALSE, first_second_grade_not_woman);
    add(first_second_grade_not_woman, TRUE, alive);
    add(first_second_grade_not_woman, FALSE, dead);

    return root;
}
