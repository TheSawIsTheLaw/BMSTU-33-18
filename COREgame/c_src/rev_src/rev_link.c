#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include "../../c_src_headers/rev_headers/rev_link.h"

static void rev_src(FILE *fp)
{
    static char *line = NULL;
    static size_t size = 0;
    size_t i;
    ssize_t n;
    int lf;

    while ((n = getline(&line, &size, fp)) > 0)
    {
        lf = n && line[n - 1] == '\n';
        i = n -= lf;   // n -= lf; i = n; 

        for (n = 0; i--; ) 
        {
            // 0xC0 = 11000000
            // 0x80 = 10000000
            if ((line[i] & 0xC0) == 0x80)
            {
                n++;
            }
            else 
            {
                fwrite(line + i, 1, n + 1, stdout);
                n = 0;
            }
        }

        if (n)
            fwrite(line, 1, n, stdout);

        if (lf)
            fputc('\n', stdout);
    }
}


// char *argv here is simply string (either "" or "<filename>")
int rev(int argc, char *argv)
{
    FILE *fp;
    int ret = 0;

    // Reverse stdin 
    if (!argc)
    {
        rev_src(stdin);
    }
    // Reverse file
    else 
    {
        // File opening failure
        if (!(fp = fopen(argv, "r")))
        {
            fprintf(stderr, "Unable to open file!\n");
            ret = 1;
        }
        else
        {
            rev_src(fp);

            // Closing file failure
            if (fclose(fp))
            {
                fprintf(stderr, "Unable to close file!\n");
                ret = 1;
            }
        }
    }

    return ret;
}

