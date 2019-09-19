#include <stdio.h>
#include <stdlib.h>
#define CORRECT 0
#define INCORRECT 1
#define BADCODE 5051
#define XD -1
#include "../headers/arrgame_headers_index.h"


/*
Функция index
Ввод -  int  1)X, вхождение которого надо проверить,
        int* 2)адрес первого элемента массива(после технической информации о массиве),
        int  3)номер(не адрес) начального элемента и
        int  4)номер конечного.

Вывод - int номер первого вхождения X или, если X не встречен возвращается XD(-1)

Подразумевается передача в функцию ВАЛИДНОГО отрезка от start до stop !!!
Переменные: i - счётчик

*/

/*
Проверки на выход за границы массива не выполняются.
Проверка на вхождение ВКЛЮЧАЕТ в себя start и stop
(В случае непредвиденной ошибки -> errno = BADCODE(5051)) - не реализовано
В случае, если start > stop - функция работает нормально(шаг 1 -> -1)
Подразумевается, что нумерация элементов массива
(а не служебной информации о нём) начинается с 0
При корректной работе в errno кладется 0
*/


//коды ошибок:

//#define XD -1

//#define BADCODE 5051
//#define OK 0

//extern int errno; // код ошибки

int* get_addr_by_num(int* arr_addr, int num)
{
    int* adr = arr_addr;
    int i = 0;
    while (i < num)
    {
        adr++;
        i++;
    }
    return adr;
}

int indexx(const int x, int* arr_adr, const int start, const int stop)
{
    //errno = BADCODE;
    int i = 0;
    if (start > stop)
        while ((start+i) > stop)
        {
            if (x == *(get_addr_by_num(arr_adr, start + i)))
                return (start + i);
            i--;
        }
	else
        if (start == stop)
		{
            if (x == *(get_addr_by_num(arr_adr, start)))
                return start;
		}
        else
            while (start+i < stop)
            {
                if (x == *(get_addr_by_num(arr_adr, start + i)))
                    return (start + i);
                i++;
            }

    //errno = OK;
    return XD;
}

int main()
{
    int array[13];
/*
Тепличный тест
*/
    //OK
    int arr1[] = {1, 30, -22, 16, 21, -5};
    int x1 = -22;
    int start1 = 0;
    int stop1 = 5;
    if (indexx(x1, arr1, start1, stop1) == 2)
        array[0] = CORRECT;
    else
        array[0] = INCORRECT;

    int arr2[] = {22, 33, -21, 69, 228, -1};
    int x2 = 69;
    int start2 = 1;
    int stop2 = 4;
    if (indexx(x2, arr2, start2, stop2) == 3)
        array[1] = CORRECT;
    else
        array[1] = INCORRECT;

    int arr3[] = {51, -130, -272, -6, 27, -35, 229};
    int x3 = 229;
    int start3 = 6;
    int stop3 = 2;
    if (indexx(x3, arr3, start3, stop3) == 6)
        array[2] = CORRECT;
    else
        array[2] = INCORRECT;

    int arr4[] = {12, -72, 343, -4555, 27, -966};
    int x4 = -4555;
    int start4 = 3;
    int stop4 = 3;
    if (indexx(x4, arr4, start4, stop4) == 3)
        array[3] = CORRECT;
    else
        array[3] = INCORRECT;
    //NOT OK
    int arr5[] = {1, -2, 33, -45, 67, -9966};
    int x5 = 0;
    int start5 = 0;
    int stop5 = 5;
    if (indexx(x5, arr5, start5, stop5) == XD)
        array[4] = CORRECT;
    else
        array[4] = INCORRECT;

    int arr6[] = {272, 343, -721, 969, 1421, -222};
    int x6 = 272;
    int start6 = 1;
    int stop6 = 3;
    if (indexx(x6, arr6, start6, stop6) == XD)
        array[5] = CORRECT;
    else
        array[5] = INCORRECT;

    int arr7[] = {51, -130, -272, -6, 27, -35, 229, -696};
    int x7 = 229;
    int start7 = 6;
    int stop7 = 2;
    if (indexx(x7, arr7, start7, stop7) == 6)
        array[6] = CORRECT;
    else
        array[6] = INCORRECT;

    int arr8[] = {51, -130, -272, -6, 27, -35, 229, -696};
    int x8 = 229;
    int start8 = 2;
    int stop8 = 7;
    if (indexx(x8, arr8, start8, stop8) == 6)
        array[7] = CORRECT;
    else
        array[7] = INCORRECT;



/*
Граничный тест
*/
    //OK
    int arr9[] = {-2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647};
    int x9 = -2147483648;
    int start9 = 0;
    int stop9 = 11;
    if (indexx(x9, arr9, start9, stop9) == 0)
        array[8] = CORRECT;
    else
        array[8] = INCORRECT;

    int arr10[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int x10 = 0;
    int start10 = 0;
    int stop10 = 0;
    if (indexx(x10, arr10, start10, stop10) == 0)
        array[9] = CORRECT;
    else
        array[9] = INCORRECT;



    int arr11[1000];
    int elem;
    for (int i = 0; i < 1000; i ++)
    {
        elem = rand();
        if (elem != 3)
        {
            arr11[i] = elem;
        }
        if (i == 998)
        {
            arr11[i] = 3;
        }
    }
    int x11 = 3;
    int start11 = 0;
    int stop11 = 999;
    if (indexx(x11, arr11, start11, stop11) == 998)
        array[10] = CORRECT;
    else
        array[10] = INCORRECT;



    //NOT OK
    int arr12[] = {-2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647};
    int x12 = 0;
    int start12 = 0;
    int stop12 = 7;
    if (indexx(x12, arr12, start12, stop12) == XD)
        array[11] = CORRECT;
    else
        array[11] = INCORRECT;

    int arr13[] = {-2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647, -2147483648, 2147483647};
    int x13 = -2147483648;
    int start13 = 1;
    int stop13 = 1;
    if (indexx(x13, arr13, start13, stop13) == XD)
        array[12] = CORRECT;
    else
        array[12] = INCORRECT;


    for (int i = 0; i < 13; i ++)
    {
        if (array[i] == CORRECT)
            printf("Test no.%d works correct\n", i + 1);
        else
            printf("Test no.%d works incorrect\n", i + 1);
    }
}
