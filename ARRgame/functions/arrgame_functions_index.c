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

#define XD -1

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