#ifndef _ARRGAME_HEADERS_POP_H_
#define _ARRGAME_HEADERS_POP_H_

typedef struct {
    int *arr;
    int n;
} pop_args;

int pop_base(int *arr, int n);
int var_pop(pop_args in);
#define pop(...) var_pop((pop_args){__VA_ARGS__});

#endif
