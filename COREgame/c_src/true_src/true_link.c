#include "../../c_src_headers/true_headers/true_link.h"

/* true -- true does nothing except return an exit status of 0, meaning success
*/

#define EXIT_SUCCESS 0

#define FUNC_NAME "true"
#define AUTHORS proper_name ("Sverdlov Sergey")

int true()
{
    return EXIT_SUCCESS;
}
