/* yes -- output a string repeatedly untill killed
   function by Simonenko Emil
*/


#include <string.h>
#include "../c_src_headers/yes_link.h"

#define EXIT_FAILURE 1
#define OUTSTRMAXLEN 255

/* The official name of this function (e.g., no 'g' prefix).  */
#define FUNC_NAME "yes"


#define AUTHORS proper_name ("Emil Simonenko")

int
yes(char *argv)
{
    char outstr[OUTSTRMAXLEN];
    if (argv == NULL)
    {
        strcpy(outstr,"y");
    }
    else
    {
        strcpy(outstr, argv);
    }
    
    while(printf("%s", outstr) > 0)
        continue;
       
    return EXIT_FAILURE;
}