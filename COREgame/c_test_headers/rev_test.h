#ifndef _REV_TEST_H_
#define _REV_TEST_H_

// Return codes
#define TESTING_SUCCESS 0
#define TESTING_FAILURE 1


#define TESTS_AMOUNT 2

// Test result
#define PASSED 1
#define FAILED 0

#define REV_FILE 1  // to reverse the file (argc)


int32_t trivial_testing(int32_t *const _Index);
int32_t dll_testing(int32_t *const _Index);

#endif