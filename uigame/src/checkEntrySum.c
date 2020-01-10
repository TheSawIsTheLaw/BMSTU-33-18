#include <stdio.h>
#include <string.h>
#include "../include/ui.h"
#include "../include/checkEntrySum.h"

int check_entry_sum(char *str)
{
    int i = 0, numbers_after_dot = 0;
    int dot_flag = 0, non_zero_flag = 0;
    int len;
    
    len = strlen(str);
    
    // Убираем лишние нули в начале
    while (str[i] == 48)
    {
        i++;
    }
    
    if (i == len)
        return 1;
    
    for (int k = 0; k < len - i; k++)
    {
        str[k] = str[k + i];
    }
    for (int k = len - i; k < len; k++)
        str[k] = 0;
        
    len = strlen(str);
    
    i = 0;
    // Проверка, если число начинается с точки и дорисовка нуля
    if (str[0] == '.')
    {
        for (i = len; i > 0; i--) str[i] = str[i-1];
        str[0] = 48;
    }
    i = 0;
    len = strlen(str);
    
    // Проверяем правильность ввода
    while (str[i])
    {
        if (dot_flag)
            numbers_after_dot++;
            
        if ((str[i] < 48 || str[i] > 57) && str[i] != '.')
            return 1; 
        
        if (str[i] != 48 && str[i] != '.')
            non_zero_flag = 1;
        
        if (str[i] == '.' && dot_flag == 0)
            dot_flag = 1;
            
        else if (str[i] == '.' && dot_flag)
            return 1;
        
        i++;
    }
    
    if (non_zero_flag && numbers_after_dot < 3)
        return 0;
    else
        return 1;
}

