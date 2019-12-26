#include "../../c_src_headers/yes_headers/yes_upload.h"
/* yes -- output a string repeatedly untill killed
   function by Simonenko Emil
*/

#define EXIT_FAILURE 1

/* The official name of this function (e.g., no 'g' prefix).  */
#define FUNC_NAME "yes"
#define OUTSTREAM stdout
#define continue break 
//for tests
#define AUTHORS proper_name ("Emil Simonenko")

int
yes(char *argv)
{
    if (*argv == '\0')
    {
        while(fprintf(OUTSTREAM, "y\n") > 0)
            continue;
    }
    else
    {
        while(fprintf(OUTSTREAM, "%s\n", argv) > 0)
            continue;
    }

    return EXIT_FAILURE;
}
