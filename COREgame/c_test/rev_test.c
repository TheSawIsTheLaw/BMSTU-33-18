#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "../c_test_headers/rev_test.h"
#include "../c_src_headers/rev_headers/rev_upload.h"
#include "../c_src_headers/rev_headers/rev_link.h"



// Rev testing
int32_t trivial_testing(int32_t *const test_idx)
{
    int32_t code;

    if (!rev(REV_FILE, "rev_test.c"))
    {
        fprintf(stdout, "ok");
        code = PASSED;
    }
    else
    {
        fprintf(stdout, "not ok");
        code = FAILED;
    }

    fprintf(stdout, " %d\t", (*test_idx)++);
    fprintf(stdout, "trivial rev testing\n");

    return code;
}


// Dynamic linking testing (.so)
int32_t dll_testing(int32_t *const test_idx)
{
    int32_t code;
    fprot rev_ptr = get_rev();

    if (rev_ptr)
    {
        code = rev_ptr(REV_FILE, "rev_test.c");  // reverse rev_test.c file
        if (code)
        {
            fprintf(stdout, "ok");
            code = PASSED;
        }
        else
        {
            fprintf(stdout, "not ok");
            code = FAILED;
        }

    }
    else
    {
        fprintf(stdout, "not ok");
        code = FAILED;
    }

    fprintf(stdout, " %d\t", (*test_idx)++);
    fprintf(stdout, "dynamic linking\n");
    

    return code;
}


int main()
{
    int32_t code = 0;
    int32_t test_idx = 1, last_test_idx = TESTS_AMOUNT;

    fprintf(stdout, "%d..%d\n", test_idx, last_test_idx);

    // Trivial testing
    code += trivial_testing(&test_idx);
    
    // .so testing
    code += dll_testing(&test_idx);

    fprintf(stdout, "Testing finished\n");

    if (test_idx != TESTS_AMOUNT + 1)
    {
        return TESTING_FAILURE;
    }

    return TESTING_SUCCESS;
}
