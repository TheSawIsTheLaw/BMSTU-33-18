#include <stdio.h>

#define N 4713814 - 509712
//#define N 1000000
#define OK 0

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "rb");
    unsigned int id1;
    int id = 0;

    for (int i = 0; i < N; i++)
    {
        fread(&id1, sizeof(id1), 1, f);
        if (id1 == -1)
        {
            puts("=============");
            fread(&id, sizeof(id), 1, f);
            printf("FILM ID: %d\n", id);
        }
        else
        {
            printf("ID %d \n", id1);
        }
    }
    return OK;
}
