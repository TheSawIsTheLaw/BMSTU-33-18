#include <stdio.h>
#define OK 0

int main(int argc, char *argv[])
{
    FILE *f = fopen(argv[1], "rb");
    char name[36];
    unsigned int id1;

    for (int i = 0; i < 100; i++)
    {
        fread(&id1, sizeof(id1), 1, f);
        fread(&name, sizeof(name), 1, f);
        printf("%u\n\n", id1);
        puts(name);
    }
    return OK;
}
