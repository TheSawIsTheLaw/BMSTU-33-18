#include <stdio.h>
#define OK 0

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "rb");
    unsigned int id1;

    for (int i = 0; i < 1000; i++)
    {
        fread(&id1, sizeof(id1), 1, f);
        if (id1 == -1)
            puts("=============");
        printf("%d |\n", id1);
    }
    return OK;
}
