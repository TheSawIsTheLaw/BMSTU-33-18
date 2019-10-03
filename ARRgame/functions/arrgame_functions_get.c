#include "../headers/arrgame.h"

#define SERVICE_INFO 3
#define POS_ERROR 1
#define ZERO 0


// Индексация позиций с нуля (то есть если запрашивается 5ый
// элемент по индексу из 5 массиве, то вылетит птичка (ошибка))
// Аллокация памяти отсутствует
// При корректной работе в errno кладется 0, иначе ненулевое значение
int arrgame_get(const int *const array, const int pos)
{
    if (*(array - SERVICE_INFO) - pos <= 0 || pos < 0) // Ненавижу создателя creat(e).
    {
        return ZERO;
    }
    return *(array + pos);
}
