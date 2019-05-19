#define FILE_NAME "../data/name_basic-test.tsv"
#include <stdio.h>
#include "node.h"
#define START_PARS 74
#define FILE_ERR 1
#define OK 0

int open_file(const FILE *f)
{
    if ((f = fopen(FILE_NAME, "r")) == NULL)
    {
        return FILE_ERR;
    }

    return OK;
}
//developing
int parser_name()
{
    FILE *f;
    if (open_file(f))
    {
        return FILE_ERR;
    }
    fseek(f, START_PARS, SEEK_SET);

    while (!feof(f))
    {
        return OK;
    }
    unsigned int i = 0;
    return OK;
}

/*int main(void)
{
    setbuf(stdout, NULL);
    int a = parser_name();
    return OK;
}
*/
    
