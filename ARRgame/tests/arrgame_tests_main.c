// #include "../headers/arrgame_headers_get.h"
#include <stdio.h>
#include <errno.h>

#define OK 0
#define SERVICE_INFO 3
#define POS_ERROR 1
#define ZERO 0
#define ERROR -1

extern int errno;

int get(const int *const array, const int pos)
{
    if (*(array - SERVICE_INFO) - pos <= 0 || pos < 0)
    {
        errno = POS_ERROR;
        return ZERO;
    }
    return *(array + pos);
}

int main(void)
{
    int count = 1;
    errno = ZERO;

    // Тепличные тесты
    int arr1[] = {4, 0, 0, 10, 11, 12, 13};

    if (get(arr1 + SERVICE_INFO, 2) != 12)
    {
        printf("Ошибка на тесте: %d\n", count);
        return ERROR;
    }
    count++;

    // Граничные тесты
    if (get(arr1 + SERVICE_INFO, 0) != 10)
    {
        printf("Ошибка на тесте: %d\n", count);
        return ERROR;
    }
    count++;

    if (get(arr1 + SERVICE_INFO, 3) != 13)
    {
        printf("Ошибка на тесте: %d\n", count);
        return ERROR;
    }
    count++;

    // Запредельные тесты 
    int arr2[] = {0};

    if (!get(arr1 + SERVICE_INFO, 999) && errno != POS_ERROR)
    {
        printf("Ошибка на тесте: %d\n", count);    
        return ERROR;
    }
    errno = ZERO;
    count++;

    if (!get(arr2 + SERVICE_INFO, 0) && errno != POS_ERROR)
    {
        printf("Ошибка на тесте: %d\n", count);    
        return ERROR;
    }
    errno = ZERO;
    count++;

    if (!get(arr1 + SERVICE_INFO, -1) && errno != POS_ERROR)
    {
        printf("Ошибка на тесте: %d\n", count);    
        return ERROR;
    }
    errno = ZERO;
    count++;

    if (!get(arr1 + SERVICE_INFO, 4) && errno != POS_ERROR)
    {
        printf("Ошибка на тесте: %d\n", count);    
        return ERROR;
    }
    errno = ZERO;
    count++;

    int arr3[] = {0, 0, 0};

    if (!get(arr3 + SERVICE_INFO, 10) && errno != POS_ERROR)
    {
        printf("Ошибка на тесте: %d\n", count);    
        return ERROR;
    }
    errno = ZERO;
    count++;
    printf("Прошло %d из 9 тестов!\n", count);

    return OK;   
}
