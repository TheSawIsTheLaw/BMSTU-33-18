#include "string.h"

#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"
#include "../d_trees_headers/burtelov_d6n_tree_titanicgame.h"

#define AGE_CHILDREN 13
#define AGE_TEENAGER 20
#define AGE_MIDDLE 50

//Gender
bool check_gender(passenger lucky)
{
    if (strcmp(lucky.sex, "female") == 0)
        return TRUE;
    return FALSE;
}
//AGE
bool check_age_children(passenger lucky)
{
    if (lucky.age > AGE_CHILDREN && lucky.age <= AGE_TEENAGER)
        return TRUE;
    return FALSE;
}

bool check_age_baby(passenger lucky)
{
    if (lucky.age > 0 && lucky.age <= AGE_CHILDREN)
        return TRUE;
    return FALSE;
}

bool check_age_old(passenger lucky)
{
    if (lucky.age > AGE_MIDDLE)
        return TRUE;
    return FALSE;
}

bool check_age_middle(passenger lucky)
{
    if (lucky.age > AGE_TEENAGER && lucky.age <= AGE_MIDDLE)
        return TRUE;
    return FALSE;
}

bool check_old(passenger lucky)
{
    if (check_age_baby(lucky) == TRUE || check_age_children(lucky) == TRUE)
        return TRUE;
    else
        return FALSE;
}

//CLASS
bool check_class_baby(passenger lucky)
{
    if (lucky.pclass == 1 || lucky.pclass == 2)
    {
        if (lucky.siblings_sp == 0)
            return FALSE;
        else if (lucky.siblings_sp == 0 && lucky.parch == 0)
            return FALSE;
        else if (lucky.siblings_sp >= 1 && lucky.parch == 0)
            return TRUE;
        else if (lucky.parch >=1)
            return TRUE;
    }
    else if (lucky.pclass == 3)
    {
        if (lucky.siblings_sp == 0)
            return FALSE;
        else if (lucky.siblings_sp == 0 && lucky.parch == 0)
            return FALSE;
        else if (lucky.siblings_sp >= 3 && (lucky.parch >= 1 && lucky.parch <= 2))
            return FALSE;
                else if (lucky.parch >= 2)
            return TRUE;
    }
    
    return FALSE;
}

bool check_class_ch(passenger lucky)
{
    if (lucky.pclass == 1 || lucky.pclass == 2)
    {
        if (lucky.siblings_sp == 0)
            return FALSE;
        else if (lucky.siblings_sp == 0 && lucky.parch == 0)
            return FALSE;
        else if (lucky.siblings_sp >= 1)
            return TRUE;
        else if (lucky.parch >=1)
            return TRUE;
    }
    else if (lucky.pclass == 3)
    {
        if (lucky.siblings_sp == 0)
            return FALSE;
        else if (lucky.siblings_sp == 0 && lucky.parch == 0)
            return FALSE;
        else if (lucky.siblings_sp >= 4 && lucky.parch == 2)
            return FALSE;
        else if (lucky.siblings_sp >= 2 && lucky.parch == 1)
            return TRUE;
        else if (lucky.parch >=2)
            return TRUE;
    }
    
    return FALSE;
}

bool check_class_mid_f(passenger lucky)
{
    if (lucky.pclass == 1 || lucky.pclass == 2)
    {
        if (lucky.parch <= 3)
            return TRUE;
        else if (lucky.parch <= 4 && lucky.embarked == 'C')
            return TRUE;
        else
            return FALSE;
    }
    else if (lucky.pclass == 3)
    {
        if (lucky.parch <= 2)
            return TRUE;
        else if (lucky.parch <= 3 && lucky.embarked == 'C')
            return TRUE;
        else
            return FALSE;
    }
    return FALSE;
}

bool check_class_mid_m(passenger lucky)
{
    if (lucky.pclass == 1)
    {
        if (lucky.parch == 0 && lucky.siblings_sp == 0)
            return TRUE;
        if (lucky.parch <= 1 && lucky.siblings_sp <= 1 && lucky.embarked == 'C')
            return TRUE;
        else
            return FALSE;
    }
    else if (lucky.pclass == 2)
    {
        if (lucky.parch <= 1 && lucky.siblings_sp == 0 && lucky.embarked == 'C')
            return TRUE;
        else if (lucky.parch == 1 && lucky.siblings_sp == 0 && lucky.embarked == 'C')
            return TRUE;
        return FALSE;
    }
    else if (lucky.pclass == 3)
    {
        if (lucky.parch == 0 && lucky.siblings_sp == 0 && lucky.embarked == 'C')
            return TRUE;
        else
            return FALSE;
    }
    return FALSE;
}

bool check_class_old_f(passenger lucky)
{
    if (lucky.pclass == 1)
    {
        if (lucky.parch <= 1 && lucky.siblings_sp <= 1)
            return TRUE;
        else if (lucky.parch <= 2 && lucky.siblings_sp <= 1 && lucky.embarked == 'C')
            return TRUE;
        else
            return FALSE;
    }
    else if (lucky.pclass == 2)
    {
        if (lucky.parch == 1 && lucky.siblings_sp == 0 && lucky.embarked == 'C')
            return TRUE;
        else
            return FALSE;
    }
    else if (lucky.pclass == 3)
    {   
        if (lucky.parch == 0 && lucky.siblings_sp == 0 && lucky.embarked == 'C')
            return TRUE;
        else
            return FALSE;
    }
    
    return FALSE;
}

bool check_class_old_m(passenger lucky)
{
    if (lucky.pclass == 1)
    {
        if (lucky.parch <= 1 && lucky.siblings_sp == 1)
            return TRUE;
        else
            return FALSE;
    }
    else if (lucky.pclass == 2)
        {
            if (lucky.parch == 0 && lucky.siblings_sp == 0 && lucky.embarked == 'C')
                return TRUE;
        }
    else if (lucky.pclass == 3)
        return FALSE;

    return FALSE;
}

node* burtelov_d6n_tree_titanicgame()
{
    node *root = create(check_old);

    //Возраст
    node *age_children = create(check_age_baby);
    node *age_old = create(check_age_middle);

    //Пол
    node *gender_middle = create(check_gender);
    node *gender_old = create(check_gender);

    //Класс + (родственники, порт)
    node *class_baby = create(check_class_baby);

    node *class_ch = create(check_class_ch);

    node *class_mid_f = create(check_class_mid_f);
    node *class_mid_m = create(check_class_mid_m);

    node *class_old_f = create(check_class_old_f);
    node *class_old_m = create(check_class_old_m);

    //Соединяем вершины
    add(root, TRUE, age_children);
    add(root, FALSE, age_old);

    add(age_children, TRUE, class_baby);
    add(age_children, FALSE, class_ch);

    add(age_old, TRUE, gender_middle);
    add(age_old, FALSE, gender_old);

    add(gender_middle, TRUE, class_mid_f);
    add(gender_middle, FALSE, class_mid_m);
    add(gender_old, TRUE, class_old_f);
    add(gender_old, FALSE, class_old_m);

    return root;
}