#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/struct.h"

#define TESTSET 418
#define TRAINSET 891
#define UNDEFINED 4

#define OK 0

char *get_field(char *const line, int field)
{
    char *tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--field)
            return tok;
    }

    return NULL;
}

int compare_none(char *const str)
{
    if (strcmp(str, "None"))
    {
        return 1;
    }

    return 0;
}

void parse(passenger *const test_p, passenger *const train_p)
{
    FILE *test = fopen("data/test.csv", "r");
    FILE *train = fopen("data/train.csv", "r");

    for (int data = 0; data < TRAINSET; ++data)
    {
        char line[MAX_STRING_LEN], tmp[MAX_STRING_LEN], field[MAX_STRING_LEN];
        fgets(line, MAX_STRING_LEN, train);
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 1));
        if (compare_none(field))
        {
            train_p[data].passenger_id = -1;
        }
        else
        {
            train_p[data].passenger_id = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 2));
        if (compare_none(field))
        {
            train_p[data].survived = -1;
        }
        else
        {
            train_p[data].survived = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 3));
        if (compare_none(field))
        {
            train_p[data].pclass = -1;
        }
        else
        {
            train_p[data].pclass = atoi(field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 4));
        if (compare_none(field))
        {
            strcpy(train_p[data].name, "\0");
        }
        else
        {
            strcpy(train_p[data].name, field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 5));
        if (compare_none(field))
        {
            strcpy(train_p[data].surname, "\0");
        }
        else
        {
            strcpy(train_p[data].surname, field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 6));
        if (compare_none(field))
        {
            strcpy(train_p[data].status, "\0");
        }
        else
        {
            strcpy(train_p[data].status, field);
        }
        strcpy(tmp, line);

        strcpy(field, get_field(tmp, 7));
        if (compare_none(field))
        {
            strcpy(train_p[data].sex, "\0");
        }
        else
        {
            strcpy(train_p[data].sex, field);
        }
        strcpy(tmp, line);
    }

    fclose(test);
    fclose(train);
}