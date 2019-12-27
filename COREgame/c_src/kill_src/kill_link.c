#include "../../c_src_headers/kill_headers/kill_link.h"

// Sends signal (signum) to processes from (argv). Returns number of failures.
int core_kill (int signum, int argc, char *const *argv)
{
  int test = 0;
  int fails = 0;
  char const *arg = *argv;

  for (int i = 0; i < argc; i++)
  {
    char *endp = NULL;
    intmax_t n = strtoimax (arg, &endp, 10);
    pid_t pid = n;

    if (pid != n || arg == endp || *endp)
      {
        fprintf(stderr, "%s: invalid process id", arg);
        fails++;
      }
    else if (kill(pid, signum) != 0)
      {
        fprintf(stderr, "%s: error while killing", arg);
        fails++;
      }
    test++;
    printf("\n%d\n", test);
    arg = *(argv + i + 1);
  }
  return fails;
}