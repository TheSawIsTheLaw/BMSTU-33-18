#include <stdio.h>
#include <string.h>

#include "../d_trees_headers/akhmetov_d6n_tree_titanicgame.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"

#define EPS 0.001

#define AGE_MAX_FOR_FIND 16.0
#define AGE_MIN_FOR_FIND 0.0
#define MIN_FARE_FOR_FIND 62.5

bool check_age(passenger a)
{
    if (a.age <= 18 || (a.age > 19 && a.age < 29) || (a.age >= 30 && a.age <= 36) || (a.age >= 47 && a.age <= 60))
        return TRUE;
    return FALSE;
}

bool check_sex(passenger a)
{
    if (strcmp(a.sex, "female") == 0)
        return TRUE;
    return FALSE;
}

bool check_pclass(passenger a)
{
    if (a.pclass == 1)
        return TRUE;
    return FALSE;
}

bool check_parch(passenger a)
{
    if (a.parch <= 2)
        return TRUE;
    return FALSE;
}

node* akhmetov_d6n_tree_titanicgame()
{
    node *root = create(check_age);
    node *yes = create(check_sex);
    node *yes_yes = create(check_pclass);
    node *no = create(check_parch);
    node *no_yes = create(check_sex);

    add(root, TRUE, yes);
    add(yes, TRUE, yes_yes);
    add(root, FALSE, no);
    add(no, TRUE, no_yes);
    
    return root;
}


