#include "node.h"

#define MAX_NAME_SIZE 32

// f_id_name - имя файла с id и именем актера
// f_neighbours - имя файла с набором соседей актера
// array - массив структур 

typedef const char c_c;
typedef unsigned int u_i;

void cut_name(FILE* f_p, char *name)
{
    u_i length = 0u;
    char symb = fgetc(f_p);
    while (symb == ' ')
        symb = fgetc(f_p);
    if (symb == '\n')
    {
        name[0] = '\0';
    }
    else
    {
        ungetc(symb, f_p);
        while (symb != '\n')
        {
            if (length == MAX_NAME_SIZE - 1)
                break;
            name[length] = symb;
            length++;
            symb = fgetc(f_p);
        }
        name[length] = '\0';
    }
    while (symb != '\n')
        symb = fgetc(f_p);
}

void fill_struct(c_c *const f_id_name, c_C *const f_neighbours, node *const array)
{

    FILE *fp_1 = fopen(f_id_name, "r");
    FILE *fp_2 = fopen(f_neighbours, "r");

    if (fp_1 && fp_2)
    {
        u_i i = 0u; // Номер записи
        char ending = fgetc(fp_2);
        while (ending != EOF)
        {
            ungetc(symb, f_p);
            fscanf(fp_1, "%u", &(array[i].id));
            cut_name(fp_1, array[i].name);
            array[i] = structure;
            fill_neighbours(fp_2, );
            i++;
            ending = fgetc(fp_2);
        }
    }
}
