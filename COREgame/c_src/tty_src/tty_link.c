#include "../../c_src_headers/tty_headers/tty_link.h"

static void usage()
{
    fprintf(stderr, "path\n");
}

int tty(int argc, char **argv)
{
    int optc;
    silent = false;

    while ((optc = getopt_long(argc, argv, "s", longopts, NULL)) != -1)
    {
        switch (optc)
        {
            case 's':
                silent = true;
                break;

            default:
                usage(TTY_FAILURE);
        }
    }

    if (optind < argc)
    {
        fprintf(stderr, "extra operand");
        usage (TTY_FAILURE);
    }

    errno = ENOENT;

    if (silent)
        return isatty (STDIN_FILENO) ? EXIT_SUCCESS : TTY_STDIN_NOTTY;

    int status = EXIT_SUCCESS;
    char const *tty = ttyname(STDIN_FILENO);

    if (!tty)
    {
        tty = _("not a tty");
        status = TTY_STDIN_NOTTY;
    }

    puts(tty);
    return status;
}
