#include "../c_src_headers/kill_headers/kill_link.h"
#include "../c_src_headers/kill_headers/kill_upload.h"

#define OK 0

int core_kill_test()
{
    char *idlist[3] = { "99999r", "9999900", "54i12" };

    int fails = core_kill(11, 4, idlist);

    if (fails == 3)
        fprintf(stdout, "ok 1 - Invalid id's");
    else
        fprintf(stdout, "not ok 1 - Invalid id's");
    return OK;
}

// int get_kill_test()
// {
//     char *idlist[3] = { "99999r", "9999900", "54i12" };

//     if (*(get_kill())(11, 4, idlist)) == core_kill(11, 4, idlist))
//         fprintf(stdout, "ok 1 - Invalid id's");
//     else
//         fprintf(stdout, "not ok 1 - Invalid id's");
//     return OK;
// }

int main()
{
    core_kill_test();
    get_kill_test();
    return OK;
}