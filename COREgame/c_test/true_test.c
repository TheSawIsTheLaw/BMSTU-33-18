
#include "../c_src_headers/true_headers/true_link.h"

#define SUCCESS 0

void test_true_link(void)
{
    int check = true();
    if (check == SUCCESS)
        printf("Тест пройден\n");
    else
        printf("Тест завален\n");
}

int main()
{
    test_true_link();
    
    return SUCCESS;
}
