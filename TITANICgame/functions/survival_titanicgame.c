#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../f_headers/survival_titanicgame.h"
#include "../headers/struct.h"
#include "../f_headers/add_titanicgame.h"
#include "../f_headers/create_titanicgame.h"
#include "../f_headers/delete_titanicgame.h"
#include "../d_trees_headers/member_name_header.h"

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
    f = fopen("./TITANICgame/submission/submission.csv", "w");
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
    int percent = ((sum * 1.0) / size) * PERCENT;
    
    return percent;
}

int check_void(node* (*decision_tree)(), passenger *train, passenger *test)
{
    node* root = decision_tree();
    int percent = check_arr(train, TRAINSET, 0, root);
    int fc = check_arr(test, TESTSET, 1, root);
    if (fc == FOPEN_ERROR)
    {
        delete_vertex(root);
        return fc;
    }
    delete_vertex(root);
    return percent;
}


int main()
{
    passenger train[TRAINSET], test[TESTSET];  //structs array

    parse(test, train);
    int result = check_void(function_name, train, test);
    printf("%d", result);
}
