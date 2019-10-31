#ifndef __ARRGAME_H__
#define __ARRGAME_H__

typedef struct {
    int *arr;
    int n;
} pop_args;

#define arrgame_pop(...) arrgame_pop_var((pop_args){__VA_ARGS__});


int arrgame_clean(int *p_beg, int *p_end);

int arrgame_count(const int x, int const* start, const int length);

int *arrgame_create(const int sizeArray);

int *arrgame_extend(int *arra, const int *const arrb);

void arrgame_filter(int (*f) (int), int *arr);

int arrgame_get(const int *const array, const int pos);

int arrgame_index(const int x, int* arr_adr, const int start, const int stop);

int *arrgame_leftappend(int *array, int element);

void arrgame_map(void (*f) (int *), int *arr);

int arrgame_pop_var(pop_args in);

int arrgame_reduce(int (*f) (int, int), int *arr);

int arrgame_reverse(int *head, int *tail);

int arrgame_set(int *const array, const int num_to_be_set, const int pos);

void arrgame_sort(int *head, int *tail, int key);

#endif
