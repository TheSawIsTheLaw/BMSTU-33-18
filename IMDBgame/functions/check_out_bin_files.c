#include <stdio.h>

#define POS_FOR_FILM 0

int main(void)
{
    FILE *f_in = fopen("IMDBgame_functions_FILM_IDs.bin", "rb");
    FILE *f_out  = fopen("out2.bin", "wb");
    
    int film;
    int act;
    int cur;
    int n = 0;
    int i = 0;
    int sep = -1;
    
    while (fread(&cur, sizeof(int), 1, f_in) == 1)
    {
        if (cur != -1)
        {
            if (i == POS_FOR_FILM)
            {
                film = cur;
                ++i;
            }
            else
            {
                act = cur;
                fwrite(&film, sizeof(int), 1, f_out);
                fwrite(&act, sizeof(int), 1, f_out);
                fwrite(&sep, sizeof(int), 1, f_out);
                n++;
                ++i;
            }
        }
        else
        {
            i = POS_FOR_FILM;
        }
    }
    printf("%d - n\n", n);
    fclose(f_in);
    fclose(f_out);
    return 0;
}
