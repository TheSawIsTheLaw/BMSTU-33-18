#ifndef SURVIVAL_H_

#define SURVIVAL_H_

#include "create_titanicgame.h"
#include "add_titanicgame.h"
#include "../headers/struct.h"
#include "stdlib.h"
#define FOPEN_ERROR -2
#define FUNC_NAME 256
#define PERCENT 100
#define ARR_SIZE 3
#define MAX 1

bool check_age(passenger a);
bool check_sex(passenger a);
bool check_pclass(passenger a);
bool check_parch(passenger a);
node* decision_tree();
int check_survival(const passenger a, node* root);
int check_arr(passenger *data, const int size, const int flag, node* root);
int check_void(node* (*decision_tree)(), passenger *train, passenger *test);

#endif

