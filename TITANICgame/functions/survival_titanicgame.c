#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../f_headers/survival_titanicgame.h"
#include "../headers/struct.h"

int add(node *parent, bool choice, node *new_node)
{
    if (!parent)
    {
        return PARENT_IS_EMPTY;
    }

    if (!new_node)
    {
        return NODE_IS_EMPTY;
    }

    if (choice)
    {
        parent -> yes = new_node;
    }
    else
    {
        parent -> no = new_node;
    }

    return OK;
}

node* create(bool (*decision)(passenger info))
{
    node *new = NULL;

    if ((new = malloc(sizeof(node))) == NULL)
    {
        return NULL;
    }

    new -> no = NULL;
    new -> yes = NULL;
    new -> decision = decision;

    return new;
}

bool check_age(passenger a)
{
    if (a.age > 17)
        return TRUE;
    return FALSE;
}

bool check_sex(passenger a)
{
    if (strcmp(a.sex, "male") == 0)
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
    if (a.parch > 0)
        return TRUE;
    return FALSE;
}

node* decision_tree()
{
    node *root = create(&check_age);
    node *yes = create(&check_sex);
    node *yes_yes = create(&check_pclass);
    node *no = create(&check_parch);
    node *no_yes = create(&check_sex);

    add(root, TRUE, yes);
    add(yes, TRUE, yes_yes);
    add(root, FALSE, no);
    add(no, TRUE, no_yes);
    
    return root;
}

int check_survival(const passenger a, node* root)
{
    node* pt = root;
    bool result = FALSE;
    
    while (pt != NULL)
    {
        result = pt -> decision(a);
        
        if ((pt -> no == NULL) && (pt -> yes == NULL))
            return result;
        if (result == FALSE)
        {
            if( pt -> no == NULL)
                return result;
            else
                pt = pt -> no;
        }
        else
        {
            if (pt -> yes == NULL)
                return result;
            else
                pt = pt -> yes;
        }
    }
    return result;
}

int check_arr(passenger *data, const int size, const int flag, node* root)
{
    FILE *f;
    f = fopen("submission.csv", "w");
    if (f == NULL)
    {
        return FOPEN_ERROR;
    }
    fprintf(f, "PassengerId,Survived\n");
    int sum = 0;
    int result;
    for (int i = 0; i < size; i++)
    {
        result = check_survival(data[i], root);
        if ((flag == 0) && result == data[i].survived)
            sum++;
        if (flag == 1)
            fprintf(f, "%d,%d\n", data[i].passenger_id, result);
    }
    fclose(f);
    int percent = (sum / size) * PERCENT;
    
    return percent;
}

int check_void(node* (*decision_tree)(), passenger *people)
{
    node* root = decision_tree();
    int percent = check_arr(people, 3, 0, root);
    int fc = check_arr(people, 3, 1, root);
    if (fc == FOPEN_ERROR)
        return fc;
    return percent;
}

int main(int args, char **argv)
{
    passenger people[ARR_SIZE];  //structs array
    char func_name[FUNC_NAME];
    strcpy(func_name, argv[1]);
    

    people[0].passenger_id = 1;
    people[0].survived = 1;
    people[0].pclass = 1;
    strcpy(people[0].name, "Mr Owen Harris");
    strcpy(people[0].sex, "male");
    people[0].age = 22;
    people[0].siblings_sp = 1;
    people[0].parch = 0;
    strcpy(people[0].ticket, "A/5 21171");
    people[0].fare = 7.25;
    people[0].embarked = 'S';

    people[1].passenger_id = 2;
    people[1].survived = 0;
    people[1].pclass = 1;
    strcpy(people[1].name, "Mrs Owen Harris");
    strcpy(people[1].sex, "female");
    people[1].age = 15;
    people[1].siblings_sp = 1;
    people[1].parch = 0;
    strcpy(people[1].ticket, "A/5 21171");
    people[1].fare = 7.25;
    people[1].embarked = 'S';

    people[2].passenger_id = 3;
    people[2].survived = 1;
    people[2].pclass = 3;
    strcpy(people[2].name, "Mr Owen Harris");
    strcpy(people[2].sex, "female");
    people[2].age = 25;
    people[2].siblings_sp = 1;
    people[2].parch = 0;
    strcpy(people[2].ticket, "A/5 21171");
    people[2].fare = 7.25;
    people[2].embarked = 'S';

    int result = check_void(&decision_tree, people);
    printf("%d", result);
}
