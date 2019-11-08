#include <stdio.h>
#include <string.h>

#include "../d_trees_headers/toporkov_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

#define EPS 0.001

#define AGE_MAX_FOR_FIND 11.0
#define AGE_MIN_FOR_FIND 0.0
#define MIN_FARE_FOR_FIND 62.5

bool get_info_sex(passenger solver)
{
    switch (strcmp(solver.sex, "female"))
    {
        case 0:
            return TRUE;
        default:
            break;
    }
    return FALSE;
}

bool get_info_age(passenger solver)
{
    if ((solver.age - AGE_MAX_FOR_FIND < EPS) && (solver.age - AGE_MIN_FOR_FIND > EPS))
        return TRUE;

    return FALSE;
}

bool get_info_fare(passenger solver)
{
    if (solver.fare - MIN_FARE_FOR_FIND > EPS)
        return TRUE;

    return FALSE;
}

bool get_info_class(passenger solver)
{
    if (solver.pclass < 3)
        return TRUE;
    return FALSE;
}

node* toporkov_d6n_tree_titanicgame()
{
    node *root = create(get_info_sex);
    node *age = create(get_info_age);
    node *fare = create(get_info_fare);

    add(root, FALSE, age);
    add(age, FALSE, fare);

    return root;
}
