#include <stdio.h>


int main()
{
    FILE *f;
    int d, prev;
    f = fopen("data/FILM_IDs.bin", "rb");
    while (1)
    {
        prev = d;
        if (fread(&d, sizeof(int), 1, f) == 0)
            return 0;
        if (d == 262532)
            printf("%d %d", prev, d);
    }
}
